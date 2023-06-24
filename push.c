#include "monty.h"

/**
 * _push - push new node to linked list.
 * @head: linked list's head address.
 * @line_number: the line number of the monty file that we're currently reading
 * @arg: the push's corresponding arg.
 * @mode: 0 if stack and 1 if queue.
 * Return: nothing.
 */
void _push(stack_t **head, unsigned int line_number, char *arg, int *mode)
{
	stack_t *new = NULL;
	int num = atoi(arg);

	(void)line_number;

	free(arg);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		error = 1;
		return;
	}
	new->n = num;
	if (*mode == 0)
		stack_push(head, &new);
	else
		enqueue(head, &new);

}

/**
 * check_push_arg - check if a push command has an arg in its line.
 * @token: token corresponding the push's line.
 * @line_number: line number.
 * Return: pointer to character representing the push's arg or NULL.
 */
char *check_push_arg(char *token, unsigned int line_number)
{
	char *token2;
	char *arg;
	int i, len;

	(void)token;

	token2 = strtok(NULL, " \n");

	while (token2 && token2[0] == ' ')
		token2 = strtok(NULL, " \n");

	if (!token2)
	{
		get_usage_err(line_number);
		return (NULL);
	}
	for (len = 0;
	     (token2[len] && token2[len] != '\n' && token2[len] != ' ');
	     len++)
		;

	arg = malloc(sizeof(char) * (len + 1));

	if (!arg)
	{
		get_usage_err(line_number);
		return (NULL);
	}

	for (i = 0; i < len; i++)
		arg[i] = token2[i];
	arg[i] = '\0';

	if (is_number(arg, line_number) == 1)
		return (NULL);
	return (arg);
}

/**
 * get_usage_err - displays usage error.
 * @line_number: line_number.
 */
void get_usage_err(unsigned int line_number)
{
		dprintf(
			STDERR_FILENO,
			"L%d: usage: push integer\n",
			line_number);
		error = 1;
}

/**
 * is_number - check if the push argument is a number of not
 * @str: the token that's retrieved after a found 'push' command.
 * @line_number: line number.
 * in a given line.
 * Return: int.
 */
int is_number(char *str, unsigned int line_number)
{
	int i = 0;

	if (!(str[i] >= 48 && str[i] <= 57) && str[i] != '-')
	{
		get_usage_err(line_number);
		return (1);
	}
	else
		i++;

	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
		{
			get_usage_err(line_number);
			return (1);
		}
	}
	return (0);
}
