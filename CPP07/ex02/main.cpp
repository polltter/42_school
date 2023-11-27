#include "Array.hpp"

int	main()
{
    Array<char>	ola;

    try
    {
		ola[9] = 'a';
        std::cout << ola[9] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}