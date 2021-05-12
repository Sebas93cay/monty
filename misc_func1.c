#include "monty.h"

void trav_opcodes(instruction_t *codes, unsigned int line_counter)
{
	int i = 0, sucess = 0;

	for (i = 0; codes[i].opcode; i++)
	{
		if (_strcmp(codes[i].opcode, STK.tokens[0]) == 0)
		{
			codes[i].f(&(STK.stack), line_counter);
			sucess = 1;
			break;
		}
	}
	if (sucess == 0 && STK.tokens[0] != NULL)
	{
		dprintf(2, "L%u: unknown instruction %s\n",
			line_counter, STK.tokens[0]);
		free_stuff();
		exit(EXIT_FAILURE);
	}
}

int check_if_number(char *str)
{
	if (str == NULL)
		return (0);
	for (; *str; str++)
	{
		if (*str < '0' || *str > '9')
			return (0);
	}
	return (1);
}

void remove_newline(char *str)
{
	int len;

	len = _strlen(str);
	if (len == 0)
		return;
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
}

void free_words(char **words)
{
	int i = 0;

	if (words == NULL)
		return;

	for (i = 0; words[i]; i++)
		free(words[i]);
	free(words);
}
