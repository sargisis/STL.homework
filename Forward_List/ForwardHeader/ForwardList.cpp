#ifndef __FORWARD_LIST_HPP___
#define __FORWARD_LIST_HPP___

#include "ForwardList.h"

template<typename T>
Forward_List<T>::Forward_List() 
    : head{nullptr}
    , _size{0}
{}

template<typename T>
Forward_List<T>::Forward_List(std::initializer_list<T> initlist) 
        : head{nullptr} 
        , _size{0}
{
     for(const T& val : initlist){
        push_back(val);
     }
}

template<typename T>
Forward_List<T>::Forward_List(const Forward_List<T>& rhv) : Forward_List(nullptr , 0) {
    if (rhv.head == nullptr) {
        return;
    }
    Node* current = rhv.head;
    while(current != nullptr) {
        push_back(current->val);
        current = current->next;
    }
}



template<typename T>
const Forward_List<T>& Forward_List<T>::operator=(const Forward_List<T>& rhv){
      if (this != &rhv){
            this->clear();
            this->_size = rhv._size;
            for (size_t i = 0; i < _size; ++i){
                this->head[i] = rhv.head[i];
            }
      } 
      return *this;
}

template<typename T>
const Forward_List<T>& Forward_List<T>::operator=(Forward_List<T>&& rhv){
    if (this != &rhv){
        this->clear();
        this->_size = std::move(rhv._size);
        for (size_t i = 0; i < _size; ++i){
            this->head = std::move(rhv.head);
        }
    }
    return *this;
}


template<typename T>
Forward_List<T>::~Forward_List() {
    clear();
}

template<typename T>
Forward_List<T>::referance Forward_List<T>::operator[](size_type index){
    size_t counter = 0;
    Node* current = this->head;

    while(current != nullptr) {
        if (counter == index) {
            return current->val;
        }
        current = current->next;
        ++counter;
    }
    
    throw std::out_of_range("Index out of range");
}

template<typename T>
Forward_List<T>::_void Forward_List<T>::push_back(const_referance val){
    Node* newNode = new Node(val);
    if (this->head == nullptr){
        this->head = newNode;
    }
    else {
        Node* current = this->head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
    }
    ++_size;
}

template<typename T>
Forward_List<T>::_void Forward_List<T>::pop_back() {
    if (this->head == nullptr){
        return;
    }
    if (this->head->next == nullptr){
        delete head;
        head = nullptr;
    }
    else {
        Node* current = this->head;
        while(current->next->next != nullptr){
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    --_size;
}

template<typename T>
constexpr bool Forward_List<T>::empty() const {
    return _size == 0;
}

template<typename T>
Forward_List<T>::_void Forward_List<T>::erase(size_type index){
    if (index >= _size){
        throw std::out_of_range("Index greater than _size");
    }

    if (index == 0){
        Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
        --_size;
        return;
    }

    Node* current = this->head;
    for(size_t i = 0; i < index - 1; ++i){
        current = current->next;
    }
    Node* todelete = current->next;
    current->next = todelete->next;
    delete todelete;
    --_size;
}

template<typename T>
constexpr Forward_List<T>::size_type Forward_List<T>::Size() {
    size_t size = 0; 
    Node* tmp = this->head;
    while (tmp)
    {
        tmp = tmp->next;
        ++size;
    }
    return size;
}

template<typename T>
Forward_List<T>::_void Forward_List<T>::insert(size_type index , const_referance val){
       if (index >= _size){
            throw std::runtime_error("index of great then member size");
       }
       if (this->head == nullptr){
             return;
       }
    
        if (index == 0){
           push_front(val);
        } 
    else {
        Node* current = this->head; 
        if (current != nullptr)
        for (int i = 0; i < index - 1 && current != nullptr; ++i){
             current = current->next; 
        }
        if (current != nullptr){
            Node* temp = new Node(val);
            temp->next = this->head->next;
            this->head->next = temp; 
            ++_size; 
        }
        else {
            throw std::exception();
        }
     }
}
template<typename T>
Forward_List<T>::_void Forward_List<T>::clear() noexcept {
    while(!Size()) {
       
        pop_front();
    }
 }

template<typename T>
Forward_List<T>::_void Forward_List<T>::print() const {
    Node* current = this->head;
    while(current){
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl; 
}   

template<typename T>
Forward_List<T>::_void Forward_List<T>::_swap(const Forward_List<T>& rhv){
     std::swap(head , rhv.head);
     std::swap(_size,  rhv._size);
}

template<typename T>
Forward_List<T>::_void Forward_List<T>::push_front(const_referance val){
    Node* newNode = new Node(val);
    newNode->next = this->head;
    head = newNode;
}

template<typename T>
Forward_List<T>::_void Forward_List<T>::pop_front() {
    Node* tmp = this->head;
    tmp->next = this->head->next; 
    delete tmp; 
    tmp = nullptr;
}

template<typename T>
Forward_List<T>::referance Forward_List<T>::front() {
    if (!Size()){
        throw std::logic_error("Error");
    }
    return head->val;
}


#endif // __FORWARD_LIST_HPP___
