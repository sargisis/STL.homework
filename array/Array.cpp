#include "Array.h"

template<typename T, std::size_t N>
Array<T,N>::Array() : m_arr{nullptr} {}

template<typename T , std::size_t N>
Array<T,N>::Array(std::initializer_list<T> initList){
     if (initList.size() != size()) {
        throw std::runtime_error("Error");
    
    }

    const T* initPtr = initList.begin();
    for (size_t i = 0; i < N; ++i) {
        m_arr[i] = *initPtr;
        ++initPtr;
    }
}

template<typename T , std::size_t N>
Array<T, N>::~Array() {}

template<typename T , std::size_t N>
Array<T, N>::Array(const Array& rhv){
     for(size_t i = 0; i < N; ++i){
         m_arr[i] = rhv.m_arr[i];
     }
}

template<typename T, std::size_t N>
Array<T, N>::Array(Array&& rhv){
    for(size_t i = 0; i < N; ++i){
        m_arr[i] = std::move(rhv.m_arr[i]);
    }
}

template<typename T, std::size_t N>
const Array<T,N>& Array<T,N>::operator=(const Array& rhv){
        if (this != &rhv){
            for(size_t i = 0; i < N; ++i){
                m_arr[i] = rhv.m_arr[i];
            }
        }
        return *this; 
}

template<typename T, std::size_t N>
const Array<T,N>& Array<T,N>::operator=(Array&& rhv){
    if (this != &rhv){
       for(size_t i = 0; i < N; ++i){
         m_arr[i] = std::move(rhv.m_arr[i]);
       }
    }
    return *this; 
}

template<typename T, std::size_t N>
Array<T,N>::const_reference Array<T,N>::at(size_type index) const
{
      if (index >= size() || index < 0){
        throw std::runtime_error("error");
      }
      return m_arr[index];
}

template<typename T , std::size_t N>
Array<T,N>::reference Array<T,N>::at(size_type index){
    if (index >= size() || index < 0){
        throw std::runtime_error("error");
    }
    return m_arr[index];
}


template<typename T, std::size_t N>
Array<T,N>::const_reference Array<T,N>::operator[](size_type index) const{
        if (index >= size() || index < 0 ){
            throw std::runtime_error("Error");
        }
        return m_arr[index];
}

template<typename T, std::size_t N>
Array<T,N>::reference Array<T,N>::operator[](size_type index ){
    if (index >= size() || index < 0){
        throw std::runtime_error("Error");
    }
    return m_arr[index];
}

template<typename T, std::size_t N>
Array<T,N>::const_reference Array<T,N>::front() const {
    return m_arr[0];
}

template<typename T, std::size_t N>
Array<T,N>::reference Array<T,N>::front() {
    return m_arr[0];
}


template<typename T, std::size_t N>
Array<T,N>::const_reference Array<T,N>::back() const {
    return m_arr[N - 1];
}

template<typename T, std::size_t N>
Array<T,N>::reference Array<T,N>::back()  {
    return m_arr[N - 1];
}

template<typename T, std::size_t N>
Array<T,N>::const_pointer Array<T,N>::data() const {
     return m_arr;
}

template<typename T, std::size_t N>
Array<T,N>::pointer Array<T,N>::data()  {
     return m_arr;
}

template<typename T, std::size_t N>
constexpr bool Array<T,N>::empty() {
     return size() == 0;
}

template<typename T, std::size_t N>
constexpr Array<T,N>::size_type Array<T,N>::size() {
    return N;
}

template<typename T, std::size_t N>
constexpr Array<T,N>::size_type Array<T,N>::max_size() {
    return N;
}

template<typename T, std::size_t N>
void Array<T,N>::fill(const_reference val){
    for (size_t i = 0; i < N; ++i){
        m_arr[i] = val; 
    }
}

template<typename T, std::size_t N>
void Array<T,N>::print() const {
   for (size_t i = 0; i < N; ++i){
        std::cout << m_arr[i] << " " << std::endl; 
   }
}


template<typename T, typename U , std::size_t N >
bool operator==(const Array<T,N>& lhs , const Array<U,N>& rhs){
    return compare(lhs , rhs) == 0;
}

template<typename T, typename U, std::size_t N>
bool operator!=(const Array<T,N>& lhs , const Array<U,N>& rhs){
    return compare(lhs , rhs) != 0;
}

template<typename T, typename U , std::size_t N >
bool operator>(const Array<T,N>& lhs , const Array<U,N>& rhs){
    return compare(lhs , rhs) > 0;
}

template<typename T, typename U , std::size_t N >
bool operator>=(const Array<T,N>& lhs , const Array<U,N>& rhs){
    return compare(lhs , rhs) >= 0;
}

template<typename T, typename U , std::size_t N >
bool operator<(const Array<T,N>& lhs , const Array<U,N>& rhs){
    return compare(lhs , rhs) < 0;
}

template<typename T, typename U , std::size_t N >
bool operator<=(const Array<T,N>& lhs , const Array<U,N>& rhs){
    return compare(lhs , rhs) <= 0;
}