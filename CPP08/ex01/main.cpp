#include "easyfind.hpp"
#include <vector>

int	main()
{
    int ola[] = { 1, 2, 3, 4, 5 };
    std::vector<int> ar(ola, ola + sizeof(ola) / sizeof(*ola));

    std::vector<int>::iterator res = easyfind(ar, 6);
    if (res != ar.end())
        std::cout << *(easyfind(ar, 6)) << std::endl;
    else
        std::cout << "Item not found" << std::endl;
}