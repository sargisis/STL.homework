#pragma once 

#include "../Type_Traits/type_traits.h"

using namespace traits;
#include <iostream>


namespace conc {
    //         same_as              //
    template <typename T, typename U>
    concept same_as = is_same_v<T, U> or is_same_v<U,T>;
    //

    //         derived_from         //
    template <typename Derived , typename Base>
    concept derived_from = std::is_base_of_v<Base , Derived> 
    and std::is_convertible_v<const volatile Derived* , const volatile Base*>;
    //

    //         convertable_to       //  
    template <typename From , typename To>
    concept convertible_to = std::is_constructible_v<From, To> and
    requires {
        static_cast<To>(std::declval<From>());
    };
    //

    //        integral              //  
    template <typename T>
    concept integral = is_integral_v<T>;

    //

    //         signed_integral      //  
    template <typename T>
    concept signed_integral = is_integral_v<T> and is_signed_v<T>;
    //

    //         unsigned_integral      //  
    template <typename T>
    concept unsigned_integral = is_integral_v<T> and is_unsigned_v<T>;
    //

    //      floating_point          //  
    template <typename T>
    concept floating_point = is_floating_point_v<T>;
    //  

    //      destructable           //
    template <typename T>
    concept destructable = std::is_nothrow_destructible_v<T>;
    //

    //       default_initializable      //
    template <typename T>
    concept default_initializable = is_default_constructible_v<T> and requires {T{}; new T;};
    //  

    //          move_constructible      //  
    template <typename T>
    concept  move_constructible = is_move_constructible_v<T> and requires(T ob1 , T ob2) {
        ob1 = std::move(ob2);
    };

    //

    //          copy_constructible      //  
    template <typename T>
    concept copy_constructible  = is_copy_constructible_v<T> and requires(T ob1 , T ob2) {
        ob1 = ob2;
    };  
    //  

    //          moveable            //  
    template <typename T>
    concept moveable = std::is_object_v<T>
                       and move_constructible<T> 
                       and std::assignable_from<T&, T> 
                       and std::swappable<T>;
    //  


    //          copyable        //  
    template <typename T>
    concept copyable = std::is_object_v<T>
                       and std::copy_constructible<T>
                       and moveable<T> 
                       and std::assignable_from<T&, T&> 
                       and std::assignable_from<T&, const T&>
                       and std::assignable_from<T&, const T>;
    // 

    //         semiregular      //  
    template <typename T>
    concept semiregular = copyable<T>
                          and default_initializable<T>;
    //

    
                       




}   