#include "sort.h"

/**
 * cocktail_sort_list - function sorts a doubly linked list
 *						of integers in ascending order
 *						using the 'Cocktail shaker sort' algorithm.
 *
 * @list: pointer to pointer to the doubly linked list.
 *
 * Return: void.
*/
void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *node = NULL;

	if (list == NULL || *list == NULL)
	{
		return;
	}

	while (swapped != 0)
	{
		swapped = 0;
		for (node = *list; node != NULL && node->next != NULL; node = node->next)
		{
			if (node->n > node->next->n)
			{
				cocktail_swap_nodes(list, node, node->next);
				node = node->prev;
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}
		if (swapped == 0)
		{
			break;
		}
		swapped = 0;
		for (; node != NULL && node->prev != NULL; node = node->prev)
		{
			if (node->n < node->prev->n)
			{
				cocktail_swap_nodes(list, node->prev, node);
				node = node->next;
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}
	}
}

/**
 * cocktail_swap_nodes - function swaps nodes.
 *
 * @list: pointer to pointer to the doubly linked list.
 * @node1: pointer to the first node.
 * @node2: pointer to the second node.
 *
 * Return: void.
*/
void cocktail_swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
	}
	else
	{
		*list = node2;
	}
	if (node2->next != NULL)
	{
		node2->next->prev = node1;
	}
	node2->prev = node1->prev;
	node1->next = node2->next;
	node2->next = node1;
	node1->prev = node2;
}
