#include "sort.h"

/**
 * node_swap - This swaps two nodes in a doublely linked list
 * @head: This is the head
 * @node_1: This is the first node
 * @node_2: This is the second node
 */

void node_swap(listint_t **head, listint_t **node_1, listint_t *node_2)
{
	(*node_1)->next = node_2->next;
	if (node_2->next != NULL)
		node_2->next->prev = *node_1;
	node_2->prev = (*node_1)->prev;
	node_2->next = *node_1;
	if ((*node_1)->prev != NULL)
		(*node_1)->prev->next = node_2;
	else
		*head = node_2;
	(*node_1)->prev = node_2;
	*node_1 = node_2->prev;
}

/**
 * insertion_sort_list - This sorts a doubley linked list
 * @list: This is the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *enter, *c;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = c)
	{
		c = i->next;
		enter = i->prev;
		while (i != NULL && i->n < enter->n)
		{
			node_swap(list, &enter, i);
			print_list((const listint_t *)*list);
		}
	}
}
