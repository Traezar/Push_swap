/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:30:08 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/18 10:30:09 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../libft/includes/libft.h"

void exec_sa(t_stack **head_of_a, t_stack **head_of_b)
{
  t_stack *first;
  t_stack *second;

  (void)head_of_b;
  first = *head_of_a;
  second = (*head_of_a)->next;
  first = second->next;
  second->next = first;
  *head_of_a = second;
  return ;
}

void exec_sb(t_stack **head_of_a, t_stack **head_of_b)
{
  t_stack *first;
  t_stack *second;

  (void)head_of_a;
  first = *head_of_b;
  second = (*head_of_b)->next;
  first = second->next;
  second->next = first;
  *head_of_a = second;
  return ;
}

void exec_ss(t_stack **head_of_a, t_stack **head_of_b)
{
  exec_sa(head_of_a, head_of_b);
  exec_sb(head_of_a, head_of_b);
  return;
}

void exec_pa(t_stack **head_of_a, t_stack **head_of_b)
{
  t_stack *stack_a;
  t_stack *stack_b;

  stack_a = *head_of_a;
  stack_b = *head_of_b;
  if(stack_b == NULL)
    return ;
  *head_of_b = stack_b->next;
  stack_b->next = stack_a;
  *head_of_a = stack_b;
  return;

}

void exec_pb(t_stack **head_of_a, t_stack **head_of_b)
{
  t_stack *stack_a;
  t_stack *stack_b;

  stack_a = *head_of_a;
  stack_b = *head_of_b;
  if(stack_a == NULL)
    return ;
  *head_of_a = stack_a->next;
  stack_a->next = stack_b;
  *head_of_b = stack_a;
  return;

}

void exec_ra(t_stack **head_of_a, t_stack **head_of_b)
{
  t_stack *stack_a;
  t_stack *stack_b;
  t_stack *ptr_to_node_being_moved;

  stack_a = *head_of_a;
  stack_b = *head_of_b;
  ptr_to_node_being_moved = stack_a;
  *head_of_a = stack_a->next;
  push_back_stack(head_of_a , &ptr_to_node_being_moved);
  return ;
}

void exec_rb(t_stack **head_of_a, t_stack **head_of_b)
{
  t_stack *stack_a;
  t_stack *stack_b;
  t_stack *ptr_to_node_being_moved;

  stack_a = *head_of_a;
  stack_b = *head_of_b;
  ptr_to_node_being_moved = stack_b;
  *head_of_b = stack_b->next;
  push_back_stack(head_of_b , &ptr_to_node_being_moved);
  return ;
}

void exec_rr(t_stack **head_of_a, t_stack **head_of_b)
{
  exec_ra(head_of_a, head_of_b);
  exec_rb(head_of_a, head_of_b);
  return ;
}

void exec_rra(t_stack **head_of_a, t_stack **head_of_b)
{
  t_stack *stack_a;
  t_stack *stack_b;
  t_stack *ptr_to_previous;

  stack_a = *head_of_a;
  stack_b = *head_of_b;
  if(stack_a == NULL)
    return ;
  if((stack_a->next) == NULL)
    return ;
  while (stack_a->next != NULL)
  {
    ptr_to_previous = stack_a;
    stack_a = stack_a->next;
  }
  ptr_to_previous->next = NULL;
  push_front_stack(head_of_a, &stack_a);
  return;
}

void exec_rrb(t_stack **head_of_a, t_stack **head_of_b)
{
  t_stack *stack_a;
  t_stack *stack_b;
  t_stack *ptr_to_previous;

  stack_a = *head_of_a;
  stack_b = *head_of_b;
  if(stack_b == NULL)
    return ;
  if((stack_b->next) == NULL)
    return ;
  while (stack_b->next != NULL)
  {
    ptr_to_previous = stack_b;
    stack_b = stack_b->next;
  }
  ptr_to_previous->next = NULL;
  push_front_stack(head_of_b ,&stack_b);
  return;
}

void exec_rrr(t_stack **head_of_a, t_stack **head_of_b)
{
  exec_rra(head_of_a, head_of_b);
  exec_rrb(head_of_a, head_of_b);
  return ;
}
