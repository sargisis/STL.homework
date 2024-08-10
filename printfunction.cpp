#include <iostream>
#include <string>
#include <sstream>

std::string sep()
{
    return " ";
}

std::string end()
{
    return "\n";
}

std::string arrow()
{
    return "->";
}

template<std::string (*SEP)() = sep, std::string (*END)() = end , typename... Ts>
void print(Ts... args)
{
    std::cout << "ostream " << std::endl; 
    ((std::cout << args << SEP()), ...) << END();
}

template<std::string (*SEP)() = sep , std::string (*END)() = end , typename... Ts>
void print(std::stringstream& os , Ts... args)
{
    std::cout << "stringstream" << std::endl; 
    ((std::cout << args << SEP()), ...) << END();
}

int main()
{
    std::stringstream ob;
    
    print<arrow>(ob,3,45,6,7,84);
    std::cout << std::endl; 
    print<arrow>(4,5,6,798);
}