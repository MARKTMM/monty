#include "monty.h"

/**
 * _rotr - rotates the stack to the bottom:
 * The last element of the stack becomes the top one,
 * and the top element of the stack becomes the second top one.
 * @head: linked list's head address.
 * @line_number: line number from file.
 * Return: nothing
 */
void _rotr(stack_t **head, unsigned int line_number)
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

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	n = tmp->n;
	(tmp->prev)->next = NULL;
	free(tmp);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	(*head)->prev = new;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}
