#include "sort.h"

/**
 * vexel_forward - exchange lists forward
 *
 * @list: list of nodes
 * @pointer: 1st node
 * @temp: 2nd node
 */

void vexel_forward(listint_t **list, listint_t **pointer, listint_t **temp)
{
	listint_t *prov = (*temp)->next;

	if ((*temp)->prev != NULL)
		(*temp)->prev->next = prov;
	else
		*list = prov;
	prov->prev = (*temp)->prev;
	(*temp)->next = prov->next;
	if (prov->next != NULL)
		prov->next->prev = *temp;
	else
		*pointer = *temp;
	(*temp)->prev = prov;
	prov->next = *temp;
	*temp = prov;
}

/**
 * vexel_backward - exchange lists backward
 *
 * @list: list of nodes
 * @pointer: 1st node
 * @temp: 2nd node
 */

void vexel_backward(listint_t **list, listint_t **pointer, listint_t **temp)
{
	listint_t *prov = (*temp)->prev;

	if ((*temp)->next != NULL)
		(*temp)->next->prev = prov;
	else
		*pointer = prov;
	prov->next = (*temp)->next;
	(*temp)->prev = prov->prev;
	if (prov->prev != NULL)
		prov->prev->next = *temp;
	else
		*list = *temp;
	(*temp)->next = prov;
	prov->prev = *temp;
	*temp = prov;
}


/**
 * cocktail_sort_list - martini sort
 *
 * @list: list of numbs
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *pointer, *temp;
	int flag = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (pointer = *list; pointer->next != NULL;)
		pointer = pointer->next;

	while (flag == 1)
	{
		flag = 0;
		for (temp = *list; temp != pointer; temp = temp->next)
		{
			if (temp->n > temp->next->n)
			{
				vexel_forward(list, &pointer, &temp);
				print_list(*list);
				flag = 1;
			}
		}
		for (temp = temp->prev; temp != *list; temp = temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				vexel_backward(list, &pointer, &temp);
				print_list(*list);
				flag = 1;
			}
		}
	}
}
