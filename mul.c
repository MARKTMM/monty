#include "monty.h"

/**
 * _mul - multiplies the second top element of the stack with the top element.
 * @head: linked list's head address.
 * @line_number: line number from file.
 * Return: nothing
 */
void _mul(stack_t **head, unsigned int line_number)
{
	int mul = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(
				STDERR_FILENO,
				"L%d: can't mul, stack too short\n",
				line_number
		       );
		error = 1;
		return;
	}

	mul = (((*head)->next)->n) * ((*head)->n);
	_pop(head, line_number);
	(*head)->n = mul;
}
