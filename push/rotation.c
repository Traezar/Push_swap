#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void rotate_stacka(int rotate, t_node ** stack, t_oplist **op)
{
  if (rotate > 0)
  while(rotate-- != 0)
    ra(stack, op);
  else
  while(rotate++ != 0)
    rra(stack, op);
}

void rotate_stackb(int rotate, t_node ** stack, t_oplist **op)
{
  if (rotate > 0)
  while(rotate-- != 0)
    rrb(stack, op);
  else
  while(rotate++ != 0)
    rb(stack, op);
}

int find_next_to_push (t_node **a,t_node **target,int middle)
{
  t_node *front;
  t_node *back;

  front = *a;
  back  = *a;
  while(front->next != NULL)
  {
    if(front->rank > middle)
    break;
    front = front->next;
  }
  while(back->next != NULL)
  {
    if(back->rank > middle)
    *target = back;
    back = back->next;
  }
  if (front->distance_to_bottom > back->distance_to_top)
    *target = front;
  if(target == NULL)
    return (0);
  return (1);
}

int get_direction(t_node **head)
{
  int count;
  t_node *node;

  node = *head;
  ft_printf("the current length of the chain before 1st rotation is : %d\n", get_chain_size(node));
  count = rotations_to_a_swap_ascending(node, 0);
  ft_printf("the count is : %d\n", count);
  ft_printf("the current length of the chain after 1st rotation is : %d\n", get_chain_size(node));
  reverse_stack_order(&node);
  ft_printf("the current length of the chain after in get direction after first reversal is : %d\n", get_chain_size(node));
  ft_printf("the current length of the chain before 2nd rotation is : %d\n", get_chain_size(node));
  count = count - rotations_to_a_swap_descending(node, 0);
  ft_printf("the count is : %d\n", count);
  ft_printf("the current length of the chain before 2nd rotation is : %d\n", get_chain_size(node));
  reverse_stack_order(&node);
  ft_printf("the current length of the chain after in get direction after second reversal is : %d\n", get_chain_size(node));
  return (count);
}

int  rotations_to_a_swap_descending(t_node *node,int count)
{
    t_node *a;
    t_oplist *op;
    int size;

    a = node;
    op = NULL;
    size = get_chain_size(a);
    while(a->next != NULL)
    {
      if (rotate_or_swap_descending(a->rank, ((a->next)->rank), size) && count != size)
      {
        count++;
        a = a->next;
      }
      else
      break;
    }
    return (count);
}

int  rotations_to_a_swap_ascending(t_node *node, int count)
{
    t_node *a;
    t_oplist *op;
    int size;

    a = node;
    op = NULL;
    size = get_chain_size(a);
    while(a->next != NULL)
    {
      if (rotate_or_swap_ascending(a->rank, ((a->next)->rank), size ) && count != size)
      {
        count++;
        a = a->next;
      }
      else
      break;
    }
    return (count);
}
int get_chain_size(t_node *a)
{
  int count;

  count = 0;
  while (a != NULL)
  {
    count++;
    a=a->next;
  }
  return (count);
}
