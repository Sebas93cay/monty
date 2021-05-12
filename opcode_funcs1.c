#include "monty.h"

void push_stack(stack_t **stack, unsigned int line_number)
{
	
	if (STK.tokens[1] == NULL || check_if_number(STK.tokens[1]) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	add_dnodeint(stack, atoi(STK.tokens[1]));
}

void pall_stack(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	print_dlistint(*stack);
}

void pint_stack(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	if (dlistint_len(STK.stack) < 1)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
		return;
	}
	printf("%d\n", (*stack)->n);
	
}

void pop_stack(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	if (dlistint_len(STK.stack) < 1)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
		return;
	}
	delete_dnodeint_at_index(stack, 0);
}

void swap_stack(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp_node = NULL;

	if (dlistint_len(STK.stack) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
		return;
	}
	tmp_node = (*stack)->next;
	(*stack)->next = tmp_node->next;
	(*stack)->next->prev = (*stack);
	(*stack)->prev = tmp_node;
	tmp_node->next = (*stack);
	tmp_node->prev = NULL;
	(*stack) = tmp_node;
}
