#include "monty.h"

void mod_stack(stack_t **stack, unsigned int line_number)
{
	if (dlistint_len(STK.stack) < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
		return;
	}
	(*stack)->next->n %= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}

void pchar_stack(stack_t **stack,
		 unsigned int line_number)
{
	if (dlistint_len(STK.stack) < 1)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
		return;
	}
	if ((*stack)->n > 255)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);		
	}
	printf("%c\n", (*stack)->n);
	
}

void pstr_stack(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *node = NULL;

	node = *stack;
	while(node != NULL)
	{
		if (node->n >255 || node->n == 0)
			break;
		printf("%c", node->n);
		node = node->next;
	}
	printf("\n");
}

void rotl_stack(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *node = NULL;

	node = *stack;
	while(node->next != NULL)
		node = node->next;

	node->next = *stack;
	(*stack)->prev = node;
	(*stack) = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


void rotr_stack(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *node = NULL;

	node = *stack;
	while(node->next != NULL)
		node = node->next;

	node->next = (*stack);
	(*stack)->prev = node;
	(*stack) = node;
	node->prev->next = NULL;
	node->prev = NULL;
}
