#include "monty.h"

/**
 * free_list - frees the linked list
 * @head: head of the stack
 * @fp: file pointer.
 * @line: line we're reading.
 * Return: nothing.
 */
void free_list(stack_t **head, FILE *fp, char *line)
{
	if (*head != NULL)
	{
		while ((*head)->next)
		{
			(*head) = (*head)->next;
			free((*head)->prev);
		}
		free(*head);
	}
	fclose(fp);
	free(line);
}
