#include "Vector.hpp"

int main(){
    Vector<int> v = {3,4,2,1,6};
    
    v.print(); 

    v.insert(3,2);
    v.print();

    v.erase(2);
    v.print();

    v.push_back(44);
    v.print();
    v.pop_back();
    v.print();
    
}