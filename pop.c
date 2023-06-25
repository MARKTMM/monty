#include "monty.h"

/**
 * _pop - removes top element of stack
 * @head: linked list's head address
 * @line_number: number line of file
 * Return: null
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
