#include "monty.h"

/**
 * _sub - substracts the top element of the stack from the second.
 * @head: linked list's head address.
 * @line_number: line number from file.
 * Return: nothing
 */
void _sub(stack_t **head, unsigned int line_number)
{
	int sub = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(
			STDERR_FILENO,
			"L%d: can't sub, stack too short\n",
			line_number
			);
		error = 1;
		return;
	}

	sub = (((*head)->next)->n) - ((*head)->n);
	_pop(head, line_number);
	(*head)->n = sub;
}
