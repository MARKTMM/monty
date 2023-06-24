#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack.
 * @head: linked list's head address.
 * @line_number: line number from file.
 * Return: nothing
 */
void _pchar(stack_t **head, unsigned int line_number)
{
	int n;

	if (*head == NULL)
	{
		dprintf(
				STDERR_FILENO,
				"L%d: can't pchar, stack empty\n",
				line_number
		       );
		error = 1;
		return;
	}

	n = (*head)->n;

	if (!(n >= 32 && n <= 126))
	{
		dprintf(
				STDERR_FILENO,
				"L%d: can't pchar, value out of range\n",
				line_number
		       );
		error = 1;
		return;
	}
	putchar(n);
	putchar('\n');
}
