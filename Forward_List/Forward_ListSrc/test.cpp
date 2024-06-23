#include "../Forward_ListHeader/forward_list.h"

int main() {
    g3::forward_list<int> a = {1,2,3,4,5,6,78};
   
    size_t count = 5;
    const int& x = 4;
    a.insert_after(a.begin(), count, x);
    a.print();

}