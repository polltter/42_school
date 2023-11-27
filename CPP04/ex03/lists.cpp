//
// Created by mvenanci on 6/3/23.
//

#include "lists.hpp"

ll *head = 0;
ll *last = 0;

ll *add_list(AMateria *content) {
	ll *n = new ll;
	n->next = 0;
	n->cont = content;
	if (!head) {
		head = n;
		last = n;
	} else {
		last->next = n;
		last = n;
	}
	return n;
}

void delete_list() {
	ll *temp = head;
	while (head) {
		head = head->next;
		if (!temp->cont->equiped) {
			delete temp->cont;
			delete temp;
		} else {
			delete temp;
		}
		temp = head;
	}
}