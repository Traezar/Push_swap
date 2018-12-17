#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

t_node *create_stack_array (char **ptr,int size)
{

  t_node *stack;
  t_node *ptr_ref;
  int  i;

  i = -1;
  ptr_ref = NULL;
	while (ptr[++i] != '\0')
  {
    stack = malloc(sizeof(t_node));
    stack->value = ft_atoi(ptr[i]);
    stack->distance_to_top = i;
    stack->distance_to_bottom = size - (i + 1);
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
  t_packet *s;

  s = malloc(sizeof(t_packet));
  s->a = (*array)->stack;
  s->b = NULL;
  s->op = NULL;
  if ((*array)->size == 3)
    sort_3(s);
  else
  sort_big(&s->a, &s->b, &s->op, (*array)->size);
  debug_print_state(&s->a, &s->b, &s->op);
  ft_printf("sorting done");
  return ;
}
