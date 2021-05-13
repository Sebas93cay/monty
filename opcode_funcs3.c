#include "monty.h"

/**
 * mod_stack - computes the rest of the division of the
 *  second top element of the stack by the top element
 * of the stack.
 * @stack: pointer to pointer to stack
 * @line_number: line number from file where opcode is
 * Return: nothing
 */
void mod_stack(stack_t **stack, unsigned int line_number)
{
	if (dlistint_len(STK.stack) < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}

/**
 * pchar_stack -  prints the char at the top of the stack,
 * followed by a new line.
 * @stack: pointer to pointer to stack
 * @line_number: line number from file where opcode is
 * Return: nothing
 */
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
	if ((*stack)->n < 32 || (*stack)->n > 126)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr_stack - prints the string starting at the top
 * of the stack, followed by a new line.
 * The string stops when either:
 * -the stack is over
 * -the value of the element is 0
 * -the value of the element is not in the ascii table
 * @stack: pointer to pointer to stack
 * @line_number: line number from file where opcode is
 * Return: nothing
 */
void pstr_stack(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *node = NULL;

	node = *stack;
	while (node != NULL)
	{
		if (node->n < 32 || node->n > 126 || node->n == 0)
			break;
		printf("%c", node->n);
		node = node->next;
	}
	printf("\n");
}

/**
 * rotl_stack - The top element of the stack becomes
 * the last one, and the second top element of the
 * stack becomes the first one
 * @stack: pointer to pointer to stack
 * @line_number: line number from file where opcode is
 * Return: nothing
 */
void rotl_stack(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *node = NULL;

	node = *stack;
	while (node->next != NULL)
		node = node->next;

	node->next = *stack;
	(*stack)->prev = node;
	(*stack) = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr_stack - The last element of the stack
 * becomes the top element of the stack
 * @stack: pointer to pointer to stack
 * @line_number: line number from file where opcode is
 * Return: nothing
 */
void rotr_stack(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *node = NULL;

	node = *stack;
	while (node->next != NULL)
		node = node->next;

	node->next = (*stack);
	(*stack)->prev = node;
	(*stack) = node;
	node->prev->next = NULL;
	node->prev = NULL;
}
