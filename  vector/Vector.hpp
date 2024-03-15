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
   using value_type = T;
   using referance = value_type&;
   using size_type = std::size_t;
   using const_referance = const value_type&;
   using pointer = value_type*;
   using const_pointer = const value_type*;
  
   public:
   
   Vector();
   
   ~Vector();
   
   Vector(std::initializer_list<T> initList);
   
   Vector(const_referance);
   
   Vector(const Vector& );
   
   Vector(Vector&& );
   
   const Vector& operator=(const Vector&);
   
   const Vector& operator=(Vector&&);  
   
   const_referance operator[](size_type) const  noexcept; 
   
  referance operator[](size_type);
    
    void push_back(const_referance);
    
    void pop_back(); 
    
    const_referance front() const;  
    
    const_referance back() const; 
    
   referance front(); 
    
   referance back();
   
    void recap()  noexcept;
    
    const_referance at(size_type) const;

    referance at(size_type);
    
    pointer data(); 
   
    const_pointer data() const;
   
   constexpr bool empty() const;
   
   constexpr size_t Size() const; 
   
   constexpr size_t max_size() const; 
   
   constexpr size_t Capacity() const; 
   
    void insert(size_type , const_referance);
   
    void erase(size_type);
   
    void resize(value_type , const_referance);
   
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