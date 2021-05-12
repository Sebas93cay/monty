#include "monty.h"

/**
 * print_dlistint - print a dlistint list
 * @h: list
 * Return: returns size of the list
 */
size_t print_dlistint(const stack_t *h)
{
	int nodes_count = 0;

	if (h != NULL)
	{
		while (h != NULL)
		{
			nodes_count++;
			printf("%d\n", h->n);
			h = h->next;
		}
		/* printf("cantidad de nodos : %d\n", nodes_count); */
		return (nodes_count);
	}
	return (0);
}

/**
 * dlistint_len - returns the length of a linked list h
 * @h: list
 * Return: returns the size of h
*/
size_t dlistint_len(const stack_t *h)
{
	int nodes_count = 0;

	if (h != NULL)
	{
		while (h != NULL)
		{
			nodes_count++;
			h = h->next;
		}
		return (nodes_count);
	}
	return (0);
}


/**
 * add_dnodeint - adds a new node at the beginning of a stack_t list.
 * @head: list
 * @n: number
 * Return: the address of the new element, or NULL if it failed
*/
stack_t *add_dnodeint(stack_t **head, unsigned int n)
{
	stack_t *newnode, *h;


	if (head == NULL)
		return (NULL);

	h = *head;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = h;
	if (head != NULL && *head != NULL)
		(*head)->prev = newnode;

	(*head) = newnode;

	return (newnode);
}

/**
 * add_dnodeint_end - adds a new node at the end of a stack_t list.
 * @head: list
 * @n: number
 * Return: the address of the new element, or NULL if it failed
*/
stack_t *add_dnodeint_end(stack_t **head, unsigned int n)
{
	stack_t *newnode, *h;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		return (0);
	newnode->n = n;
	newnode->next = NULL;

	if (head == NULL || *head == NULL)
	{
		newnode->prev = NULL;
		*head = newnode;
		return (newnode);
	}

	h = *head;
	while (h->next != NULL)
		h = h->next;

	newnode->prev = h;
	h->next = newnode;
	return (newnode);
}

/**
 * free_dlistint - frees a stack_t list.
 * @head: list
 * Return: nothing
*/
void free_dlistint(stack_t *head)
{
	if (head == NULL)
		return;

	if (head->next != NULL)
		free_dlistint(head->next);

	free(head);
}
