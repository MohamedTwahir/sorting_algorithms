#include "sort.h"

/**
 * len_list - function to return length of list
 * for insertion_sort_list
 * @p: pointer to the list
 *
 * Return: length of list
 */
int len_list(listint_t *p)
{
	int len = 0;

	while (p)
	{
		len++;
		p = p->next;
	}
	return (len);
}

/**
 * insertion_sort_list - sorts a linked list using Insert Sort Algorithm
 * @list: double pointer to the list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL, *one = NULL;
	listint_t *two = NULL, *three = NULL, *four = NULL;

	if (!list || !(*list) || len_list(*list) < 2)
		return;

	curr = *list;

	while (curr)
	{
		if (curr->prev && curr->n < curr->prev->n)
		{
			one = curr->prev->prev;
			two = curr->prev;
			three = curr;
			four = curr->next;

			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
				*list = three;
			two->prev = three;
			curr = *list;
			print_list(*list);
			continue;
		}
		else
			curr = curr->next;
	}
}

