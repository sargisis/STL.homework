#ifndef __TUPLE_HPP__
#define __TUPLE_HPP__

#include <iostream>
#include <utility>
#include <initializer_list>

template<typename T, typename... Ts>
struct Tuple {
    private:
    T val;                     
    Tuple<Ts...> rest;         
    
    public:
    // Getter for the value
    const T& getVal() const {
        return val; 
    }
    // Getter for the rest of the tuple
    const Tuple<Ts...>& getRest() const {
        return rest;
    }

    // Default constructor
    Tuple() = default;
    
    // Constructor with parameters
    template<typename U, typename... Us>
    requires(sizeof...(Us) == sizeof...(Ts))
    Tuple(const U& ob, const Us&... args) : val(ob), rest(args...) {}

    // Copy constructor
    template <typename...Us>
    requires(sizeof...(Us) == sizeof...(Ts) + 1)
    Tuple(const Tuple<Us...>& rhv);

    // Move constructor
    template<typename...Us>
    requires(sizeof...(Us) == sizeof...(Ts) + 1)
    Tuple(Tuple<Us...>&& rhv);

    // Copy assignment operator
    template<typename...Us>
    requires(sizeof...(Us) == sizeof...(Ts) + 1)
    const Tuple<T,Ts...>& operator=(const Tuple<T,Ts...>& rhv);

    // Move assignment operator
    template<typename...Us>
    requires(sizeof...(Us) == sizeof...(Ts) + 1)
    const Tuple<T,Ts...>& operator=(Tuple<T,Ts...>&& rhv);

    // Swaps elements of two tuples
    void _swap(Tuple<T, Ts...>& ob) noexcept;
};



// Specialization for tuple with a single element
template<typename T>
struct Tuple<T> {
    private:
    T val;  
    
    public:
    // Default constructor
    Tuple() = default;

    // Constructor with parameter
    Tuple(const T& value ) : val(value) {}
    
    // Copy constructor
    Tuple(const Tuple& rhv);

    // Move constructor
    Tuple(Tuple&& rhv);

    // Copy assignment operator
    const Tuple& operator=(const Tuple& rhv);

    // Move assignment operator
    const Tuple& operator=(Tuple&& rhv);

    // Swaps the single elements of two tuples
    void _swap(const Tuple& other ) noexcept;
};

// Comparison operators for tuples
template<typename...Ts, typename...Us>
bool operator==(const Tuple<Ts...>& lhv, const Tuple<Us...>& rhv);

template<typename...Ts, typename...Us>
bool operator!=(const Tuple<Ts...>& lhv, const Tuple<Us...>& rhv);

template<typename...Ts, typename...Us>
bool operator>(const Tuple<Ts...>& lhv, const Tuple<Us...>& rhv);

template<typename...Ts, typename...Us>
bool operator>=(const Tuple<Ts...>& lhv, const Tuple<Us...>& rhv);

template<typename...Ts, typename...Us>
bool operator<(const Tuple<Ts...>& lhv, const Tuple<Us...>& rhv);

template<typename...Ts, typename...Us>
bool operator<=(const Tuple<Ts...>& lhv, const Tuple<Us...>& rhv);


template<typename T, typename...Ts>
struct std::tuple_element<0, std::tuple<T, Ts...>> {
    using type = T;
};

template<size_t I, typename T, typename...Ts>
struct std::tuple_element<I, std::tuple<T, Ts...>> : std::tuple_element<I - 1, Ts...> {};



#include "Tuple.cpp"

#endif // __TUPLE_HPP__
