#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void sort_big(t_node **head_of_a, t_node **head_of_b, t_oplist **op,int max);
{
  t_node *a;
  t_node *b;
  int mask;
  int e;

  mask = 1;
  //e = get_tranches(max)
  a = *head_of_a;
  b = *head_of_b;
  i  = 0;
  max = max/2
  while(i < max)
  {
    if (a->rank < max)
    {
      pb(&a, &b, &op);
      i++;
    }
    else
      ra(&a, &op);
  }
  align_stacks (&a, &b, &op, max);
  sort_both_stacks(&a, &b, &op);
}

int get_tranches(int max)
{

  int i;

  i = 0;
  while ( max != 0)
   {
     max = max >> 1;
     i++;
   }
   return (i);
}

int find_best_move(t_node **stack_a, int target)
{
  int db;
  int dt;
  t_node *a;

  a =  stack_a;
  dt = 0;
  db = get_chain_size(a);
  while (a->next != NULL)
  {
    dt++;
    db--;
    a = a->next;
  }
  if (db < dt)
    return (-1);
  return (1);
}

void align_stacks(t_node **stack_a, t_node **stack_b, t_node **op, int mid);
{
  t_node *a;
  t_node *b;
  int move;

  a = *stack_a;
  b = *stack_b;
  move = find_best_move(&a, mid);
  while(a->rank != (max - check))
  {
    if(move > 0;)
    ra(&a,&op);
    else
      rra(&a, &op);
  }
  move = find_best_move(&b, (mid + 1));
  while(b->rank != (mid + 1))
  {
    if(move > 0;)
    rb(&a,&op);
    else
      rrb(&a, &op);
  }
  return ;



}
