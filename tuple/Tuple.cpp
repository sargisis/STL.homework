#ifndef __TUPLE_CPP__
#define __TUPLE_CPP__

#include "Tuple.hpp"


template<typename T, typename... Ts>
template <typename...Us>
requires(sizeof...(Us) == sizeof...(Ts) + 1)
Tuple<T, Ts...>::Tuple(const Tuple<Us...>& rhv) : val(rhv.val), rest(rhv.rest) {}

template<typename T, typename... Ts>
template<typename...Us>
requires(sizeof...(Us) == sizeof...(Ts) + 1)
Tuple<T, Ts...>::Tuple(Tuple<Us...>&& rhv) : val(std::move(rhv.val)), rest(std::move(rhv.rest)) {}

template<typename T, typename... Ts>
template<typename...Us>
requires(sizeof...(Us) == sizeof...(Ts) + 1)
const Tuple<T,Ts...>& Tuple<T, Ts...>::operator=(const Tuple<T,Ts...>& rhv) {
    val = rhv.val;
    rest = rhv.rest;
    return *this;
}

template<typename T, typename... Ts>
template<typename...Us>
requires(sizeof...(Us) == sizeof...(Ts) + 1)
const Tuple<T,Ts...>& Tuple<T, Ts...>::operator=(Tuple<T,Ts...>&& rhv) {
    val = std::move(rhv.val);
    rest = std::move(rhv.rest);
    return *this;
}

template<typename T, typename... Ts>
void Tuple<T, Ts...>::_swap(Tuple<T, Ts...>& ob) noexcept {
    std::swap(val, ob.val);
    rest._swap(ob.rest);
}

// Define member functions for the single-element Tuple specialization
template<typename T>
Tuple<T>::Tuple(const Tuple& rhv) : val(rhv.val) {}

template<typename T>
Tuple<T>::Tuple(Tuple&& rhv) : val(std::move(rhv.val)) {}

template<typename T>
const Tuple<T>& Tuple<T>::operator=(const Tuple& rhv) {
    val = rhv.val;
    return *this;
}

template<typename T>
const Tuple<T>& Tuple<T>::operator=(Tuple&& rhv) {
    val = std::move(rhv.val);
    return *this;
}

template<typename T>
void Tuple<T>::_swap(const Tuple& other) noexcept {
    std::swap(val, other.val); 
}

// Define comparison operators for tuples
template<typename...Ts, typename...Us>
bool operator==(const Tuple<Ts...>& lhv, const Tuple<Us...>& rhv) {
    return compare(lhv, rhv) == 0;
}

template<typename...Ts, typename...Us>
bool operator!=(const Tuple<Ts...>& lhv, const Tuple<Us...>& rhv) {
    return compare(lhv, rhv) != 0;
}

template<typename...Ts, typename...Us>
bool operator>(const Tuple<Ts...>& lhv, const Tuple<Us...>& rhv) {
    return compare(lhv, rhv) > 0;
}

template<typename...Ts, typename...Us>
bool operator>=(const Tuple<Ts...>& lhv, const Tuple<Us...>& rhv) {
    return compare(lhv, rhv) >= 0;
}

template<typename...Ts, typename...Us>
bool operator<(const Tuple<Ts...>& lhv, const Tuple<Us...>& rhv) {
    return compare(lhv, rhv) < 0;
}

template<typename...Ts, typename...Us>
bool operator<=(const Tuple<Ts...>& lhv, const Tuple<Us...>& rhv) {
    return compare(lhv, rhv) <= 0;
}

#endif // __TUPLE_CPP__
