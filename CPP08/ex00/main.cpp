#include "easyfind.hpp"
#include <vector>

int	main()
{
    int ola[] = { 1, 2, 3, 123, 5 };
    std::vector<int> ar(ola, ola + sizeof(ola) / sizeof(*ola));

    std::vector<int>::iterator res = easyfind(ar, 123);
    if (res != ar.end())
        std::cout << *res << std::endl;
    else
        std::cout << "Item not found" << std::endl;
}