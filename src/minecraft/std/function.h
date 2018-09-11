#pragma once

#include <functional>
#include <type_traits>

namespace mcpe {

template<typename T>
class function;

template<typename ReturnType, typename... ArgTypes>
class function<ReturnType(ArgTypes...)> {

    class AnyClass;

    union AnyValue
    {
        void* object;
        const void* objectConst;
        void (*function)();
        void (AnyClass::*memberFunction)();
    };

    AnyValue functor;


    enum class ManagerOperation
    {
        GetTypeInfo,
        GetFunctor,
        CloneFunctor,
        DestroyFunctor
    };

    typedef bool (*ManagerFunc)(AnyValue&, const AnyValue&, ManagerOperation);

    ManagerFunc manager;


    using Invoker = ReturnType (*)(const AnyValue&, ArgTypes...);

    Invoker invoker;


    void destroy() {
        if (manager != nullptr)
            manager(functor, functor, ManagerOperation::DestroyFunctor);
    }

public:

    function() : manager(nullptr) {}

    function(function const& func) {
        manager = nullptr;
        *this = func;
    }

    function(function&& func) {
        manager = nullptr;
        *this = std::move(func);
    }

    function(nullptr_t) : manager(nullptr) {
    }

    template<typename Functor>
    function(Functor func) {
        initFunctor(functor, std::move(func));
        manager = &managerFunc<Functor>;
        invoker = &invokerFunc<Functor>;
    }

    ~function() { destroy(); }

    function& operator=(function const& func) {
        destroy();
        manager = func.manager;
        if (func) {
            manager(functor, func.functor, ManagerOperation::CloneFunctor);
            invoker = func.invoker;
        }
        return *this;
    }

    function& operator=(function&& func) {
        destroy();
        functor = func.functor;
        manager = func.manager;
        invoker = func.invoker;
        func.functor.object = nullptr;
        func.manager = nullptr;
        func.invoker = nullptr;
        return *this;
    }

    explicit operator bool() const { return manager != nullptr; }

    ReturnType operator()(ArgTypes... args) const {
        if (manager == nullptr)
            throw std::bad_function_call();
        return invoker(functor, std::forward<ArgTypes>(args)...);
    }

private:
    template <typename Functor>
    static constexpr bool isFunctorStoredLocally() {
        // if the size of the functor is smaller than the size of the AnyValue, it'll be stored directly
        return sizeof(Functor) <= sizeof(AnyValue);
    }

    template <typename Functor>
    static Functor* getFunctorPointer(const AnyValue& src) {
        return isFunctorStoredLocally<Functor>() ? (Functor*) (void*) &src : (Functor*) src.object;
    }

    template <typename Functor>
    static ReturnType initFunctor(AnyValue& functor, Functor&& val) {
        if (!isFunctorStoredLocally<Functor>())
            functor.object = new Functor(std::move(val));
        else
            new(getFunctorPointer<Functor>(functor)) Functor(std::move(val));
    }

    template <typename Functor>
    static ReturnType invokerFunc(const AnyValue& functor, ArgTypes... args) {
        return (*getFunctorPointer<Functor>(functor))(std::forward<ArgTypes>(args)...);
    }

    template <typename Functor>
    static bool managerFunc(AnyValue& dest, const AnyValue& src, ManagerOperation op) {
        switch (op) {
            /*
#if __cpp_rtti
            case ManagerOperation::GetTypeInfo:
                (const type_info*) dest.object = &type_id(Functor);
                break;
#endif
                */
            case ManagerOperation::GetFunctor:
                (Functor*&) dest.object = getFunctorPointer<Functor>(src);
                break;
            case ManagerOperation::CloneFunctor:
                if (!isFunctorStoredLocally<Functor>())
                    dest.object = new Functor(*getFunctorPointer<Functor>(src));
                else
                    new (getFunctorPointer<Functor>(dest)) Functor(*getFunctorPointer<Functor>(src));
                break;
            case ManagerOperation::DestroyFunctor:
                if (!isFunctorStoredLocally<Functor>())
                    delete (Functor*) dest.object;
                else
                    getFunctorPointer<Functor>(dest)->~Functor();
                break;
        }
        return false;
    }

};

}
