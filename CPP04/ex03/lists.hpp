//
// Created by mvenanci on 6/3/23.
//

#ifndef INC_42_SCHOOL_LISTS_HPP
#define INC_42_SCHOOL_LISTS_HPP

#include "AMateria.hpp"

typedef struct llist ll;

struct llist {
	AMateria	*cont;
	ll 			*next;
};

ll *add_list(AMateria *content);
void delete_list();

#endif //INC_42_SCHOOL_LISTS_HPP
