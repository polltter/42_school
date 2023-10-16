//
// Created by miguel on 16-10-2023.
//
#include "iter.hpp"
template <class T>
void	increase(T *i)
{
    *i += 1;
}

template <class T>
void	print_array(T *array, unsigned int lenght)
{
    for (unsigned int i = 0; i < lenght; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int	main()
{
    int	int_array[10];

    for (unsigned int i = 0; i < 10; i++)
        int_array[i] = i;

    print_array(int_array, 10);
    iter(int_array, 10, increase);
    print_array(int_array, 10);

    std::cout << std::endl << "----------------" << std::endl << std::endl;

    char char_array[26];

    for (unsigned int i = 0; i < 26; i++)
        char_array[i] = i + 'a';

    print_array(char_array, 26);
    iter(char_array, 26, increase);
    print_array(char_array, 26);
}