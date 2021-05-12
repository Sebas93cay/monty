#include "monty.h"

/**
 * delete_dnodeint_at_index - function that deletes the node at index
 * index of a dlistint_t linked list.
 * @head: list
 * @index: index to insert node
 * Return: Returns: 1 if it succeeded, -1 if it failed
*/
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	unsigned int idx = 0;
	stack_t *tmp_head = NULL, *tmp_node = NULL;

	if (head == NULL || *head == NULL)
		return (-1);

	tmp_head = *head;
	if (index == 0)
	{
		tmp_node = *head;
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		while (idx < index - 1)
		{
			if (tmp_head == NULL)
				return (-1);
			tmp_head = tmp_head->next;
			idx++;
		}
		tmp_node = tmp_head->next;
		tmp_head->next = tmp_node->next;
		if (tmp_head->next != NULL)
			tmp_head->next->prev = tmp_head;
	}
	free(tmp_node);
	return (1);
}
