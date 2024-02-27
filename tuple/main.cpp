#include "Tuple.hpp"

int main() {
    Tuple<int, char, double, std::string> t(44, 'a', 9.9, "Str");
    Tuple<double, char, double, std::string> tu(9.9, 'a', 8.8, "UU");

    auto& t_val_at_index_2 = t.getRest().getRest().getVal();
    std::cout << t_val_at_index_2 << std::endl; 

    auto& tu_val_at_index_2 = tu.getRest().getRest().getVal();
    std::cout << tu_val_at_index_2 << std::endl;

    return 0;
}

