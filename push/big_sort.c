#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void sort_big(t_node **head_of_a, t_node **head_of_b, t_oplist **op_list,int middle)
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
  while(i <= (middle) && a != NULL)
  {
    ft_printf("Current rank of Number: %i\nNumber of Numbers pushed:%i\n",a->rank , i);
    if (a->rank >= (middle))
    {
      pb(&a, &b, &op);
      i++;
    }
    else
    ra(&a, &op);
  }
  recur_a(&a, &b, &op, middle);
  debug_print_state(&a, &b, &op);
  ft_printf("exited Big Sort Loop\n");
  *head_of_a = a;
  *head_of_b = b;
  *op_list = op;
}

void recur_a(t_node **head_of_a, t_node **head_of_b, t_oplist **op_list,int middle)
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
  if (a->rank < (middle) && (a->rank > a->next->rank) && middle == 1)
    sa(&a, &op);
  if (middle > 1 && a  && a->next)
  {
      while(i <= middle && b->next)
      {
        if (a->rank >= middle)
        {
          pb(&a, &b, &op);
          i++;
        }
        else
        ra(&a, &op);

      }
      recur_a(&a, &b, &op, middle);
      recur_b(&a, &b, &op, middle);
      while(i-- != 0)
        pa(&a, &b, &op);

  }


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
  if (b->rank > middle && (b->rank < b->next->rank) && middle == 1 && b->next)
    sb(&b, &op);
  if (middle > 1 && b && b->next)
  {
    while (i <= middle && b->next)
    {
      if (b->rank < middle)
      {
        pa(&a, &b, &op);
        i++;
      }
      else
      rb(&b, &op);
    }
    recur_a(&a, &b, &op, middle);
    recur_b(&a, &b, &op, middle);
    while(i-- != 0)
      pb(&a, &b, &op);

  }


  *head_of_a = a;
  *head_of_b = b;
  *op_list = op;
  ft_printf("Number of Numbers pushed:%i\n", i);
}
