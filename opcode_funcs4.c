#include "monty.h"

void stack_stack(__attribute__((unused)) stack_t **stack,
		 __attribute__((unused)) unsigned int line_number)
{
	STK.mode = STACK_MODE;
}


void queue_stack(__attribute__((unused)) stack_t **stack,
		 __attribute__((unused)) unsigned int line_number)
{
	STK.mode = QUEUE_MODE;
}

