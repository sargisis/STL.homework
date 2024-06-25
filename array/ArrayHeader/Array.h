#ifndef __Array__
#define __Array__
   
#include <initializer_list>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <exception>
#include <cstddef>
#include <type_traits>
#include <compare>
#include <limits>
#include <ostream>

namespace g3 {
    template<typename T, std::size_t N>
    struct array 
    {   
        public:
        using value_type = T;
        using pointer  = value_type*;
        using const_pointer = const value_type*;
        using reference = value_type&;
        using const_reference = const value_type&;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
         
        public:

        class iterator;
        class const_iterator; 
        class reverse_iterator;
        class const_reverse_iterator;

        public:

        array(std::initializer_list<T> ilist); 
       

        public:
        constexpr void fill(const_reference value) noexcept;
        constexpr void swap(array& other) noexcept(std::is_nothrow_swappable_v<T>);
        
        public:
        constexpr iterator begin() noexcept;
        constexpr const_iterator begin() const noexcept;
        constexpr iterator end() noexcept;
        constexpr const_iterator end() const noexcept;
 
        constexpr reverse_iterator  rbegin() noexcept;
        constexpr const_reverse_iterator rbegin() const noexcept;
        constexpr reverse_iterator rend() noexcept;
        constexpr const_reverse_iterator rend() const noexcept;
 
        constexpr const_iterator cbegin() const noexcept;
        constexpr const_iterator cend() const noexcept;
        constexpr const_reverse_iterator crbegin() const noexcept;
        constexpr const_reverse_iterator crend() const noexcept;
        
        public:
        [[nodiscard]] constexpr bool empty() const noexcept;
        constexpr size_type size() const noexcept;
        constexpr size_type max_size() const noexcept;

        public:
        constexpr reference  operator[](size_type index);
        constexpr const_reference operator[](size_type index) const;
        constexpr reference at(size_type n);
        constexpr const_reference at(size_type n) const;
        constexpr reference front();
        constexpr const_reference front() const;
        constexpr reference  back();
        constexpr const_reference back() const;
        constexpr pointer data() noexcept;
        constexpr const_pointer data() const noexcept;

        private:
        T m_arr[N];
    };
    
    template<typename T, std::size_t N>
    struct array<T,N>::const_iterator 
    {
      public:
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;
        using const_reference = const value_type&;
        using const_pointer = const value_type*;

      private:
          friend class array<T,N>;
      protected:
          const_pointer ptr; 
      private:
        explicit const_iterator(const_pointer ptr);
      public:
          const_iterator() = default; 
          const_iterator(const const_iterator& rhv) = default; 
          const_iterator(const_iterator&&) = default;

         const_iterator& operator=(const const_iterator&) = default;      
         const_iterator& operator=(const_iterator&&) = default;
      public:
          const_iterator operator+(size_type n) const;      
          const_iterator operator-(size_type n) const;

          const_iterator& operator++();
          const_iterator operator++(int);

          const_iterator& operator--();
          const_iterator operator--(int);

          const_iterator& operator+=(difference_type offset);
          const_iterator& operator-=(difference_type offset);
        

          const_reference operator*() const;
          const_pointer operator->() const;

          const_reference operator[](size_type index) const;
            

         bool operator==(const const_iterator& other) const; 
         int operator<=>(const const_iterator& other) const;         
         const_iterator operator+(difference_type offset);
         const_iterator operator-(difference_type offset);
         difference_type operator-(const const_iterator& other);

    };

    template<typename T, std::size_t N>
    struct array<T,N>::iterator : public array<T,N>::const_iterator 
    {   
        public:
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;
        using const_reference = const value_type&;
        using const_pointer = const value_type*;


        private:
            friend class array<T,N>;
        private:
          explicit iterator(pointer ptr);
        public:
            iterator() = default; 
            iterator(const iterator& rhv) = default; 
            iterator(iterator&& rhv) = default; 

             iterator& operator=(const iterator& rhv) = default; 
             iterator& operator=(iterator&& rhv) = default; 

        public:
            iterator operator+(size_type n) const;      
            iterator operator-(size_type n) const;

        public:
           reference operator*();
           pointer operator->();

    };  
    
    template<typename T, std::size_t N>
    struct array<T,N>::const_reverse_iterator 
    {
        public:
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;
        using const_reference = const value_type&;
        using const_pointer = const value_type*;
        
        protected:
        const_reverse_iterator(pointer ptr);

        protected:
        pointer ptr; 
        
        public:
            const_reverse_iterator() = default; 
            const_reverse_iterator(const const_reverse_iterator& rhv) = default; 
            const_reverse_iterator(const_reverse_iterator&& rhv) = default;

             const_reverse_iterator& operator=(const const_reverse_iterator& rhv) = default; 
             const_reverse_iterator& operator=(const_reverse_iterator&& rhv) = default; 

        public:
            const_reverse_iterator operator+(difference_type offset) const;
            const_reverse_iterator operator-(difference_type offset) const; 

            const_reverse_iterator& operator++();
            const_reverse_iterator operator++(int);
            const_reverse_iterator& operator--();
            const_reverse_iterator operator--(int);

            const_reference operator*() const;
            const_pointer operator->() const;

            const_reference operator[](size_type index) const; 

            bool operator==(const const_reverse_iterator& other) const; 
            int operator<=>(const const_reverse_iterator& other) const; 

    };  
    template<typename T, std::size_t N>
    struct array<T,N>::reverse_iterator : public array<T,N>::const_reverse_iterator 
    {   
        public:
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;
        using const_reference = const value_type&;
        using const_pointer = const value_type*;

        private:
            friend class array<T,N>; 
        private:
           explicit reverse_iterator(pointer ptr);
        public:
           reverse_iterator() = default; 
           reverse_iterator(const reverse_iterator& rhv) = default; 
           reverse_iterator(reverse_iterator&& rhv) = default; 

            reverse_iterator& operator=(const reverse_iterator& rhv) = default; 
            reverse_iterator& operator=(reverse_iterator& rhv) = default; 
        public:

           reverse_iterator& operator++();
           reverse_iterator operator++(int);
           reverse_iterator& operator--();
           reverse_iterator operator--(int);

        public:

           reference operator*();
           pointer operator->();
        
        public:
           const_reference operator[](size_type pos) const;

    };
    
}

#include "Array.hpp"


#endif // __Array__ 
