#include "sort.h"

/**
 * insertion_sort_list - function sorts a doubly linked list of integers in
 *			ascending order using the Insertion sort algorithm.
 *
 * @list: pointer to pointer to the doubly linked list.
 *
 * Return: void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL)
	{
		return;
	}

	current = (*list)->next;
	while (current != NULL)
	{
		while (current->prev != NULL && current->prev->n > current->n)
		{
			swap_nodes(list, current->prev, current);
			print_list((const listint_t *)*list);
		}
		current = current->next;
	}
}

/**
 * swap_nodes - helper function to swap 2 nodes.
 *
 * @list: pointer to pointer to the doubly linked list.
 * @node1: pointer to the first node.
 * @node2: pointer to the second node.
 *
 * Return: void.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1 == NULL || node2 == NULL)
	{
		return;
	}

	/* if node1 is not the head of the list */
	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
	}

	/* if node2 is not the tail of the list */
	if (node2->next != NULL)
	{
		node2->next->prev = node1;
	}

	/* swap node1 and node2 in the list */
	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;

	/* if node2 is now the head of the list */
	if (node2->prev == NULL)
	{
		*list = node2;
	}
}
