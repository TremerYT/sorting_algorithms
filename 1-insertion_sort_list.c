#include "sort.h"

/**
 * exchange_two - This swaps doubly linked elements
 * @i: This is the left element
 * @j: This is the right element
 * @list: This is all the doubly linked lists
 * Return: This should return pointer to the actual element
 */

listint_t *exchange_two(listint_t *i, listint_t *j, listint_t **list)
{
	if (i->prev)
	{
		(i->prev)->next = j;
	}
	else
	{
		*list = j, j->prev = NULL;
	}
	if ((j->next))
	{
		(j->next)->prev = i;
	}
	j->prev = i->prev;
	i->prev = j;
	i->next = j->next;
	j->next = i;
	return (i);
}
/**
 * insertion_sort_list - This sorts the list in ascending order
 * @list: This is the doubley linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *genuine;
	listint_t *previous, *rear;

	if (!list || !(*list) || !(*list)->next)
	{
		return;
	}
	genuine = (*list)->next;
	while (genuine)
	{
		previous = genuine->prev;
		rear = genuine;
		while (rear->prev && rear->n < previous->n)
		{
			genuine = exchange_two(previous, rear, list);
			print_list(*list);
			if (!rear->prev)
				break;
			previous = rear->prev;
		}
		genuine = genuine->next;
		previous = previous->next;
	}
}
