
#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void front_back_split(t_node **head_of_a, t_node **front, t_node **back)
{
  t_node *fast;
  t_node *slow;

  slow = *head_of_a;
  fast = (*head_of_a)->next;

  while (fast != NULL)
  {
    fast = fast->next;
    if (fast != NULL)
    {
      slow = slow->next;
      fast = fast->next;
    }
  }
  *front = *head_of_a;
  *back = slow->next;
  slow->next = NULL;
}

t_node *merge(t_node *front, t_node *back)
{
  t_node *result = NULL;

  if (front == NULL)
    return(back);
  else if (back == NULL)
    return(front);
  if (front->value <= back->value)
  {
    result = front;
    result->next = merge(front->next, back);
  }
  else
  {
    result = back;
    result->next = merge(front, back->next);
  }
  return(result);
}

void sort(t_node **head_of_a)
{
  t_node *front;
  t_node *back;

  front = NULL;
  back = NULL;
  if (*head_of_a == NULL )
    return ;
  if ((*head_of_a)->next == NULL)
    return ;
  front_back_split(head_of_a, &front, &back);
  sort(&front);
  sort(&back);
  *head_of_a = merge(front,back);
}

void rank (t_node **head_of_stack)
{
	t_node *stack;
  t_node *ref;
  int i;

	i = 0;
	stack = *head_of_stack;
  ref = stack;
	while (stack != NULL)
	{
		stack->rank = ++i;
		stack = stack->next;
	}
  *head_of_stack = ref;
	return;
}
