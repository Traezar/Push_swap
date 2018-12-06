#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void sa(t_node **head_of_a,  t_oplist **op)
{
  t_node *first;
  t_node *second;

  (void)head_of_b;
  first = *head_of_a;
  second = (*head_of_a)->next;
  first = second->next;
  second->next = first;
  *head_of_a = second;
  print_to_op("sa",op);
  return ;
}

void sb(t_node **head_of_b, t_oplist **op)
{
  t_node *first;
  t_node *second;

  (void)head_of_a;
  first = *head_of_b;
  second = (*head_of_b)->next;
  first = second->next;
  second->next = first;
  *head_of_a = second;
  print_to_op("sb",op);
  return ;
}

void ss(t_node **head_of_a, t_node **head_of_b, t_oplist **op)
{
  exec_sa(head_of_a, head_of_b);
  exec_sb(head_of_a, head_of_b);
  print_to_op("sa",op);
  print_to_op("sb",op);
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
  print_to_op("pa",op);
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
  print_to_op("pb",op);
  return;

}

void ra(t_node **head_of_a, t_oplist **op)
{
  t_node *node_a;
  t_node *node_b;
  t_node *ptr_to_node_being_moved;

  node_a = *head_of_a;
  node_b = *head_of_b;
  ptr_to_node_being_moved = node_a;
  *head_of_a = node_a->next;
  push_back_node(head_of_a , &ptr_to_node_being_moved, t_oplist **op);
  print_to_op("ra",op);
  return ;
}

void rb(t_node **head_of_b, t_oplist **op)
{
  t_node *node_a;
  t_node *node_b;
  t_node *ptr_to_node_being_moved;

  node_a = *head_of_a;
  node_b = *head_of_b;
  ptr_to_node_being_moved = node_b;
  *head_of_b = node_b->next;
  push_back_node(head_of_b , &ptr_to_node_being_moved, t_oplist **op);
  print_to_op("rb",op);
  return ;
}

void rr(t_node **head_of_a, t_node **head_of_b, t_oplist **op)
{
  ra(head_of_a, head_of_b);
  rb(head_of_a, head_of_b);
  print_to_op("ra",op);
  print_to_op("rb",op);
  return ;
}

void rra(t_node **head_of_a, t_oplist **op)
{
  t_node *node_a;
  t_node *node_b;
  t_node *ptr_to_previous;

  node_a = *head_of_a;
  node_b = *head_of_b;
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
  print_to_op("rra",op);
  return;
}

void rrb(t_node **head_of_a, t_oplist **op)
{
  t_node *node_a;
  t_node *node_b;
  t_node *ptr_to_previous;

  node_a = *head_of_a;
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
  print_to_op("rrb",op);
  return;
}

void rrr(t_node **head_of_a, t_node **head_of_b, t_oplist **op)
{
  rra(head_of_a, head_of_b);
  rrb(head_of_a, head_of_b);
  print_to_op("rra",op);
  print_to_op("rrb",op);
  return ;
}

void print_to_op(char *str, t_oplist **op)
{
  malloc new node;
  assign str to it ;
  pushback new node;
}
