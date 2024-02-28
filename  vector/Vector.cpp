#ifndef VECTOR_CPP
#define VECTOR_CPP
#include "Vector.hpp"

template<typename T>
Vector<T>::Vector() : m_ptr(nullptr) , _size(0) , _capacity(0) {}

template<typename T>
Vector<T>::~Vector() { clear();}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> initList)
    : _size(initList.size()), _capacity(initList.size()), m_ptr(new T[initList.size()]) {
    std::copy(initList.begin(), initList.end(), m_ptr);
}

template<typename T>
Vector<T>::Vector(const T& val ) : _size(val) , _capacity(val) , m_ptr(new T[val]) {}

template<typename T>
Vector<T>::Vector(const Vector& rhv) : _size(rhv._size) , _capacity(rhv._capacity)
{
    m_ptr = new T[_capacity];
    for (size_t i = 0; i < _size; ++i){
        m_ptr[i] = rhv.m_ptr[i];
    }
}

template<typename T>
Vector<T>::Vector(Vector&& rhv) : _size(std::move(rhv._size)) , _capacity(std::move(rhv._capacity)) , m_ptr(std::move(rhv.m_ptr)) {
    rhv._size = 0; 
    rhv._capacity = 0;
    rhv.m_ptr = nullptr; 
}

template<typename T>
const Vector<T>& Vector<T>::operator=(const Vector& rhv) {
    _size = rhv._size;
    _capacity = rhv._capacity;
    m_ptr = rhv.m_ptr;
    return *this; 
}

template<typename T>
const Vector<T>& Vector<T>::operator=(Vector&& rhv) {
    _size = std::move(rhv._size);
    _capacity = std::move(rhv._capacity);
    m_ptr = std::move(rhv.m_ptr);

    _size = 0; 
    _capacity = 0; 
    m_ptr = nullptr; 
    
    return *this; 
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const noexcept {
    if (index >= _size || index < 0 ){
        throw std::out_of_range("Index of bounds");
    }
    return m_ptr[index];
}

template<typename T>
T& Vector<T>::operator[](size_t index)  {
    if (index >= _size || index < 0 ){
        throw std::out_of_range("Index of bounds");
    }
    return m_ptr[index];
}

template<typename T>
void Vector<T>::push_back(const T& val){
    recap();
    m_ptr[_size] = val; 
    ++_size;
}

template<typename T>
void Vector<T>::pop_back() const {
    if (_size >  0){
        --_size;
    }
}

template<typename T>
const T& Vector<T>::front() const {
    return m_ptr[0];
}

template<typename T>
 T& Vector<T>::front() {
    return m_ptr[0];
}

template<typename T>
const T& Vector<T>::back() const {
    return m_ptr[_size - 1];
}

template<typename T>
T& Vector<T>::back() {
    return m_ptr[_size - 1];
}

template<typename T>
void Vector<T>::recap()  noexcept {
    if (_size == _capacity){
        _capacity*= 2; 

        T* tmp = new T[_capacity];
        for (size_t i = 0; i < _size; ++i){
            tmp[i] = m_ptr[i]; 

        }
        delete[] m_ptr;
        m_ptr = tmp;
        tmp = nullptr; 
    }
}

template<typename T>
const T& Vector<T>::at(size_t index) const {
    if (index >= _size || index < 0){
        throw std::out_of_range("Index of bounds");
    }  
    return m_ptr[index];
}

template<typename T>
 T& Vector<T>::at(size_t index)  {
    if (index >= _size || index < 0){
        throw std::out_of_range("Index of bounds");
    }  
    return m_ptr[index];
}


template<typename T>
constexpr bool Vector<T>::empty() const {
    return _size == 0;
}

template<typename T>
constexpr size_t Vector<T>::Size() const {
    return _size; 
}

template<typename T>
constexpr size_t Vector<T>::max_size() const {
    return _size; 
}

template<typename T>
constexpr size_t Vector<T>::Capacity() const {
    return _capacity; 
}

template<typename T>
const T* Vector<T>::data() const {
    return m_ptr;
}

template<typename T>
 T* Vector<T>::data() {
    return m_ptr;
}

template<typename T>
void Vector<T>::clear() noexcept {
    _size = 0; 
    _capacity = 0; 
    delete[] m_ptr;
    m_ptr = nullptr; 
}


template<typename T>
void Vector<T>::insert(size_t index , const T& val){
    if (index >= _size || index < 0){
        throw std::out_of_range("index of bounds");
    }
     recap();
     for (size_t i = _size; i >= index; --i){
        m_ptr[i] = m_ptr[i - 1];
     }
     m_ptr[index] = val; 
     ++_size; 
}

template<typename T>
void Vector<T>::erase(size_t index ) {
    for (size_t i = index; i < _size - 1; ++i){
        m_ptr[i] = m_ptr[i + 1];
    }
    --_size; 
}

template<typename T>
void Vector<T>::resize(T newsize , const T& val ){
    if (newsize < _size) {
        _size = newsize;   
    }else if (newsize > _size){
        if (newsize > _capacity){
            _capacity = newsize * 2; 
        
         T* tmp = new T[_capacity];
         for (size_t i = 0; i < _size; ++i){
            tmp[i] = m_ptr[i];
         }
          delete[] m_ptr;
          m_ptr = tmp; 
          tmp = nullptr;
        }
       for (size_t i = _size; i < newsize; ++i){
          m_ptr[i] = val; 
       }
       _size = newsize;
    }

}

template<typename T , typename U>
bool operator==(const Vector<T>& lhv , const Vector<U>& rhv) {
    return compare(lhv , rhv) == 0;
}
template<typename T , typename U>
bool operator!=(const Vector<T>& lhv , const Vector<U>& rhv) {
    return compare(lhv , rhv) != 0;
}
template<typename T , typename U>
bool operator>=(const Vector<T>& lhv , const Vector<U>& rhv) {
    return compare(lhv , rhv) >= 0;
}
template<typename T , typename U>
bool operator>(const Vector<T>& lhv , const Vector<U>& rhv) {
    return compare(lhv , rhv) > 0;
}
template<typename T , typename U>
bool operator<=(const Vector<T>& lhv , const Vector<U>& rhv) {
    return compare(lhv , rhv) < 0;
}
template<typename T , typename U>
bool operator<(const Vector<T>& lhv , const Vector<U>& rhv) {
    return compare(lhv , rhv) == 0;
}

template<typename T>
void Vector<T>::print() const {
    for (size_t i = 0; i < _size; ++i){
         std::cout << m_ptr[i] << " " << std::endl; 
    }
}


template<typename T>
void Vector<T>::_swap(const Vector& ob){
    for(size_t i = 0; i < _size; ++i){
        for (size_t j = 0; j < _size; ++j){
            std::swap(m_ptr[i] , ob.m_ptr[j]);
        }
    }
}
#endif // VECTOR_HPP