#include "../ArrayHeader/Array.h"

int main() {
    Array<int, 5> s{1,3,2,4,7};
    Array<int , 5> s1{1,2,3,4,5};
    
    s1 = std::move(s); 
    s1.print();

    s1.fill(3);
    s1.print();
    
}