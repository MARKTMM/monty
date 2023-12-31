#include "monty.h"

/**
 * _push - push new node to linked list
 * @head: linked list's head address
 * @line_number: memory alocation of the linked list's head
 * @arg: push's corresponding argument
 * @mode: 0 if stack and 1 if queue
 * Return: null
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
 * check_push_arg - check if push command has argument in it's line
 * @token: token corresponding the push's line
 * @line_number: number of line
 * Return: pointer to chara reping push's argument or NULL
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
 * get_usage_err - display error usage.
 * @line_number: number of line we are at
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
 * is_number - check if the push argument is a number or not.
 * @str: token that is retrieved after a found push command.
 * @line_number: number of line we are at
 * Return: num
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
