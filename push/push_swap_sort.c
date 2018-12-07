#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

t_node *create_stack_array (char **ptr,int size)
{
  t_node *stack;
  int  i;

  i = 0;
  i = size;
  stack = malloc(sizeof(t_node) * size);
	while (i <= size)
  {
    stack[i].value = ft_atoi(ptr[i]);
    stack[i].distance_to_top = i;
    stack[i].distance_to_bottom = size - i;
    stack[i].rank = 0;
  }
  return (stack);
}

int get_largest_value(t_array *array)
{
  int i;
  t_node *ptr;

  i = 0;
  ptr =
  array->largest_value = 0;
  while (i < array.size)
  {
    if(array[i].value >= array->largest_value)
       array->largest_value == array[i].value;
    i++;
  }
  return (array->largest_value);
}

int get_smallest_value(t_array *array)
{
  int i;
  t_node *ptr;

  i = 0;
  ptr =
  array->smallest_value = array->largest_value;
  while (i < array.size)
  {
    if(array[i].value >= array->largest_value)
       array->smallest_value == array[i].value;
    i++;
  }
  return (array->smallest_value);
}

void assign_rank_to_stack_elements (t_node *ranker, t_array **array)
{
  int i;
  t_array *ptr;

  i = 0;
  while (ranker != NULL)
  {
    ptr = array;
    while(ptr->stack[i].value != ranker.num) && (ptr->stack[i] <= ptr->size))
    {
      if (ranker->num == ptr->stack[i].value)
      ptr->stack.rank = ranker->rank;
      i++;
    }
    ranker = ranker->next;
  }
  return ;
}

void sort_with_commands(t_array **array)
{
  t_node *stack_a;
  t_node *stack_b;
  t_op_list op;
  int middle;

  stack_a = array->stack;
  stack_b = NULL;
  middle = (rank / 2);
  if (array->size > 20)
  {
    while(!sorted(stack_a, stack_b array->size) && (stack_b != NULL))
    {
      while (there_are_numbers_bigger_than_the_middle(stack_a, middle))
        move_them_over_to_stack_b(&stack_a, &stack_b, middle, op);
      sort_both_stacks(&stack_a, &stack_b, middle, op);
      unload_stack_b(&stack_a, &stack_b, middle, op);
    }
  }
}
