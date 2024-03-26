#include "../ForwardHeader/ForwardList.h"

int main() {
    Forward_List<int> f = {1,2,3,4};
    

    f.push_back(55);
    f.print();
   
    f.insert(2,555);
    f.print();

    f.erase(1);
    f.print();
    
}