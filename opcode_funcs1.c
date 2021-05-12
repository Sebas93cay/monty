#include "monty.h"

void push_stack(stack_t **stack, unsigned int line_number)
{
	
	if (STK.tokens[1] == NULL || check_if_number(STK.tokens[1]) == 0)
	{
		dprintf(2, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	add_dnodeint(stack, atoi(STK.tokens[1]));
}

void pall_stack(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	print_dlistint(*stack);
}
