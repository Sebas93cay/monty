#include "monty.h"

/**
 * add_stack - adds the top two elements of the stack.
 * @stack: pointer to pointer to stack
 * @line_number: line number from file where opcode is
 * Return: nothing
 */
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

/**
 * nop_stack - this functios does nothing
 * @stack: pointer to pointer to stack
 * @line_number: line number from file where opcode is
 * Return: nothing
 */
void nop_stack(__attribute__((unused)) stack_t **stack,
	       __attribute__((unused))  unsigned int line_number)
{}

/**
 * sub_stack - subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: pointer to pointer to stack
 * @line_number: line number from file where opcode is
 * Return: nothing
 */
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

/**
 * div_stack - divides the second top element of the
 * stack by the top element of the stack.
 * @stack: pointer to pointer to stack
 * @line_number: line number from file where opcode is
 * Return: nothing
 */
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

/**
 * mul_stack - multiplies the second top element of
 * the stack with the top element of the stack.
 * @stack: pointer to pointer to stack
 * @line_number: line number from file where opcode is
 * Return: nothing
 */
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

