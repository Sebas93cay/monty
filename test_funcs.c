#include "monty.h"

void print_words(char **words)
{
	if (words == NULL || *words == NULL)
	{
		printf("There are no words to print\n");
		return;
	}
	while (*words)
	{
		printf("-> %s\n", *words);
		words++;
	}
}
