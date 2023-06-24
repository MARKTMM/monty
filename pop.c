#include "monty.h"

/**
 * _pop - removes the top element of the stack.
 * @head: linked list's head address.
 * @line_number: line number from file.
 * Return: nothing
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*head == NULL)
	{
		dprintf(
			STDERR_FILENO,
			"L%d: can't pop an empty stack\n",
			line_number
			);
		error = 1;
		return;
	}

	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		tmp = *head;
		((*head)->next)->prev = NULL;
		(*head) = (*head)->next;
		free(tmp);
	}
}
