#include "monty.h"

/**
 * _rotl - rotates the stack to the top:
 * The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one.
 * @head: linked list's head address.
 * @line_number: line number from file.
 * Return: nothing
 */
void _rotl(stack_t **head, unsigned int line_number)
{
	int n;
	stack_t *tmp, *new;

	if (*head == NULL || (*head)->next == NULL)
		return;
	if (((*head)->next)->next == NULL)
	{
		_swap(head, line_number);
		return;
	}

	n = (*head)->n;
	_pop(head, line_number);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		error = 1;
		return;
	}
	new->n = n;
	new->next = NULL;
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}
