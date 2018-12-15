#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void sort_big(t_node **head_of_a, t_node **head_of_b, t_oplist **op_list,int max)
{
  t_node *a;
  t_node *b;
  t_oplist *op;
  int i;

  a = *head_of_a;
  b = *head_of_b;
  op = *op_list;
  i  = 0;
  debug_print_state(&a, &b, &op);
  while(i < (max / 2) && a != NULL)
  {
    ft_printf("current rank of a:%i\n vlues of i:%i\n",a->rank , i);
    if (a->rank > (max/ 2))
    {

      pb(&a, &b, &op);
      i++;
    }
    else
        ra(&a, &op);
  }
  debug_print_state(&a, &b, &op);
  *head_of_a = a;
  *head_of_b = b;
  *op_list = op;
  ft_printf("exited LOOP");

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
