#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

int there_are_numbers_bigger_than_the_middle(t_node *stack_a, int middle)
{
  while(stack_a != NULL)
  {
    if (stack_a->rank > middle)
      return(1);
    stack_a = stack_a->next;
  }
  return (0);
}
void move_them_over_to_stack_b(t_node ** stack_a, t_node **stack_b, int middle, t_oplist **op)
{
  t_node *a;
  t_node *b;
  t_node *target;

  a = *stack_a;
  b = *stack_b;
  if (a->rank > middle)
    pb(&a,&b, op);
  if (find_next_to_push(&a, &target, middle))
    best_move(a,b, target, op);
  while (a->rank > middle)
    pb(&a, &b, op);
  if (find_next_to_push(&a, &target, middle))
    best_move(a, b,target, op);
}

void best_move (t_node *stack_a, t_node *stack_b, t_node *target, t_oplist **op)
{
  t_node *a;
  t_node *b;
  int    rotate;

  a = stack_a;
  b = stack_b;
  if(target->distance_to_top < target->distance_to_bottom)
    rotate = 1;
  else
    rotate = -1;
  while (a->rank != target->rank)
  {
    if (a->rank < (a->next)->rank) && (a->rank > middle) && target->rank != (a->next)->rank)
    swap(a);
    else
      rotate_stacka(rotate, stack_a, op);
  }
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
  return ;
}

void rotate_stacka(int rotate, t_node ** stack, t_oplist **op)
{
  if (rotate > 0)
    ra(stack, op);
  else
    rra(stack, op);
}

void rotate_stackb(int rotate, t_node ** stack, t_oplist **op)
{
  if (rotate > 0)
    rrb(stack, op);
  else
    rb(stack, op);
}

void sort_both_stacks(t_node **stack_a, t_node **stack_b, int  middle, t_oplist op)
{
  t_oplist op_a;
  t_oplist op_b;
  t_node *a;
  t_node *b;

  a = *stack_a;
  b = *stack_b;
  while ((a->rank > (a->next)->rank) && (b->rank > (b->next)->rank))
  {
    if ((a->rank > (a->next)->rank) && target->rank != (a->next)->rank))
    swap(&a, &op_a);
    else
      rotate_stacka(rotate, &a, &op_a);
    if (b->rank > (b->next)->rank) && target->rank != (b->next)->rank)
    swap(&b, &op_b);
    else
      rotate_stackb(rotate, &b, &op_b);
}
