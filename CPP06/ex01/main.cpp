//
// Created by miguel on 04-09-2023.
//

#include "Serializer.hpp"

int	main()
{
    Data *pepeta = new Data;
    Data *orlando;

    Serializer	serio;

    pepeta->content = 10;
    orlando = serio.deserialize(serio.serialize(pepeta));
    if (orlando == pepeta)
        std::cout << "ola" << std::endl;
    std::cout << orlando->content << std::endl;
    delete pepeta;
}