#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using an insertion sort algorithm
 * @list: doubly linked list of integers to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *lead, *follow, *new, *temp;

	if (!list || !(*list) || !((*list)->next))
		return;

	follow = (*list);
	lead = (*list)->next;
	while (lead)
	{
		new = lead->next;
		while (follow && lead->n < follow->n)
		{
			if (follow->prev)
				follow->prev->next = lead;
			else
				/* if lead makes it to house left, now head */
				*list = lead;
			if (lead->next)
				lead->next->prev = follow;
			temp = lead->next;
			lead->next = follow;
			lead->prev = follow->prev;
			follow->next = temp;
			follow->prev = lead;
			print_list(*list);
			/* compare next pair, flowing to house left */
			follow = lead->prev;
		}
		/* lead sorted to left, new cycle starts @ right leading edge */
		lead = new;
		if (lead)
			follow = lead->prev;
	}
}
