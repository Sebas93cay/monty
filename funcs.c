#include "monty.h"

int check_if_num(char *str)
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
