#ifndef MONTY_H

#define MONTY_H

/* Included libraries */
#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct stack_instance
{
	stack_t *stack;
	char **tokens;
	char *line;
	FILE *file;
	int mode;
} stack_instance;


/* GLobal instance for stack*/
extern stack_instance STK;



/* Macros */
#define STACK_MODE 0
#define QUEUE_MODE 1


/*In main file*/
char **splitwords(char *buff, char token);
void check_malloc(void *p);
void free_stuff();

/*opcode_funcs1.c*/
void push_stack(stack_t **stack, unsigned int line_number);
void pall_stack(stack_t **stack, unsigned int line_number);
void pint_stack(stack_t **stack, unsigned int line_number);
void pop_stack(stack_t **stack, unsigned int line_number);
void swap_stack(stack_t **stack, unsigned int line_number);
/*opcode_funcs2.c*/
void add_stack(stack_t **stack, unsigned int line_number);
void nop_stack(stack_t **stack, unsigned int line_number);
void sub_stack(stack_t **stack, unsigned int line_number);
void div_stack(stack_t **stack, unsigned int line_number);
void mul_stack(stack_t **stack, unsigned int line_number);
/*opcode_funcs3.c*/
void mod_stack(stack_t **stack, unsigned int line_number);
void pchar_stack(stack_t **stack, unsigned int line_number);
void pstr_stack(stack_t **stack, unsigned int line_number);
void rotl_stack(stack_t **stack, unsigned int line_number);
void rotr_stack(stack_t **stack, unsigned int line_number);
/*opcode_funcs3.c*/
void stack_stack(stack_t **stack, unsigned int line_number);
void queue_stack(stack_t **stack, unsigned int line_number);


/*misc functions*/
void trav_opcodes(instruction_t *codes, unsigned int line_counter);
int check_if_number(char *str);
void remove_newline(char *str);

void free_words(char **words);
/*str1. c   string functions*/
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, unsigned int n);

/*lists_1.c doublelinkedlist Functions */
size_t print_dlistint(const stack_t *h);
size_t dlistint_len(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, unsigned int n);
stack_t *add_dnodeint_end(stack_t **head, unsigned int n);
void free_dlistint(stack_t *head);
/*lists_2.c doublelinkedlist Functions */
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
size_t print_dlistint_rev(const stack_t *h);

/*test_func.c*/
void print_words(char **words);



#endif
