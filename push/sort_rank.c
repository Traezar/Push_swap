
#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void front_back_split(t_stack **head_of_a, t_stack *front, t_stack *back)
{
  t_stack *fast;
  t_stack *slow;

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
  front = *head_of_a;
  back = slow->next;
  slow->next = NULL;
}

t_stack *merge(t_stack *front, t_stack *back)
{
  t_stack *result = NULL;

  if (front == NULL)
    return(back);
  else if (back == NULL)
    return(front);
  if (front->num <= back->num)
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

void sort(t_stack **head_of_a)
{
  t_stack *front;
  t_stack *back;

  front = NULL;
  back = NULL;
  if (*head_of_a == NULL )
    return ;
  if ((*head_of_a)->next == NULL)
    return ;
  front_back_split(head_of_a, front, back);
  sort(&front);
  sort(&back);
  *head_of_a = merge(front,back);
}

void rank (t_stack **head_of_stack)
{
	t_stack *stack;
  t_stack *ref;
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
