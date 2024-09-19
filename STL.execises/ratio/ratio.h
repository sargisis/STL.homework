#pragma once 

#include <cstdint>
#include <type_traits>

namespace rat 
{
    template <intmax_t N , intmax_t D>
    struct simplify;
    template <intmax_t N, intmax_t D = 1>
    class ratio {
    public:
        static constexpr intmax_t num = simplify<N, D>::num;
        static constexpr intmax_t den = simplify<N, D>::den;
        typedef ratio<num, den> type;
    };

    constexpr intmax_t gcd(intmax_t a , intmax_t b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

    template <intmax_t N, intmax_t D>
    struct simplify {
        static constexpr intmax_t g = gcd(N, D);
        static constexpr intmax_t num = N / g;
        static constexpr intmax_t den = D / g;
        typedef ratio<num, den> type;
    };

    template <class R1, class R2> 
    using ratio_add = typename simplify<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den>::type;
    
    template <class R1, class R2> 
    using ratio_subtract = typename simplify<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den>::type;
    
    template <class R1, class R2> 
    using ratio_multiply = typename simplify<R1::num * R2::num, R1::den * R2::den>::type;
    
    template <class R1, class R2> 
    using ratio_divide = typename simplify<R1::num * R2::den, R1::den * R2::num>::type;
    
    template <class R1, class R2> 
    struct ratio_equal : std::bool_constant<(R1::num == R2::num && R1::den == R2::den)> {};
    
    template <class R1, class R2> 
    struct ratio_not_equal : std::bool_constant<!ratio_equal<R1, R2>::value> {};
    
    template <class R1, class R2> 
    struct ratio_less : std::bool_constant<(R1::num * R2::den < R2::num * R1::den)> {};
    
    template <class R1, class R2> 
    struct ratio_less_equal : std::bool_constant<ratio_less<R1, R2>::value || ratio_equal<R1, R2>::value> {};
    
    template <class R1, class R2> 
    struct ratio_greater : std::bool_constant<ratio_less<R2, R1>::value> {};
    
    template <class R1, class R2> 
    struct ratio_greater_equal : std::bool_constant<ratio_greater<R1, R2>::value || ratio_equal<R1, R2>::value> {};

    typedef ratio<1, 1000000000000000> femto;  // 10^-15
    typedef ratio<1, 1000000000000> pico;     // 10^-12
    typedef ratio<1, 1000000000> nano;        // 10^-9
    typedef ratio<1, 1000000> micro;          // 10^-6
    typedef ratio<1, 1000> milli;             // 10^-3
    typedef ratio<1, 100> centi;              // 10^-2
    typedef ratio<1, 10> deci;                // 10^-1
    typedef ratio<10, 1> deca;                // 10^1
    typedef ratio<100, 1> hecto;              // 10^2
    typedef ratio<1000, 1> kilo;              // 10^3
    typedef ratio<1000000, 1> mega;           // 10^6
    typedef ratio<1000000000, 1> giga;        // 10^9
    typedef ratio<1000000000000, 1> tera;     // 10^12
    typedef ratio<1000000000000000, 1> peta;  // 10^15
    typedef ratio<1000000000000000000, 1> exa; // 10^18

}
