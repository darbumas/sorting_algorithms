#include "sort.h"

/**
 * insertion_sort_list - ƒ() sorts a doubly linked list of integers in
 * ascending order via the 'insertion sort' algorithm.
 * @list: the passed doubly linked list.
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (!list || !*list || !(*list)->next)
		return;
	current = *list;

	while (current && current->next != NULL)
	{
		current = current->next;
		while (current->prev && current->n < current->prev->n)
		{
			current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
		}
	}
}
