#ifndef _FORWARD_LIST_HPP
#define _FORWARD_LIST_HPP

#include <iostream>
#include <stdexcept>
#include <initializer_list>

template <typename T>
class Forward_List {
private:
    struct Node {
        T val;
        Node* next;
        Node(const T& val) : val(val), next(nullptr) {}
    };
    
    Node* head;
    
    std::size_t _size = 0; 
public:
   using value_type = T;
   using _void = void; 
   using size_type = std::size_t;
   using referance = value_type&;
   using const_referance = const value_type&;
   using pointer = value_type*;
   using const_pointer = const value_type*;
public:
    Forward_List();
    Forward_List(std::initializer_list<T> initlist); 
    Forward_List(const Forward_List<T>& rhv); 
    Forward_List(Forward_List<T>&&);  
    const Forward_List& operator=(const Forward_List<T>&);
    const Forward_List& operator=(Forward_List<T>&&);
    ~Forward_List();
    T& front();
    T& operator[](size_type);
    void push_back(const_referance);
    void pop_back();
    void push_front(const_referance);
    void pop_front();
    constexpr bool empty() const noexcept;
    void clear() noexcept;
    void print() const;
    void _swap(const Forward_List<T>& rhv);
    void insert(size_type  , const_referance);
    void erase(size_type );
    constexpr size_type Size();
 
};

#include "ForwardList.hpp"

#endif // _FORWARD_LIST_HPP
