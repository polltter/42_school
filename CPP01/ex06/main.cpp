#include "Harl.hpp"

int main(int ac, char **av) {
    std::string str;
    Harl        h;

    if (ac == 2)
    {
        str = av[1];
        h.comlain(str);
    }
    else
        h.comlain("");
    return 0;
}
