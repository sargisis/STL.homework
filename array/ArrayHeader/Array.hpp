#ifndef ARRAY_HPP
#define ARRAY_HPP
#include "Array.h"


namespace g3 {

  template<typename T, std::size_t N>
  array<T,N>::array(std::initializer_list<T> ilist){
    if (ilist.size() != size()) {
        throw std::runtime_error("Error");
    }

    const_pointer initPtr = ilist.begin();
    for (size_t i = 0; i < N; ++i) {
        m_arr[i] = *initPtr;
        ++initPtr;
    }
  }
  template<typename T, std::size_t N>
  constexpr void array<T, N>::fill(const_reference value) noexcept {
    for (size_t i = 0; i < N; ++i) {
         this->m_arr[i] = value;
    }
  } 
    
  template<typename T, std::size_t N>
  constexpr void array<T,N>::swap(array& other) noexcept(std::is_nothrow_swappable_v<T>)
  {
    std::swap(this->m_arr , other.m_arr);
  }

  template<typename T, std::size_t N>
  [[nodiscard]] constexpr bool array<T,N>::empty() const noexcept
   {
        return N == 0;     
   }
   
  template<typename T, std::size_t N>
  constexpr std::size_t array<T,N>::size() const noexcept
  {
    return N; 
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::size_type array<T,N>::max_size() const noexcept 
  {
    return std::numeric_limits<std::size_t>::max() / sizeof(T);
  } 

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::reference array<T,N>::operator[](std::size_t index) 
  {
    return this->m_arr[index];
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::const_reference array<T,N>::operator[](std::size_t index) const 
  {
    return this->m_arr[index];
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::reference array<T,N>::at(std::size_t n) 
  {
      return this->m_arr[n];
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::const_reference array<T,N>::at(std::size_t n) const
  {
      return this->m_arr[n];
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::reference array<T,N>::front() 
  {
      return this->m_arr[0];
  }
  
  template<typename T, std::size_t N>
  constexpr typename array<T,N>::const_reference array<T,N>::front() const 
  {
      return this->m_arr[0];
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::reference array<T,N>::back() 
  {
      return this->m_arr[N - 1];
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::const_reference array<T,N>::back() const
  {
      return this->m_arr[N - 1];
  }
  
  template<typename T, std::size_t N>
  constexpr typename array<T,N>::pointer array<T,N>::data() noexcept
  {
      return this->m_arr;
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::const_pointer array<T,N>::data() const noexcept
  {
      return this->m_arr;
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::iterator array<T,N>::begin()  noexcept {
        return iterator(m_arr);
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::const_iterator array<T,N>::begin() const noexcept {
        return  const_iterator(m_arr); 
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::iterator array<T,N>::end()  noexcept {
        return iterator(m_arr + N);
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::const_iterator array<T,N>::end() const noexcept {
        return  const_iterator(m_arr + N); 
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::const_iterator array<T,N>::cbegin() const noexcept {
        return  const_iterator(m_arr); 
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::const_iterator array<T,N>::cend() const noexcept {
        return  const_iterator(m_arr + N); 
  }

  template<typename T, std::size_t N>
  constexpr typename array<T, N>::reverse_iterator array<T, N>::rbegin() noexcept {
    return reverse_iterator(m_arr + N - 1);
  }


  template<typename T, std::size_t N>
  constexpr typename array<T,N>::const_reverse_iterator array<T,N>::rbegin() const noexcept {
        return const_reverse_iterator(m_arr - 1);
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::const_reverse_iterator array<T,N>::crbegin() const noexcept {
        return const_reverse_iterator(m_arr + N - 1);
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::reverse_iterator array<T,N>::rend()  noexcept {
        return reverse_iterator(m_arr - 1); 
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::const_reverse_iterator array<T,N>::rend() const noexcept {
        return  const_reverse_iterator(m_arr - 1); 
  }

  template<typename T, std::size_t N>
  constexpr typename array<T,N>::const_reverse_iterator array<T,N>::crend() const noexcept {
        return  const_reverse_iterator(m_arr - 1); 
  }
 
  // start Iterators // 
  template<typename T, std::size_t N>
  g3::array<T,N>::const_iterator::const_iterator(const_pointer ptr)
    : ptr{ptr}
  {}

  template<typename T, std::size_t N>
  typename array<T,N>::const_iterator array<T,N>::const_iterator::operator+(size_type n) const 
  {
    return const_iterator(ptr + n);
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_iterator array<T,N>::const_iterator::operator-(size_type n) const 
  {
      return const_iterator(ptr - n);
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_iterator& array<T,N>::const_iterator::operator++()
  {
      ++ptr; 
      return *this; 
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_iterator array<T,N>::const_iterator::operator++(int) 
  {
      const_iterator tmp = *this; 
      ++(*this);
      return tmp; 
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_iterator& array<T,N>::const_iterator::operator--() 
  {
      --ptr; 
      return *this; 
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_iterator array<T,N>::const_iterator::operator--(int) 
  {
      const_iterator tmp = *this; 
      --(*this);
      return tmp; 
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_iterator& array<T,N>::const_iterator::operator+=(difference_type offset) 
  {
      ptr += offset;
      return *this; 
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_iterator& array<T,N>::const_iterator::operator-=(difference_type offset) 
  {
      ptr -= offset;
      return *this; 
  }
  
  template<typename T, std::size_t N>
  typename array<T,N>::const_iterator::const_reference array<T,N>::const_iterator::operator*() const 
  {
      return *ptr; 
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_iterator::const_pointer array<T,N>::const_iterator::operator->() const 
  {
      return ptr; 
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_iterator::const_reference array<T,N>::const_iterator::operator[](size_type index) const 
  {
      return ptr[index];
  }

  template<typename T, std::size_t N>
  bool array<T,N>::const_iterator::operator==(const const_iterator& other) const 
  {
    return ptr == other.ptr; 
  }

  template<typename T, std::size_t N>
  int array<T,N>::const_iterator::operator<=>(const const_iterator& other) const 
  {
      if (ptr < other.ptr) {
          return -1; 
      }
      else if (ptr > other.ptr){ 
          return 1; 
      }

      return 0; 
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_iterator array<T,N>::const_iterator::operator+(difference_type offset) 
  {
    return const_iterator(ptr + offset);
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_iterator array<T,N>::const_iterator::operator-(difference_type offset) 
  {
    return const_iterator(ptr - offset);    
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_iterator::difference_type array<T,N>::const_iterator::operator-(const const_iterator& other)
  {
    return const_iterator(ptr - other.ptr);
  }
  
  template<typename T, std::size_t N>
  array<T,N>::iterator::iterator(pointer ptr)
    : const_iterator(ptr)
  {}
  
  template<typename T, std::size_t N>
  typename array<T,N>::iterator array<T,N>::iterator::operator+(size_type n) const 
  {
    return iterator(this->ptr + n);
  }

  template<typename T, std::size_t N>
  typename array<T,N>::iterator array<T,N>::iterator::operator-(size_type n) const 
  {
      return iterator(this->ptr - n);
  }

  template<typename T, std::size_t N>
  typename array<T,N>::iterator::reference array<T,N>::iterator::operator*() {
      return *(this->ptr);

  }

  template<typename T, std::size_t N>
  array<T,N>::const_reverse_iterator::const_reverse_iterator(pointer ptr)
    : ptr{ptr}
  {}

  template<typename T, std::size_t N>
  typename array<T,N>::const_reverse_iterator array<T,N>::const_reverse_iterator::operator+(difference_type offset) const
  {
      return const_reverse_iterator(ptr - offset);
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_reverse_iterator array<T,N>::const_reverse_iterator::operator-(difference_type offset) const
  {
      return const_reverse_iterator(ptr + offset);
  }
  
  template<typename T, std::size_t N>
  typename array<T,N>::const_reverse_iterator& array<T,N>::const_reverse_iterator::operator++()
  {
    this->ptr--;
    return *this; 
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_reverse_iterator array<T,N>::const_reverse_iterator::operator++(int)
  {
        const_reverse_iterator tmp = *this; 
        --(*this);
        return tmp; 
  }


  template<typename T, std::size_t N>
  typename array<T,N>::const_reverse_iterator& array<T,N>::const_reverse_iterator::operator--()
  {
    this->ptr++;
    return *this; 
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_reverse_iterator array<T,N>::const_reverse_iterator::operator--(int)
  {
        const_reverse_iterator tmp = *this; 
        ++(*this);
        return tmp; 
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_reverse_iterator::const_reference array<T,N>::const_reverse_iterator::operator*() const 
  {
      return *(this->ptr);
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_reverse_iterator::const_pointer array<T,N>::const_reverse_iterator::operator->() const 
  {
      return this->ptr;  
  }

  template<typename T, std::size_t N>
  typename array<T,N>::const_reverse_iterator::const_reference array<T,N>::const_reverse_iterator::operator[](size_type pos) const 
  {
      return this->ptr;
  }

  template<typename T, std::size_t N>
  bool array<T,N>::const_reverse_iterator::operator==(const const_reverse_iterator& other) const 
  {
    return this->ptr == other.ptr; 
  }

  template<typename T, std::size_t N>
  int array<T,N>::const_reverse_iterator::operator<=>(const const_reverse_iterator& other) const 
  {
      if (this->ptr < other.ptr) {
          return -1; 
      }
      else if (this->ptr > other.ptr){ 
          return 1; 
      }

      return 0; 
  }

  template<typename T, std::size_t N>
  array<T,N>::reverse_iterator::reverse_iterator(pointer ptr)
     : const_reverse_iterator(ptr)
  {}
  
  template<typename T, std::size_t N>
  typename array<T,N>::reverse_iterator& array<T,N>::reverse_iterator::operator++()
  {
         this->ptr--;
         return *this; 
  }

  template<typename T, std::size_t N>
  typename array<T,N>::reverse_iterator array<T,N>::reverse_iterator::operator++(int)
  {
        const_reverse_iterator tmp = *this; 
        --(*this);
        return tmp; 
  }

  template<typename T, std::size_t N>
  typename array<T,N>::reverse_iterator& array<T,N>::reverse_iterator::operator--()
  {
        this->ptr++;
        return *this; 
  }

  template<typename T, std::size_t N>
  typename array<T,N>::reverse_iterator array<T,N>::reverse_iterator::operator--(int)
  {
        reverse_iterator tmp = *this; 
        ++(*this);
        return tmp; 
  }

  template<typename T, std::size_t N>
  typename array<T,N>::reverse_iterator::reference array<T,N>::reverse_iterator::operator*() {
        return *(this->ptr);
  }

  template<typename T, std::size_t N>
  typename array<T,N>::reverse_iterator::pointer array<T,N>::reverse_iterator::operator->() {
        return this->ptr;  
  }
  
  template<typename T, std::size_t N>
  typename array<T,N>::reverse_iterator::const_reference array<T,N>::reverse_iterator::operator[](size_type pos) const
  {
        return this->ptr[pos];
  }

  // end iterators 
}

#endif
