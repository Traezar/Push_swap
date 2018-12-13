#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void sort_both_stacks(t_node **stack_a, t_node **stack_b, t_oplist **op)
{

  sort_inplace(&stack_a, &op_a);
  sort_inplace(&stack_b, &op_b); // NEED TO INVERT THE B AND A;
  combine(&op_a, &op_b, op);
}

void sort_inplace(t_node **stack_a, t_node **stack_b, t_oplist **op)
{
  int len;
  t_node *a;
  t_node *b;

  a = *head_a;
  b = *head_b;
  len = get_chain_size(a);
  while(a != NULL)
  {
      pb(&a, &b, &op);
      sort_inplace(&a, &b , &op);
      sort_insert(&a, &b , &op);
  }
}

void sort_insert(t_node **stack_a, t_node **b, t_oplist **op)
{
  t_node *a;
  t_node *b;

  a = *head_a;
  b = *head_b;
  if ((a = NULL) || ((b->rank) > (a->rank)))
    pa(&a, &b, &op);
  else
  {
    pb(&a, &b, &op);
    sort_insert(&a, &b , &op);
    pa(&a, &b, &op);
  }
}
