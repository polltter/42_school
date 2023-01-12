#include "list_utils.h"
#include <stdio.h>

void	print_list(t_elems	*elem, void *o)
{
	(void)o;
	printf("%s\n", elem->content);
}

void a(void *e){

	array(e)->for_each(print_list, NULL);	
}

int main()
{
	void *e = creat_array();
	array(e)->add("o ezequiel gosta de cona\n")->del = NULL;
	a(e);
	array(e)->destroy();
}

