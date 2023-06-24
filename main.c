#include "monty.h"

int error = 0;

/**
 * main - the main function.
 * @ac: arguments number.
 * @av: arguments vector.
 * Return: int.
 */
int main(int ac, char **av)
{
	FILE *fp;
	char *line = NULL;
	size_t size = 0;
	ssize_t len;
	stack_t *head = NULL;
	int line_number = 0;
	int mode = 0;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((len = getline(&line, &size, fp)) != -1)
	{
		line_number++;
		treat_line(&head, fp, line, line_number, &mode);
	}
	free_list(&head, fp, line);
	exit(EXIT_SUCCESS);
}
