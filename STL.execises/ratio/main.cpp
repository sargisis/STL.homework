#include "ratio.h"
#include <iostream>

using namespace rat;

int main() {
    
    using milli = ratio<1, 1000>;  
    using kilo = ratio<1000, 1>;   

    std::cout << ratio<1000,1>::num << std::endl; 

    std::cout << "milli: " << milli::num << "/" << milli::den << std::endl;
    std::cout << "kilo: " << kilo::num << "/" << kilo::den << std::endl;

    return 0;
}