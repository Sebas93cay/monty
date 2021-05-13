#include "monty.h"

/**
 * print_words - print the strings from the array of
 * strings words
 * @words: array of strings
 * Return: Nothing
*/
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
