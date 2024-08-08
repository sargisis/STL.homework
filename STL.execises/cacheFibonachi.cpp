#include <iostream>
#include <unordered_map>

int cache_fibonchi(int n, std::unordered_map<int, int> &m)
{
    if (n <= 2)
    {
        return 1;
    }
    if (m.count(n) == 0)
    {
        m.insert({n, cache_fibonchi(n - 1, m) + cache_fibonchi(n - 2, m)});
    }
    return m[n];
}


int main()
{

    std::unordered_map<int , int> m = {};

    std::cout << cache_fibonchi(1,m) << std::endl;
    std::cout << cache_fibonchi(2,m) << std::endl;
    std::cout << cache_fibonchi(3,m) << std::endl;
    std::cout << cache_fibonchi(4,m) << std::endl;
    std::cout << cache_fibonchi(5,m) << std::endl;
    std::cout << cache_fibonchi(6,m) << std::endl;

    std::cout << "=================" << std::endl;
    std::cout << cache_fibonchi(7,m) << std::endl;
}
