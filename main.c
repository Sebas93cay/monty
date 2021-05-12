#include "monty.h"

stack_instance STK;

int main(int argc, char **argv)
{
	size_t line_size = 0;
	unsigned int line_counter = 0;
	instruction_t codes[] = {{"push", push_stack},
				 {"pall", pall_stack},
				 {"pint", pint_stack},
				 {"pop", pop_stack},
				 {"swap", swap_stack},
				 {NULL, NULL}};
	STK.stack = NULL;
	STK.line = NULL;
	STK.tokens = NULL;
	STK.file = NULL;
		

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

	while (getline(&STK.line, &line_size, STK.file) > 0)
	{
		line_counter++;
		remove_newline(STK.line);
		free_words(STK.tokens);
		STK.tokens = splitwords(STK.line, ' ');
		/* print_words(STK.tokens); */
		if (STK.tokens != NULL)
			trav_opcodes(codes, line_counter);
	}
	/* print_dlistint(STK.stack); */
	free_stuff();
	return (0);
}




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
	if (wordcount > 0)
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



void check_malloc(void *p)
{
	if (p == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stuff();
		exit(EXIT_FAILURE);
	}
}

void free_stuff()
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
