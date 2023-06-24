#include "monty.h"

/**
 * treat_token - function that treats a token.
 * check if it's valid and has the necessary args
 * or if it's invalid.
 * @head: linked list's head address.
 * @fp: file pointer.
 * @line: line we're reading.
 * @token: token to check.
 * @line_number: line number.
 * @mode: 0 if stack, 1 if queue
 * Return: nothing.
 */
void treat_token(stack_t **head, FILE *fp, char *line,
char *token, unsigned int line_number, int *mode)
{
	char *push_arg;
	void (*f)(stack_t **head, unsigned int line_number);

	if (!strncmp("push", token, 4) && (token[4] == '\0'))
	{
		push_arg = check_push_arg(token, line_number);
		if (push_arg != 0)
		{
			_push(head, line_number, push_arg, mode);
			if (error == 1)
			{
				free_list(head, fp, line);
				exit(EXIT_FAILURE);
			}
			return;
		}
		else
		{
			free_list(head, fp, line);
			exit(EXIT_FAILURE);
		}
	}
	f = get_function(token);
	if (!f)
	{
		get_invalid_opcode(token, line_number);
		if (error == 1)
		{
			free_list(head, fp, line);
			exit(EXIT_FAILURE);
		}
	}
	f(head, line_number);
	if (error == 1)
	{
		free_list(head, fp, line);
		exit(EXIT_FAILURE);
	}
}

/**
 * get_function - returns the right function for the correponding function
 * for the given token.
 * @token: token to get its corresponding function.
 * Return: the right function for the given token.
 */
void (*get_function(char *token))(stack_t **, unsigned int)
{
	int i;
	instruction_t ops[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	if (token[0] == '#')
		return (_nop);

	for (i = 0; ops[i].opcode; i++)
	{
		if (
				!strncmp(token, ops[i].opcode, strlen(ops[i].opcode)) &&
				(token[strlen(ops[i].opcode)] == '\0')
		   )
			return (ops[i].f);
	}

	return (NULL);
}

/**
 * get_invalid_opcode - function to malloc invalid command and display
 * its corresponding error.
 * @token: invalid command (or opcode).
 * @line_number: line number.
 * Return: nothing.
 */
void get_invalid_opcode(char *token, unsigned int line_number)
{
	int i, len = 0;
	char *invalid_opcode;

	for (
		len = 0;
		(token[len] != '\0' && token[len] != ' ' && token[len] != '\n');
	     len++)
		;
	invalid_opcode = malloc(sizeof(char) * (len));
	if (!invalid_opcode)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		error = 1;
		return;
	}
	for (i = 0; i < len; i++)
		invalid_opcode[i] = token[i];
	dprintf(STDERR_FILENO,
			"L%d: unknown instruction %s\n",
			line_number, invalid_opcode);
	free(invalid_opcode);
	error = 1;
}
