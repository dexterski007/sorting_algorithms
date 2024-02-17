#include "sort.h"

/**
 * vexel - exchange lists
 *
 * @list1: list 1
 * @list2: list 2
 */

void vexel(listint_t *list1, listint_t *list2)
{
	if (list1->prev)
		list1->prev->next = list2;
	if (list2->next)
		list2->next->prev = list1;
	list1->next = list2->next;
	list2->prev = list1->prev;
	list1->prev = list2;
	list2->next = list1;
}



/**
 * insertion_sort_list - insertion sort
 *
 * @list: list of numbs
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *point, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	point = (*list)->next;
	while (point)
	{
		temp = point;
		point = point->next;
		while (temp && temp->prev)
		{
			if (temp->prev->n > temp->n)
			{
				vexel(temp->prev, temp);
				if (!temp->prev)
					*list = temp;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
	}
}
