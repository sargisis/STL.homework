#pragma once

#include <iostream>
#include <type_traits>

namespace traits
{   
    //      is_void     // 
    template <typename T>
    struct is_void : std::is_same<void, std::remove_cv_t<T>>
    {
    };

    template<class T>
    constexpr bool is_void_v = is_void<T>::value; 
    //

    //      is_null_pointer     //  
    template <typename T>
    struct is_null_pointer : std::is_same<std::nullptr_t , std::remove_cv_t<T>> 
    {  
    };

    template<class T>
    constexpr bool is_null_pointer_v = is_null_pointer<T>::value;
    //  

    //       is_integral    //
    template <class T>
    struct is_integral : std::bool_constant < requires(T t, T *p, void (*f)(T))
    {
        reinterpret_cast<T>(t);
        f(0);
        p += t;
    } > {};
    //

    //      is_floating_point       //
    template<typename T>
    struct is_floating_point : std::is_same<float , std::remove_cv_t<T>> ,
                               std::is_same<double, std::remove_cv_t<T>> ,
                               std::is_same<long double , std::remove_cv_t<T>>
    {
    };

    template<class T>
    constexpr bool is_floating_point_v = is_floating_point<T>::value; 

    //          is_array        // 
    template <typename T>
    struct is_array : std::false_type {};

    template <typename T>
    struct is_array<T[]> : std::true_type {};

    template <typename T, size_t N>
    struct is_array<T[N]> : std::true_type {};

    template <class T>
    constexpr bool is_array_v = is_array<T>::value; 


    //      is_function      // 
    template<typename T>
    struct is_function : std::false_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...)> : std::true_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...) const > : std::true_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...) volatile > : std::true_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...) const volatile > : std::true_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...) &> : std::true_type {};
   
    template<typename T, typename... Args>
    struct is_function<T(Args...) const &> : std::true_type {};
   
    template<typename T, typename... Args>
    struct is_function<T(Args...) volatile &> : std::true_type {};
   
    template<typename T, typename... Args>
    struct is_function<T(Args...) const volatile&> : std::true_type {};
    
    template<typename T, typename... Args>
    struct is_function<T(Args...) &&> : std::true_type {};
    
    template<typename T, typename... Args>
    struct is_function<T(Args...) const&&> : std::true_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...) volatile&&> : std::true_type {};
   
    template<typename T, typename... Args>
    struct is_function<T(Args...) const volatile&&> : std::true_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...) noexcept > : std::true_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...) const noexcept > : std::true_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...) volatile noexcept > : std::true_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...) const volatile noexcept > : std::true_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...) & noexcept > : std::true_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...) && noexcept > : std::true_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...) const& noexcept > : std::true_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...) volatile& noexcept > : std::true_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...) const volatile& noexcept > : std::true_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...) const&& noexcept > : std::true_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...) volatile&& noexcept > : std::true_type {};

    template<typename T, typename... Args>
    struct is_function<T(Args...) const volatile&& noexcept > : std::true_type {};

    template<class T>
    constexpr bool is_function_v = is_function<T>::value; 
    //  

    //      is_pointer      //
    template <typename T>
    struct is_pointer : std::false_type {};

    template <typename T>
    struct is_pointer<T*> : std::true_type {};

    template <class T>
    constexpr bool is_pointer_v = is_pointer<T>::value; 
    //

    //         is_lvalue_referance      //
    template <typename T>
    struct is_lvalue_reference : std::false_type {};

    template <typename T>
    struct is_lvalue_reference<T&> : std::true_type {};

    template <class T>
    constexpr bool is_lvalue_reference_v = is_lvalue_reference<T>::value; 

    //  


    //         is_rvalue_referance      //
    template <typename T>
    struct is_rvalue_reference : std::false_type {};

    template <typename T>
    struct is_rvalue_reference<T&&> : std::true_type {};

    template <class T>
    constexpr bool is_rvalue_reference_v = is_rvalue_reference<T>::value; 

    //  


    //      is_member_object_pointer    //
    template <typename T>
    struct is_member_object_pointer : std::integral_constant<bool , 
                                      std::is_member_pointer_v<T> and
                                     !std::is_member_function_pointer_v<T>>
    {};

    template <class T>
    constexpr bool is_member_object_pointer_v = is_member_object_pointer<T>::value; 
    //  

    //      is_member_function_pointer     //
    template <typename T>
    struct is_member_function_pointer : std::false_type {};

    template <typename T, typename U>
    struct is_member_function_pointer<T U::*> : is_function<T> {};

    template <class T>
    constexpr bool is_member_function_pointer_v = is_member_function_pointer<T>::value;
    //  

    //     is_fundamental       //  
    template <typename T>
    struct is_fundamental  : std::integral_constant<bool,   
                             std::is_arithmetic_v<T> or
                             is_void_v<T> or
                             std::is_same_v<std::nullptr_t , std::remove_cv_t<T>>>
    {};   

    template <class T>
    constexpr bool is_fundamental_v = is_fundamental<T>::value; 
    //  

    //  is_arithmetic //  
    template <typename T>
    struct is_arithmetic : std::integral_constant<bool ,
                           is_floating_point_v<T>>
    {};

    template <class T> 
    constexpr bool is_arithmetic_v = is_arithmetic<T>::value;
    //  

    //  is_object //
    template <typename T>
    struct is_object : std::integral_constant<bool,
                       is_array_v<T> or
                       std::is_enum_v<T> or
                       std::is_class_v<T> >
    {};

    template <class T>
    constexpr bool is_object_v = is_object<T>::value; 
    // 

    //     is_reference     //
    template <typename T>
    struct is_reference : std::false_type {};

    template <typename T>
    struct is_reference<T&> : std::true_type {};

    template <typename T>
    struct is_reference<T&&> : std::true_type {};

    template <class T>
    constexpr bool is_reference_v = is_reference<T>::value; 

    // 

    //  is_member_pointer // 
    template <typename T>
    struct is_member_pointer : std::false_type {};

    template <typename T, typename U>
    struct is_member_pointer<T U::*> : std::true_type {};

    template <class T>
    constexpr bool is_member_pointer_v = is_member_pointer<T>::value; 
    //


    //  is_const // 
    template <typename T>
    struct is_const : std::false_type {};

    template <typename T>
    struct is_const<const T> : std::true_type {};

    template <class T>
    constexpr bool is_const_v = is_const<T>::value; 
    //  

     //  is_volatile // 
    template <typename T>
    struct is_volatile : std::false_type {};

    template <typename T>
    struct is_volatile<volatile T> : std::true_type {};

    template <class T>
    constexpr bool is_volatile_v = is_volatile<T>::value; 
    //  


    //      is_signed       //

    template <typename T>
    struct is_signed : std::integral_constant<bool,
                       std::is_signed_v<T>
                       >
    {};

    template <class T>
    constexpr bool is_signed_v = is_signed<T>::value; 
    //  

    //     is_unsigned      //

    template <typename T>
    struct is_unsigned : std::integral_constant<bool , 
                         std::is_unsigned_v<T>
                         >
    {};

    template <class T>
    constexpr bool is_unsigned_v = is_unsigned<T>::value; 

    //  

    //      is_same         //
    template <typename T , typename U>
    struct is_same : std::false_type {};

    template <typename T>
    struct is_same<T,T> : std::true_type {};

    template <class T, class U>
    constexpr bool is_same_v = is_same<T,U>::value; 
    //  


    //      remove_cv       //  
    template <typename T>
    struct remove_cv { typedef T type; };

    template <typename T>
    struct remove_cv<const T> {typedef T type;};

    template <typename T>
    struct remove_cv<volatile T> {typedef T type;};

    template <typename T>
    struct remove_cv<const volatile T> {typedef T type;};

    //      remove_const        //
    template <typename T>
    struct remove_const {typedef T type;};

    template <typename T>
    struct remove_const<const T> {typedef T type;};

    //      remove_volatile     //
    template <typename T>
    struct remove_volatile {typedef T type;};

    template <typename T>
    struct remove_volatile<volatile T> {typedef T type;};
    //

    template <class T>
    using remove_cv_t = typename remove_cv<T>::type;

    template <class T>
    using remove_const_t = typename remove_const<T>::type;

    template <class T>
    using remove_volatile_t = typename remove_volatile<T>::type; 
    //

    //          add_cv           //

    template <typename T>
    struct add_cv {typedef const volatile T type;};


    //         add_const        //

    template <typename T>
    struct add_const {typedef const T type;};  

    //         add_volatile     //

    template <typename T>
    struct add_volatile {typedef volatile T type;};

    template <class T>
    using add_cv_t = typename add_cv<T>::type; 

    template <class T>
    using add_const_t = typename add_const<T>::type; 

    template <class T>
    using add_volatile_t = typename add_volatile<T>::type; 
    //

    //      remove_reference    //
    template <typename T>
    struct remove_reference {typedef T type;};

    template <typename T>
    struct remove_reference<T&> {typedef T type;};

    template <typename T>
    struct remove_reference<T&&> {typedef T type;};

    template <class T>
    using remove_reference_t = typename remove_reference<T>::type; 

    //  

    //   add_lvalue_reference / add_rvalue_reference //  
    // template <typename T>
    // struct add_lvalue_reference {typedef T type;};

    // template <typename T>
    // struct add_lvalue_reference<T&> {typedef T& type;};

    // template <typename T>
    // struct add_rvalue_reference {typedef T type;};

    // template <typename T>
    // struct add_rvalue_reference<T&&> {typedef T&& type;};

    // template <class T>
    // using add_lvalue_reference_t = add_lvalue_reference<T>::type; 

    // template <class T>
    // using add_rvalue_reference_t = add_rvalue_reference<T>::type; 
    // 


    //  does not work

    //      remove_pointer      //

    template <typename T>
    struct remove_pointer {typedef T type; };

    template <typename T>
    struct remove_pointer<T*> {typedef T type;};

    template <typename T>
    struct remove_pointer<const T*> {typedef T type;};

    template <typename T>
    struct remove_pointer<volatile T*> {typedef T type;};

    template <typename T>
    struct remove_pointer<const volatile T*> {typedef T type;};


    template <typename T>
    using remove_pointer_t = remove_pointer<T>::type; 
    //  

    //         enable_if            //  

    template <bool B,typename T>
    struct enable_if {};

    template <typename T>
    struct enable_if<true , T>  {typedef T type;};

    template <bool B , typename T>
    using enable_if_t = typename enable_if<B,T>::type; 
    //

}
