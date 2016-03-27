#ifndef SIMPPL_TYPE_WRAPPERS_H
#define SIMPPL_TYPE_WRAPPERS_H


namespace simppl
{
   
/**
 * integral constant wrapper
 */
template<int i>
struct int_
{
    typedef int value_type;
    static const int value = i;
};


/**
 * integral constant wrapper
 */
template<char c>
struct char_
{
    typedef char value_type;
    static const char value = c;
};


template<bool b>
struct bool_
{
   static const bool value = b;
};

typedef bool_<true> tTrueType;
typedef bool_<false> tFalseType;

}   // namespace simppl


#endif  // SIMPPL_TYPE_WRAPPERS_H