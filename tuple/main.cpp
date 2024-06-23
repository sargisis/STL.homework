#include <iostream>
#include "tuple.h"  // Include the correct header file

int main() {
    g3::tuple<int, double> f(1, 5.5);
    g3::tuple<int , double> f1(5,55.5);

    f1.swap(f);

    auto value = f1.get_rest().get_val();
    auto value1 = f.get_rest().get_val();

    
    
    std::cout << value << std::endl; 
    std::cout << value1 << std::endl;
}
