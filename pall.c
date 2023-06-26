#include "monty.h"

/**
 * _pall - output every node data linked list
 * @head: memory alocation of the linked list's head
 * @line_number: line number of monty file we are treating
 * Return: null
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *h = *head;

	(void)line_number;

	if (*head == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
