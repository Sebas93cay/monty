#include "monty.h"

stack_instance STK;

/**
 * main - main function for monty project in holberton
 * @argc: argument count
 * @argv: array of arguments
 * Return: if an error is found, the program exits with
 * status EXIT_FAILURE, otherwise it returns cero
 */
int main(int argc, char **argv)
{
	size_t line_size = 0;
	unsigned int line_counter = 0;
	instruction_t codes[] = {{"push", push_stack}, {"pall", pall_stack},
				 {"pint", pint_stack}, {"pop", pop_stack},
				 {"swap", swap_stack}, {"add", add_stack},
				 {"nop", nop_stack}, {"sub", sub_stack},
				 {"div", div_stack}, {"mul", mul_stack},
				 {"mod", mod_stack}, {"pchar", pchar_stack},
				 {"pstr", pstr_stack}, {"rotl", rotl_stack},
				 {"rotr", rotr_stack}, {"stack", stack_stack},
				 {"queue", queue_stack}, {NULL, NULL}};
	STK.stack = NULL;
	STK.line = NULL;
	STK.tokens = NULL;
	STK.file = NULL;
	STK.mode = STACK_MODE;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	STK.file = fopen(argv[1], "r");
	if (STK.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[2]);
		free_stuff();
		exit(EXIT_FAILURE);
	}
	read_lines(&line_size, &line_counter, codes);
	free_stuff();
	return (0);
}


/**
 * read_lines - function reads all the line from STK.file
 * and look for opcodes follow instructions
 * @line_size: pointer size of malloqued buffer where the
 * line readed is storaged.
 * @line_counter: pointer to line from file.
 * @codes: structure with opcodes and its respective fucntions
 * Return: nothing
 */
void read_lines(size_t *line_size,
		unsigned int *line_counter,
		instruction_t *codes)
{

	while (getline(&STK.line, line_size, STK.file) > 0)
	{
		(*line_counter)++;
		remove_newline(STK.line);
		free_words(STK.tokens);
		STK.tokens = splitwords(STK.line, ' ');
		/* print_words(STK.tokens); */
		if (STK.tokens != NULL && STK.tokens[0][0] != '#')
		{
			trav_opcodes(codes, *line_counter);
		}
	}
}

/**
 * splitwords - split buffer into array of strings.
 * the separation is made from all pieces whiche are
 * separated from one or several chars token
 * @buff: buffer to split
 * @token: char
 * Return: array of strings.
 */
char **splitwords(char *buff, char token)
{
	int i, wordcount = 0, letters = 0;
	char **words = NULL;


	if (buff == NULL || *buff == 0)
		return (NULL);
	for (i = 0; buff[i]; i++)
	{
		if (buff[i] != token && (buff[i + 1] == token
			   || buff[i + 1] == '\0'))
			wordcount++;
	}
	if (wordcount == 0)
		return (words);

	words = malloc(sizeof(*words) * (wordcount + 1));
	check_malloc((void *)(words));
	i = 0;
	while (*buff && i < wordcount)
	{
		while (*buff == token)
			buff++;
		letters = 0;
		while (buff[letters] != 0 && buff[letters] != token)
			letters++;
		words[i] = malloc(sizeof(char) * (letters + 1));
		check_malloc((void *)(words[i]));
		_strncpy(words[i], buff, letters);
		words[i][letters] = '\0';
		buff += letters;
		i++;
	}
	words[i] = NULL;
	return (words);
}


/**
 * check_malloc - check if a just malloqued pointer is NULL.
 * if so, the program is stoped and it exit with value
 * EXIT_FAILURE
 * @p: just malloqued pointer
 * Return: nothing
 */
void check_malloc(void *p)
{
	if (p == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stuff();
		exit(EXIT_FAILURE);
	}
}

/**
 * free_stuff - free STK.stack, STK.line, STK.tokens
 * and STK.file if they were malloqued
 * Return: nothing
 */
void free_stuff(void)
{
	if (STK.stack != NULL)
	{
		free_dlistint(STK.stack);
		STK.stack = NULL;
	}
	if (STK.line != NULL)
	{
		free(STK.line);
		STK.line = NULL;
	}
	if (STK.tokens != NULL)
	{
		free_words(STK.tokens);
		STK.tokens = NULL;
	}
	if (STK.file != NULL)
	{
		fclose(STK.file);
		STK.file = NULL;
	}

}
