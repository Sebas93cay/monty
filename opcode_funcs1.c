#include "monty.h"

/**
 * push_stack - pushes an element to the stack.
 * @stack: pointer to pointer to stack
 * @line_number: line number from file where opcode is
 * Return: nothing
 */
void push_stack(stack_t **stack, unsigned int line_number)
{
	if (STK.tokens[1] == NULL || check_if_number(STK.tokens[1]) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	switch (STK.mode)
	{
	case STACK_MODE:
		add_dnodeint(stack, atoi(STK.tokens[1]));
		break;
	case QUEUE_MODE:
		add_dnodeint_end(stack, atoi(STK.tokens[1]));
		break;
	}
}

/**
 * pall_stack - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: pointer to pointer to stack
 * @line_number: line number from file where opcode is
 * Return: nothing
 */
void pall_stack(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	print_dlistint(*stack);
	/* print_dlistint_rev(*stack); */
}

/**
 * pint_stack -  prints the value at the top of the stack,
 * followed by a new line.
 * @stack: pointer to pointer to stack
 * @line_number: line number from file where opcode is
 * Return: nothing
 */
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

/**
 * pop_stack - removes the top element of the stack.
 * @stack: pointer to pointer to stack
 * @line_number: line number from file where opcode is
 * Return: nothing
 */
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

/**
 * swaps_stack - swaps the top two elements of the stack.
 * @stack: pointer to pointer to stack
 * @line_number: line number from file where opcode is
 * Return: nothing
 */
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
	if ((*stack)->next)
		(*stack)->next->prev = (*stack);
	(*stack)->prev = tmp_node;
	tmp_node->next = (*stack);
	tmp_node->prev = NULL;
	(*stack) = tmp_node;
}
