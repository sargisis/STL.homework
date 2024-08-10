#include <iostream>

template<typename... Ts>
int sum(Ts... args)
{
   return (args + ...);
}

template<typename... Ts>
int sub(Ts... args)
{
   return (args - ...);
}

template<typename... Ts>
int mul(Ts... args)
{
    return (args * ...);
}

template<typename... Ts>
double div(Ts... args)
{
    return (args / ...);
}


template<typename... Ts>
int mod(Ts... args)
{
    return (args % ...);
}


int main()
{
   std::cout << sum(5,6,7,8) << std::endl; 
   std::cout << mul(5,6,78) << std::endl; 
   std::cout << div(6.5,78) << std::endl;
   std::cout << mod(55,3) << std::endl; 
   std::cout << sub(44,5) << std::endl; 
}