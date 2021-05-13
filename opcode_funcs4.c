#include "monty.h"

/**
 * stack_stack - sets the format of the data to a stack
 * (LIFO). This is the default behavior of the program.
 * @stack: pointer to pointer to stack
 * @line_number: line number from file where opcode is
 * Return: nothing
 */

void stack_stack(__attribute__((unused)) stack_t **stack,
		 __attribute__((unused)) unsigned int line_number)
{
	STK.mode = STACK_MODE;
}


/**
 * queue_stack - sets the format of the data to a
 * queue (FIFO).
 * @stack: pointer to pointer to stack
 * @line_number: line number from file where opcode is
 * Return: nothing
 */
void queue_stack(__attribute__((unused)) stack_t **stack,
		 __attribute__((unused)) unsigned int line_number)
{
	STK.mode = QUEUE_MODE;
}

