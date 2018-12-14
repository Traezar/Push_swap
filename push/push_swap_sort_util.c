#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void sort_both_stacks(t_node **stack_a, t_node **stack_b, t_oplist **op)
{
  t_oplist *op_a;
  t_oplist *op_b;

  (void)op;

  op_a = NULL;
  op_b = NULL;
  sort_inplace(stack_a, stack_b, &op_a);
  sort_inplace(stack_b, stack_a, &op_b); // NEED TO INVERT THE B AND A;
  //combine(&op_a, &op_b, op);
}

void sort_inplace(t_node **stack_a, t_node **stack_b, t_oplist **op)
{
  int len;
  t_node *a;
  t_node *b;

  a = *stack_a;
  b = *stack_b;
  len = get_chain_size(a);
  if(a != NULL)
  {
      pb(&a, &b, op);
      //debug
      debug_print_state(&a, &b, op);
      //debug
      ft_printf("Entered sort in place");
      sort_inplace(&a, &b , op);
      ft_printf("Entered sort insert");
      sort_insert(&a, &b , op);
  }
}

void sort_insert(t_node **stack_a, t_node **stack_b, t_oplist **op)
{
  t_node *a;
  t_node *b;

  a = *stack_a;
  b = *stack_b;
  //debug
  debug_print_state(&a, &b, op);
  //debug
  if ((a == NULL) || ((b->rank) < (a->rank)))
    pa(&a, &b, op);
  else
  {
    pb(&a, &b, op);
    sort_insert(&a, &b , op);
  }
}
