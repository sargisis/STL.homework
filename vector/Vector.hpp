#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <initializer_list>


template<typename T>
class Vector {
   private:
   T* m_ptr; 
   size_t _size; 
   size_t _capacity;

  
   public:
  
   Vector();
   ~Vector();
   Vector(std::initializer_list<T> initList);
   Vector(const T&);
   Vector(const Vector& );
   Vector(Vector&& );
   const Vector& operator=(const Vector&);
   const Vector& operator=(Vector&&);  
   const T& operator[](size_t) const  noexcept; 
   T& operator[](size_t);
    void push_back(const T&);
    void pop_back() const; 
    const T& front() const;  
    const T& back() const; 
    T& front(); 
    T& back();
    void recap()  noexcept;
    const T& at(size_t) const; 
    T& at(size_t);
    T* data(); 
    const T* data() const;
   constexpr bool empty() const;
   constexpr size_t Size() const; 
   constexpr size_t max_size() const; 
   constexpr size_t Capacity() const; 
    void insert(size_t , const T&);
    void erase(size_t);
    void resize(T , const T&);
    void clear() noexcept;
    void print() const;
    void _swap(const Vector&);

};

template<typename T, typename U>
bool operator==(const Vector<T>& lhv , const Vector<U>& rhv);

template<typename T, typename U>
bool operator!=(const Vector<T>& lhv, const Vector<U>& rhv);

template<typename T, typename U>
bool operator>(const Vector<T>& lhv, const Vector<U>& rhv);

template<typename T, typename U>
bool operator>=(const Vector<T>& lhv, const Vector<U>& rhv);

template<typename T, typename U>
bool operator<(const Vector<T>& lhv, const Vector<U>& rhv);

template<typename T, typename U>
bool operator<=(const Vector<T>& lhv, const Vector<U>& rhv);


#include "Vector.cpp"

#endif // VECTOR_HPP
