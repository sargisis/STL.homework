#include "ForwardList.h"

int main() {
    Forward_List<int> f = {1,2,3,4};
    Forward_List<int> s = {3,2,1,5};
   
    
   
    s = std::move(f);
    f.print();
}