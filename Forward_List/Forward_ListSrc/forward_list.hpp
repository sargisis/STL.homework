#include "../Forward_ListHeader/forward_list.h"

template<typename T, typename Allocator>
g3::forward_list<T, Allocator>::forward_list()
    : m_head{nullptr}
    , m_size{0} {}

template<typename T, typename Allocator>
g3::forward_list<T, Allocator>::forward_list(const forward_list& rhv)
    : m_head{nullptr}
    , m_size{0} {
    Node* current = rhv.m_head; 
    while (current != nullptr) {
        push_back(current->val);
        current = current->next;
    }
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::forward_list(std::initializer_list<value_type> init) 
    : forward_list()
{
    for (const auto& val : init) {
       push_back(val);
    }
}

template<typename T, typename Allocator>
g3::forward_list<T, Allocator>::forward_list(forward_list&& rhv) noexcept
    : m_head{rhv.m_head}
    , m_size{rhv.m_size} {
    rhv.m_head = nullptr;
    rhv.m_size = 0;
}

template<typename T, typename Allocator>
template<typename InputIt>
g3::forward_list<T,Allocator>::forward_list(InputIt first , InputIt last) 
    : forward_list()
{
    for (auto it = first; it != last; ++it) {
        push_back(*it);
    }
}

template<typename T, typename Allocator>
g3::forward_list<T, Allocator>::~forward_list() {
    clear();
}

template<typename T, typename Allocator>
const g3::forward_list<T, Allocator>& g3::forward_list<T, Allocator>::operator=(const forward_list& rhv) {
    if (this != &rhv) {
        this->clear();
        Node* current = rhv.m_head;
        while (current != nullptr) {
            push_back(current->val);
            current = current->next;
        }
    }
    return *this;
}

template<typename T, typename Allocator>
const g3::forward_list<T,Allocator>& g3::forward_list<T,Allocator>::operator=(forward_list&& rhv) {
    if (this != &rhv) {
        this->m_size = std::move(rhv.m_size);
        this->m_head = std::move(rhv.m_head);

        this->m_size = 0; 
        this->m_head = nullptr;
    }
    return *this; 
}

template<typename T, typename Allocator>
g3::forward_list<T, Allocator>::allocator_type g3::forward_list<T, Allocator>::get_allocator() const {
    return this->m_alloc;
}

template<typename T, typename Allocator>
void g3::forward_list<T, Allocator>::assign(size_type count, const_referance value) {
    clear();
    for (size_type i = 0; i < count; ++i) {
        push_back(value);
    }
}

template<typename T, typename Allocator>
template<typename InputIt>
void g3::forward_list<T, Allocator>::assign(InputIt first, InputIt last) {
    clear();
    for (auto it = first; it != last; ++it) {
        push_back(*it);
    }
}

template<typename T, typename Allocator>
void g3::forward_list<T, Allocator>::assign(std::initializer_list<value_type> ilist) {
    clear();
    for (const auto& val : ilist) {
        push_back(val);
    }
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::iterator g3::forward_list<T,Allocator>::begin() {
    return iterator(this->m_head);
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::const_iterator g3::forward_list<T,Allocator>::begin() const {
    return const_iterator(this->m_head);
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::const_iterator g3::forward_list<T,Allocator>::cbegin() const {
    return const_iterator(this->m_head);
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::iterator g3::forward_list<T,Allocator>::end() {
    return iterator(this->m_head + this->m_size);
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::const_iterator g3::forward_list<T,Allocator>::end() const{
    return const_iterator(this->m_head + this->m_size);
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::const_iterator g3::forward_list<T,Allocator>::cend() const{
    return const_iterator(this->m_head + this->m_size);
}

template<typename T, typename Allocator>
g3::forward_list<T, Allocator>::referance g3::forward_list<T, Allocator>::front() {
    return this->m_head->val;
}

template<typename T, typename Allocator>
g3::forward_list<T, Allocator>::const_referance g3::forward_list<T, Allocator>::front() const {
    return this->m_head->val;
}

template<typename T, typename Allocator>
bool g3::forward_list<T, Allocator>::empty() const {
    return this->m_size == 0;
}

template<typename T, typename Allocator>
g3::forward_list<T, Allocator>::size_type g3::forward_list<T, Allocator>::max_size() const noexcept {
    return std::numeric_limits<size_type>::max() / sizeof(Node);
}

template<typename T, typename Allocator>
void g3::forward_list<T, Allocator>::clear() noexcept {
    while (m_head != nullptr) {
        Node* temp = this->m_head;
        this->m_head = this->m_head->next;
        delete temp;
    }
    m_size = 0;
}

template<typename T, typename Allocator>
void g3::forward_list<T, Allocator>::push_front(const_referance value) {
    Node* newNode = new Node(value);
    newNode->next = m_head;
    m_head = newNode;
    ++m_size;
}

template<typename T, typename Allocator>
void g3::forward_list<T, Allocator>::push_front(rvalue_referance value) {
    Node* newNode = new Node(std::move(value));
    newNode->next = m_head;
    m_head = newNode;
    ++m_size;
}

template<typename T, typename Allocator>
void g3::forward_list<T, Allocator>::pop_front() {
    if (m_head != nullptr) {
        Node* temp = this->m_head;
        this->m_head = this->m_head->next;
        delete temp;
        --m_size;
    }
}

template<typename T, typename Allocator>
void g3::forward_list<T, Allocator>::print() const {

    Node* current = this->m_head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template<typename T, typename Allocator>
void g3::forward_list<T, Allocator>::resize(size_type count) {
    if (this->m_size == count) {
        return;
    }

    if (this->m_size < count) {
        
        size_type nodesToAdd = count - this->m_size;
        Node* current = this->m_head;
        if (current == nullptr) {
          
            this->m_head = new Node(count);
            current = this->m_head;
            --nodesToAdd;
        } else {
            
            while (current->next != nullptr) {
                current = current->next;
            }
        }

        for (size_type i = 0; i < nodesToAdd; ++i) {
            current->next = new Node(count);
            current = current->next;
        }
    } else {
      
        size_type nodesToRemove = this->m_size - count;
        Node* current = this->m_head;
        for (size_type i = 0; i < count - 1; ++i) {
            current = current->next;
        }

        
        Node* toDelete = current->next;
        current->next = nullptr;

        
        while (toDelete != nullptr) {
            Node* next = toDelete->next;
            delete toDelete;
            toDelete = next;
        }
    }
    this->m_size = count;
}

template<typename T, typename Allocator>
void g3::forward_list<T,Allocator>::resize(size_type count , const_referance value) {
    if (this->m_size == count) {
        return;
    }
    if (this->m_size < count ) {
        size_type add_nodes = count - this->m_size;
        Node* current = this->m_head;
        if (current == nullptr) {
            this->m_head = new Node(value);
            current->next = this->m_head;
            --add_nodes;
        } else {
            while (current->next != nullptr) {
                current = current->next; 
            }
            for (size_type i = 0; i < add_nodes; ++i) {
                current->next = new Node(value);
                current = current->next; 
            }
        }
    } else {
        Node* current = this->m_head;
        for (size_type i = 0; i < count - 1; ++i) {
            current = current->next; 
        }
        Node* to_delete = current->next; 
        current->next = nullptr;

        while (to_delete != nullptr) {
            Node* next = to_delete->next; 
            delete to_delete;
            to_delete = next; 
        }
    }
   this->m_size = count; 
}

template<typename T, typename Allocator> 
void g3::forward_list<T,Allocator>::push_back(const_referance value) {
   Node* new_node = new Node(value);
    if (this->m_head == nullptr) {
        this->m_head = new_node;
    } 
    else {
        Node* current = this->m_head; 
        while (current->next) {
            current = current->next;
        }
        current->next = new_node; 
    }
    this->m_size++;
}

template<typename T, typename Allocator>
void g3::forward_list<T,Allocator>::push_back(rvalue_referance value) {
    Node* new_node = new Node(value);
    if (this->m_head == nullptr) {
        return;
    }
    else {
        Node* current = this->m_head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
    this->m_size++; 
   
}

template<typename T, typename Allocator>
void g3::forward_list<T,Allocator>::swap(forward_list& other) noexcept {
    std::swap(this->m_head , other.m_head);
    std::swap(this->m_size , other.m_size);
}

template<typename T, typename Allocator>
int g3::forward_list<T,Allocator>::compare(const forward_list& other) const {
    if (this->m_head < other.m_head) {
        return -1;
    }else if (this->m_head > other.m_head) {
        return 1;
    }
    return 0; 
}

template<typename T, typename Allocator>
bool g3::forward_list<T,Allocator>::operator==(const forward_list& other) const {
    return this->compare(other) == 0;
}
template<typename T, typename Allocator>
bool g3::forward_list<T,Allocator>::operator!=(const forward_list& other) const {
    return this->compare(other) != 0;
}
template<typename T, typename Allocator>
bool g3::forward_list<T,Allocator>::operator>(const forward_list& other) const {
    return this->compare(other) > 0;
}
template<typename T, typename Allocator>
bool g3::forward_list<T,Allocator>::operator>=(const forward_list& other) const {
    return this->compare(other) >= 0;
}
template<typename T, typename Allocator>
bool g3::forward_list<T,Allocator>::operator<(const forward_list& other) const {
    return this->compare(other) < 0;
}

template<typename T, typename Allocator>
bool g3::forward_list<T,Allocator>::operator<=(const forward_list& other) const {
    return this->compare(other) <= 0;
}


// start write iterators 

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::const_iterator::const_iterator(Node* ptr)
    : ptr{ptr}
{}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::const_iterator& g3::forward_list<T,Allocator>::const_iterator::operator++() {
    if (this->ptr != nullptr) {
        this->ptr = this->ptr->next; 
    }
    return *this; 
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::const_iterator g3::forward_list<T,Allocator>::const_iterator::operator++(int) {
    const_iterator tmp = *this; 
    if (this->ptr == nullptr) {
        this->ptr = this->ptr->next;
    }
    return tmp; 
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::const_referance g3::forward_list<T,Allocator>::const_iterator::operator*() const {
    return (this->ptr->val);
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::const_pointer g3::forward_list<T,Allocator>::const_iterator::operator->() const {
    return (this->ptr);
}

template<typename T, typename Allocator>
int g3::forward_list<T,Allocator>::const_iterator::compare(const const_iterator& other) const {
    if (this->ptr < other.ptr) {
        return -1;
    } else if (this->ptr > other.ptr) {
        return 1;
    }
    return 0; 
}

template<typename T, typename Allocator>
bool g3::forward_list<T,Allocator>::const_iterator::operator==(const const_iterator& rhv) const {
    return this->compare(rhv) == 0; 
}

template<typename T, typename Allocator>
bool g3::forward_list<T,Allocator>::const_iterator::operator!=(const const_iterator& rhv) const {
    return this->compare(rhv) == 0; 
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::iterator::iterator(Node* ptr) 
    : const_iterator(ptr)
{}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::referance g3::forward_list<T,Allocator>::iterator::operator*() const {
    return (this->ptr->val);
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::pointer g3::forward_list<T,Allocator>::iterator::operator->() const {
    return *(this->ptr);
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::iterator& g3::forward_list<T,Allocator>::iterator::operator++() {
    if (this->ptr != nullptr) {
        this->ptr = this->ptr->next; 
    }
    return *this;
}
template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::iterator g3::forward_list<T,Allocator>::iterator::operator++(int) {
    iterator tmp = *this; 
    if (this->ptr != nullptr) {
        this->ptr = this->ptr->next; 
    }
    return tmp; 
}


template<typename T, typename Allocator>
bool g3::forward_list<T,Allocator>::iterator::operator==(const iterator& rhv) const {
    return this->compare(rhv) == 0; 
}

template<typename T, typename Allocator>
bool g3::forward_list<T,Allocator>::iterator::operator!=(const iterator& rhv) const {
    return this->compare(rhv) == 0; 
}

// end iterators 

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::iterator g3::forward_list<T,Allocator>::insert_after(const_iterator pos , const_referance value) {
   
    if (this->m_head == nullptr && pos.ptr == nullptr) {
       
        this->m_head = new Node(value);
        ++m_size; 
        return iterator(this->m_head);
    }
   

    Node* current = pos.ptr;
    Node* new_node = new Node(value);

    new_node->next = current->next;
    current->next = new_node;

    this->m_size++;
    return iterator(new_node);
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::iterator g3::forward_list<T,Allocator>::insert_after(const_iterator pos , rvalue_referance value) {
    if (this->m_head == nullptr && pos.ptr == nullptr) {
       
        this->m_head = new Node(value);
        ++m_size; 
        return iterator(this->m_head);
    }
   
    Node* current = pos.ptr; 
    Node* new_node = new Node(value);

    new_node->next = current->next;
    current->next = new_node;

    this->m_size++;
    return iterator(new_node);
}
template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::iterator g3::forward_list<T,Allocator>::insert_after(const_iterator pos , size_type count , const_referance value) {
   
    if (this->m_head == nullptr && pos.ptr == nullptr) {
        this->m_head = new Node(value);
        ++m_size; 
        return iterator(this->m_head);
    }
    size_type index = count - this->m_size; 
    Node* current = pos.ptr;
    Node* new_node = new Node(value);

    if (current != nullptr) {
        for (size_type i = 0; i < index - 1; ++i) {
            current = current->next; 
        }
    } if (current != nullptr) {
        new_node->next = current->next; 
        current->next = new_node; 
        ++m_size; 
    }
    return (new_node);
}


