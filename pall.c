#include "monty.h"

/**
 * _pall - print all linked list node data.
 * @head: address of linked list's head.
 * @line_number: the line number of the monty file we're treating.
 * Return: nothing.
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
