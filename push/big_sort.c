#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void sort_big(t_node **head_of_a, t_node **head_of_b, t_oplist **op_list,int size)
{
  t_node *a;
  t_node *b;
  t_oplist *op;
  int i;

  a = *head_of_a;
  b = *head_of_b;
  op = *op_list;
  i  = 0;
  ft_printf("\n**************************************\n");
  debug_print_state(&a, &b, &op);
  ft_printf("\n^^^^^^^^^^^STACK BEFORE SORT^^^^^^^^^ \n");
  recur_a(&a, &b, &op, size);
  ft_printf("exited Big Sort Loop\n");
  *head_of_a = a;
  *head_of_b = b;
  *op_list = op;
}

void recur_a(t_node **head_of_a, t_node **head_of_b, t_oplist **op_list,int max)
{
  t_node *a;
  t_node *b;
  t_oplist *op;
  int i;
  int middle;

  a = *head_of_a;
  b = *head_of_b;
  op = *op_list;
  i  = 0;
  middle = max / 2;
  debug_print_state(&a, &b, &op);
  if (middle > 1 && a  && a->next)
  {
      while(i < middle && a->next)
      {
        if (a->rank <= middle)
        {
          pb(&a, &b, &op);
          i++;
        }
        else
        ra(&a, &op);
         if (a->rank > a->next->rank && !(a->rank <= middle) && !(a->next->rank <= middle))
        sa(&a, &op);
      }
      recur_a(&a, &b, &op, middle);
      ft_printf("\nprint state before going into B\n");
      debug_print_state(&a, &b, &op);
      recur_b(&a, &b, &op, middle);
      while(i-- != 0)
        pa(&a, &b, &op);
  }
  else if (middle == 1 && (a->rank > a->next->rank))
    sa(&a, &op);
  *head_of_a = a;
  *head_of_b = b;
  *op_list = op;
  ft_printf("Number of Numbers pushed:%i\n", i);
}

void recur_b(t_node **head_of_a, t_node **head_of_b, t_oplist **op_list,int middle)
{
  t_node *a;
  t_node *b;
  t_oplist *op;
  int i;

  a = *head_of_a;
  b = *head_of_b;
  op = *op_list;
  i  = 0;
  middle = middle / 2;
  debug_print_state(&a, &b, &op);
  if (middle > 1 && a  && a->next)
  {
      while(i < middle && a->next)
      {
        if (a->rank > middle)
        {
          pa(&a, &b, &op);
          i++;
        }
        else
        rb(&b, &op);
        if (a->next && a->rank > a->next->rank)
        sa(&a, &op);
        else if (b->next && b->rank < b->next->rank)
        sb(&a, &op);
      }
      recur_a(&a, &b, &op, middle);
      ft_printf("\nprint state before going into B\n");
      debug_print_state(&a, &b, &op);
      recur_b(&a, &b, &op, middle);
      while(i-- != 0)
        pb(&a, &b, &op);
  }
  *head_of_a = a;
  *head_of_b = b;
  *op_list = op;
  ft_printf("Number of Numbers pushed:%i\n", i);
}
