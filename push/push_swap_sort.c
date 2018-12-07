#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

t_node *create_stack_array (char **ptr,int size)
{

  t_node *stack;
  t_node *ptr_ref;
  int  i;

  i = 0;
	while (i <= size)
  {
    stack = malloc(sizeof(t_node));
    stack->value = ft_atoi(ptr[i]);
    stack->distance_to_top = i;
    stack->distance_to_bottom = size - i;
    stack->rank = 0;
    stack->next= NULL;
    push_back_node(&ptr_ref, &stack);
  }
  return (ptr_ref);
}

int get_largest_value(t_array *array)
{
  t_node *stack;

  stack = array->stack;
  array->largest_value = stack->value;
  while (stack != NULL)
  {
    if(stack->value >= array->largest_value)
       array->largest_value = stack->value;
    stack = stack->next;
  }
  return (array->largest_value);
}

int get_smallest_value(t_array *array)
{
  t_node *stack;

  stack=array->stack;
  array->smallest_value = stack->value;
  while (stack != NULL)
  {
    if(stack->value >= array->largest_value)
       array->smallest_value = stack->value;
    stack = stack->next;
  }
  return (array->smallest_value);
}

void assign_rank_to_stack_elements (t_node *ranker, t_array **array)
{
  int i;
  t_node  *stack;

  i = 1;
  while (ranker != NULL)
  {
    stack = (*array)->stack;
    while(stack != NULL)
    {
      if (ranker->value == stack->value)
      {
        stack->rank = ranker->rank;
        break ;
      }
      stack = stack->next;
    }
    ranker = ranker->next;
  }
  return ;
}

void sort_with_commands(t_array **array)
{
  t_node *stack_a;
  t_node *stack_b;
  t_oplist *op;
  int middle;

  stack_a = (*array)->stack;
  stack_b = (*array)->stack;
  middle = ((*array)->size / 2);
  if ((*array)->size > 20)
  {
    while(!(sorted(stack_a, stack_b, (*array)->size)))
    {
      while (there_are_numbers_bigger_than_the_middle(stack_a, middle))
        move_them_over_to_stack_b(&stack_a, &stack_b, middle, &op);
    }
    sort_both_stacks(&stack_a, &stack_b, middle, &op);
    //unload_stack_b(&stack_a, &stack_b, middle, op)
    ft_printf("sorting done");
  }
  else
  sort_small(&stack_a, &stack_b, middle, &op);
  ft_printf("sorting done");
  return ;
}
