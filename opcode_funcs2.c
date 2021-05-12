#include "monty.h"

void add_stack(stack_t **stack, unsigned int line_number)
{
	if (dlistint_len(STK.stack) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
		return;
	}
	(*stack)->next->n += (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}

void nop_stack(__attribute__((unused)) stack_t **stack,
	       __attribute__((unused))  unsigned int line_number)
{}

void sub_stack(stack_t **stack, unsigned int line_number)
{
	if (dlistint_len(STK.stack) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
		return;
	}
	(*stack)->next->n -= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}


void div_stack(stack_t **stack, unsigned int line_number)
{
	if (dlistint_len(STK.stack) < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
		return;		
	}
	(*stack)->next->n /= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}


void mul_stack(stack_t **stack, unsigned int line_number)
{
	if (dlistint_len(STK.stack) < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
		return;
	}
	(*stack)->next->n *= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}

