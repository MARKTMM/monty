#include "monty.h"

/**
 * treat_line - function that gets the line from monty file and tokenize it
 * to check for the correct command.
 * @head: linked list' head address.
 * @fp: file pointer.
 * @line: line we're treating from the monty file.
 * @line_number: line number.
 * @mode: 0 if stack, 1 if queue
 * Return: nothing.
 */
void treat_line(stack_t **head, FILE *fp, char *line,
unsigned int line_number, int *mode)
{
	char *token = NULL;
	int mode_changed = 0;

	token = strtok(line, " \n");
	while (token && token[0] == ' ')
		token = strtok(NULL, " \n");
	if (!token)
		return;
	mode_changed = check_mode(token, mode);
	if (mode_changed)
		return;
	treat_token(head, fp, line, token, line_number, mode);
}
/**
 * check_mode - checks if we have mode changes (stack or queue)
 * @token: the word we're checking
 * @mode: 0 if stack, 1 if queue
 * Return: 1 if changed, 0 if not changed
 */
int check_mode(char *token, int *mode)
{
	if (!strncmp(token, "stack", 5) &&
			(token[5] == '\0' || token[5] == ' ' || token[5] == '\n'))
	{
		*mode = 0;
		return (1);
	}

	if (!strncmp(token, "queue", 5) &&
			(token[5] == '\0' || token[5] == ' ' || token[5] == '\n'))
	{
		*mode = 1;
		return (1);
	}

	return (0);
}
