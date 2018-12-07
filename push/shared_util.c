/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:33:19 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/18 11:01:52 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void push_front_node(t_node **head_of_stack,t_node **ptr_to_node)
{
	t_node *stack;
	t_node *node;

	node = *ptr_to_node;
	stack = *head_of_stack;
	node->next = stack;
	*head_of_stack = node;
}

void push_back_stack(t_node **head_of_stack,t_node **ptr_to_node)
{
	t_node *stack;
	t_node *node;

	node = *ptr_to_node;
	stack = *head_of_stack;
	while (stack->next != NULL)
		stack = stack->next;
	stack->next = node;
	node->next = NULL;
}

t_node *extract_out_of_stack(t_node **head_of_stack,int node_with_this_value)
{
	t_node *stack;
	t_node *node_before_the_extracted;
	t_node *node_to_extract;

	node_to_extract = NULL;
	stack = *head_of_stack;
	node_before_the_extracted = *head_of_stack;
	while ((stack->value != node_with_this_value) && (stack->next != NULL))
	{
		node_before_the_extracted = stack;
		stack = stack->next;
	}
	if(stack->value == node_to_extract->value)
	{
		node_to_extract = stack;
		node_before_the_extracted = stack->next;
		stack->next = NULL;
	}
	else
		node_to_extract = NULL;
	return (node_to_extract);
}


void initialise_stack_a(t_node **head_of_a, char **int_array)
{
	t_node *new_stack_node;
	t_node *head_of_stack;
	int i;

	i = -1;
	head_of_stack = NULL;
	while(int_array[++i] != '\0')
	{
		new_stack_node = malloc(sizeof(t_node));
		new_stack_node->value = ft_atoi(int_array[i]);
		new_stack_node->next = head_of_stack;
		head_of_stack = new_stack_node;
	}
	reverse_stack_order(&head_of_stack);
	*head_of_a = head_of_stack;
}

void reverse_stack_order(t_node **head_of_stack)
{
	t_node *previous;
	t_node *current;
	t_node *next;

	if (*head_of_stack == NULL)
		return;
	if ((*head_of_stack)->next == NULL)
		return;
	current = *head_of_stack;
	previous = NULL;
		while (current != NULL)
     {
         next  = current->next;
         current->next = previous;
         previous = current;
         current = next;
     }
   *head_of_stack = previous;
}
