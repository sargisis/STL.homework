#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <iostream>
#include <stdexcept>
#include <initializer_list>

template<typename T, std::size_t N>
class Array {
private:
    T m_arr[N];
public: // member_types
    using value_type = T; 
    using pointer = value_type*; 
    using size_type = std::size_t; 
    using reference = value_type&; 
    using const_reference = const value_type&; 
    using const_pointer = const value_type*;
public: // constructors and assignments 
    Array();
    Array(std::initializer_list<T>);
    ~Array();
    Array(const Array&);
    Array(Array&&);
    const Array& operator=(const Array&); 
    const Array& operator=(Array&&);
public: // Element access
    const_reference at(size_type) const; 
    reference at(size_type); 
    const_reference operator[](size_type) const; 
    reference operator[](size_type); 
    const_reference front() const; 
    reference front(); 
    const_reference back() const; 
    reference back(); 
    const_pointer data() const; 
    pointer data(); 
public: // Capacity 
    constexpr bool empty();
    constexpr size_type size();
    constexpr size_type max_size();
public: // Operations 
    void fill(const_reference); 
    void print() const; 
};

// End methods in Array 

template<typename T, typename U , std::size_t N >
bool operator==(const Array<T , N>& lhv , const Array<U, N>& rhv);

template<typename T, typename U , std::size_t N >
bool operator!=(const Array<T,N>& lhv, const Array<U,N>& rhv);

template<typename T, typename U , std::size_t N >
bool operator>(const Array<T,N>& lhv, const Array<U,N>& rhv);

template<typename T, typename U , std::size_t N >
bool operator>=(const Array<T,N>& lhv, const Array<U,N>& rhv);

template<typename T, typename U , std::size_t N >
bool operator<(const Array<T,N>& lhv, const Array<U,N>& rhv);

template<typename T, typename U , std::size_t N >
bool operator<=(const Array<T,N>& lhv, const Array<U,N>& rhv);


#include "Array.cpp"

#endif // __ARRAY_HPP__
