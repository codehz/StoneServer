#pragma once

#include <atomic>
#include <memory>

namespace mcpe {

namespace detail {
class SharedPtrBase {

protected:
    struct RefCountBase {

        std::atomic_int count;
        std::atomic_int weakCount;

        RefCountBase() : count(1), weakCount(1) {}

        virtual ~RefCountBase() noexcept = default;

        virtual void dispose() noexcept = 0;

        virtual void destroy() noexcept { delete this; }

        virtual void* getDeleter(const std::type_info&) noexcept = 0;

        void addRefFromCopy() {
            count.fetch_add(1);
        }

        void release() noexcept  {
            if (count.fetch_add(-1) == 1) {
                dispose();
                if (weakCount.fetch_add(-1) == 1)
                    destroy();
            }
        }

    };

    template <typename T>
    struct DefaultRefCount : public RefCountBase {
        T t;

        DefaultRefCount(T t) : t(t) {}

        void dispose() noexcept override {
            delete t;
        }

        void* getDeleter(const std::type_info&) noexcept override {
            return nullptr;
        }

    };

    template <typename T, typename Deleter, typename Alloc>
    struct DeleterRefCount : public RefCountBase {
        using RebindedAlloc = typename Alloc::template rebind<DeleterRefCount>::other;

        Deleter deleter;
        Alloc alloc;
        T t;

        DeleterRefCount(Deleter deleter, Alloc alloc, T t) : deleter(deleter), alloc(alloc), t(t) {}

        void dispose() noexcept override {
            deleter(t);
        }

        void destroy() noexcept override {
            DeleterRefCount ra (alloc);
            this->~RefCount();
            std::allocator_traits<DeleterRefCount>::deallocate(ra, this, 1);
        }

        void* getDeleter(const std::type_info&) noexcept override {
            return nullptr; // We do not support RTTI
        }

    };

};
}

template<typename T>
class shared_ptr : public detail::SharedPtrBase {

    T *ptr;
    RefCountBase *refCount;

public:
    shared_ptr() : ptr(nullptr), refCount(nullptr) {}

    template <typename P>
    shared_ptr(P ptr) : ptr(ptr), refCount(new DefaultRefCount<P>(ptr)) {
    }

    ~shared_ptr() {
        refCount->release();
    }

    template <typename P, typename Deleter, typename Alloc = std::allocator<void>>
    shared_ptr(P ptr, Deleter deleter, Alloc alloc) : ptr(ptr) {
        using RefCount = DeleterRefCount<P, Deleter, Alloc>;
        typename RefCount::RebindedAlloc ra (alloc);
        refCount = std::allocator_traits<RefCount>::allocate(ra, sizeof(RefCount));
        new (refCount) RefCount(deleter, alloc, ptr);
    }

};

}