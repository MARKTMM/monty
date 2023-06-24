#include "monty.h"

/**
 * _add - adds the top 2 elements of the stack.
 * @head: linked list's head address.
 * @line_number: line number from file.
 * Return: nothing
 */
void _add(stack_t **head, unsigned int line_number)
{
	int sum = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(
			STDERR_FILENO,
			"L%d: can't add, stack too short\n",
			line_number
			);
		error = 1;
		return;
	}

	sum = ((*head)->n) + (((*head)->next)->n);
	_pop(head, line_number);
	(*head)->n = sum;
}
