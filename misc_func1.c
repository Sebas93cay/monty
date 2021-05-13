#include "monty.h"

/**
 * trav_opcodes - look for a matching opcode in structure
 * codes, for the first word in STK.tokens
 * if a matching opcode is found, the corresponding function
 * from structure code is executed.
 * if no matching opcode is found, an error message is printed
 * @codes: structure with opcodes and its respective fucntions
 * @line_counter: line number from file
 * Return: Nothing
*/
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
		fprintf(stderr, "L%u: unknown instruction %s\n",
			line_counter, STK.tokens[0]);
		free_stuff();
		exit(EXIT_FAILURE);
	}
}

/**
 * check_if_number - check if a string is composed only by
 * numbers
 * @str: string
 * Return: Return 1 if string is composed only by numbers,
 * 0 otherwise
 */
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

/**
 * remove_newline - if last byte in str is '\n', this is
 * substitured for '\0'
 * @str: string
 * Return: nothing
 */
void remove_newline(char *str)
{
	int len;

	len = _strlen(str);
	if (len == 0)
		return;
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
}

/**
 * free_words - frees an array of strings
 * @words: array of strings
 * Return: nothing
 */
void free_words(char **words)
{
	int i = 0;

	if (words == NULL)
		return;

	for (i = 0; words[i]; i++)
		free(words[i]);
	free(words);
}
