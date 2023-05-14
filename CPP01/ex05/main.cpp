#include "Harl.hpp"


int	main(void)
{
    Harl		harl;
    std::string	msgs[7];
    msgs[0] = "DEBUG";
    msgs[1] = "INFO";
    msgs[2] = "WARNING";
    msgs[3] = "ERROR";
    msgs[4] = "info";
    msgs[5] = "hello";
    msgs[6] = "";

    for (int i = 0; i < 7; i++)
        harl.complain(msgs[i]);

}
