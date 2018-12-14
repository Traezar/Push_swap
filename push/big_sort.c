#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void sort_big(t_node **head_of_a, t_node **head_of_b, t_oplist **op,int max)
{
  t_node *a;
  t_node *b;
  int mask;
  int i;

  mask = 1;
  //e = get_tranches(max)
  a = *head_of_a;
  b = *head_of_b;
  i  = 0;
  max = max/2;
  debug_print_state(&a, &b, op);
  while(i < (max) && a != NULL)
  {
    ft_printf("current rank of a:%i\n vlues of i:%i\n",a->rank , i);
    if (a->rank > (max))
    {

      pb(&a, &b, op);
      i++;
    }
    else
    {
      ft_printf("ra");
        ra(&a, op);
    }

  }
  ft_printf("exited LOOP");
  align_stacks (&a, &b, op, max);
  sort_both_stacks(&a, &b, op);
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

  a =  *stack_a;
  dt = 0;
  db = get_chain_size(a);
  while (a->next != NULL && a->rank != target)
  {
    dt++;
    db--;
    a = a->next;
  }
  if (db < dt)
    return (-1);
  return (1);
}

void align_stacks(t_node **stack_a, t_node **stack_b, t_oplist **op, int mid)
{
  t_node *a;
  t_node *b;
  int move;

  a = *stack_a;
  b = *stack_b;
  move = find_best_move(&a, mid);
  while(a->rank != mid)
  {
    ft_printf("finding the top for a");
    if(move > 0)
    ra(&a,op);
    else
      rra(&a, op);
  }
  move = find_best_move(&b, mid + 1 );
  while(b->rank != (mid + 1 ))
  {
    ft_printf("finding the top for b");
    if(move > 0)
    rb(&b,op);
    else
      rrb(&b, op);
  }
  ft_printf("exited align stacks");
  return ;



}
