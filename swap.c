#include "monty.h"

/**
 * _swap - swap the top two elements of the stack.
 * @head: linked list's head address.
 * @line_number: line number from file.
 * Return: nothing
 */
void _swap(stack_t **head, unsigned int line_number)
{
	int n;

	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(
			STDERR_FILENO,
			"L%d: can't swap, stack too short\n",
			line_number
			);
		error = 1;
		return;
	}

	n = (*head)->n;
	(*head)->n = ((*head)->next)->n;
	((*head)->next)->n = n;
}
