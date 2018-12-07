/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:15:41 by rsathiad          #+#    #+#             */
/*   Updated: 2018/12/06 15:15:43 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void sa(t_node **head_of_a,  t_oplist **op)
{
  t_node *first;
  t_node *second;

  first = *head_of_a;
  second = (*head_of_a)->next;
  first = second->next;
  second->next = first;
  *head_of_a = second;
  print_to_oplist("sa",op);
  return ;
}

void sb(t_node **head_of_b, t_oplist **op)
{
  t_node *first;
  t_node *second;

  first = *head_of_b;
  second = (*head_of_b)->next;
  first = second->next;
  second->next = first;
  *head_of_b = second;
  print_to_oplist("sb",op);
  return ;
}

void ss(t_node **head_of_a, t_node **head_of_b, t_oplist **op_a , t_oplist **op_b)
{
  sa(head_of_a, op_a);
  sb(head_of_b, op_b);
  return;
}

void pa(t_node **head_of_a, t_node **head_of_b, t_oplist **op)
{
  t_node *node_a;
  t_node *node_b;

  node_a = *head_of_a;
  node_b = *head_of_b;
  if(node_b == NULL)
    return ;
  *head_of_b = node_b->next;
  node_b->next = node_a;
  *head_of_a = node_b;
  print_to_oplist("pa",op);
  return;

}

void pb(t_node **head_of_a, t_node **head_of_b, t_oplist **op)
{
  t_node *node_a;
  t_node *node_b;

  node_a = *head_of_a;
  node_b = *head_of_b;
  if(node_a == NULL)
    return ;
  *head_of_a = node_a->next;
  node_a->next = node_b;
  *head_of_b = node_a;
  print_to_oplist("pb",op);
  return;

}

void ra(t_node **head_of_a, t_oplist **op)
{
  t_node *node_a;
  t_node *ptr_to_node_being_moved;

  node_a = *head_of_a;
  ptr_to_node_being_moved = node_a;
  *head_of_a = node_a->next;
  push_back_node(head_of_a , &ptr_to_node_being_moved);
  print_to_oplist("ra",op);
  return ;
}

void rb(t_node **head_of_b, t_oplist **op)
{
  t_node *node_b;
  t_node *ptr_to_node_being_moved;

  node_b = *head_of_b;
  ptr_to_node_being_moved = node_b;
  *head_of_b = node_b->next;
  push_back_node(head_of_b , &ptr_to_node_being_moved);
  print_to_oplist("rb",op);
  return ;
}

void rr(t_node **head_of_a, t_node **head_of_b, t_oplist **op_a , t_oplist **op_b)
{
  ra(head_of_a, op_a);
  rb(head_of_b, op_b);
  return ;
}

void rra(t_node **head_of_a, t_oplist **op)
{
  t_node *node_a;
  t_node *ptr_to_previous;

  node_a = *head_of_a;
  if(node_a == NULL)
    return ;
  if((node_a->next) == NULL)
    return ;
  while (node_a->next != NULL)
  {
    ptr_to_previous = node_a;
    node_a = node_a->next;
  }
  ptr_to_previous->next = NULL;
  push_front_node(head_of_a, &node_a);
  print_to_oplist("rra",op);
  return;
}

void rrb(t_node **head_of_b, t_oplist **op)
{
  t_node *node_b;
  t_node *ptr_to_previous;

  node_b = *head_of_b;
  if(node_b == NULL)
    return ;
  if((node_b->next) == NULL)
    return ;
  while (node_b->next != NULL)
  {
    ptr_to_previous = node_b;
    node_b = node_b->next;
  }
  ptr_to_previous->next = NULL;
  push_front_node(head_of_b ,&node_b);
  print_to_oplist("rrb",op);
  return;
}

void rrr(t_node **head_of_a, t_node **head_of_b, t_oplist **op_a , t_oplist **op_b)
{
  rra(head_of_a, op_a);
  rrb(head_of_b, op_b);
  return ;
}
