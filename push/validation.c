/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 22:10:23 by rsathiad          #+#    #+#             */
/*   Updated: 2018/12/06 22:10:25 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

#define ALLCON {x, y, size} ((con1 && con2) || con3);
#define CON1 {x, y} (x >= y);
#define CON2 {x, y} (x != y - 1);
#define CON3 {x, y, size} (x == size && (y == 1));

int not_sorted(t_node **stack_a, t_node **stack_b)
{
  t_node *a;
  t_node *b;

  a = *stack_a;
  b = *stack_b;
  if(b != NULL)
    return 1;
  else
    while ( a != NULL)
    {
      if (a->rank <= (a->next)->rank)
        a = a->next;
      else
        return 1;
    }
  return 0;
}

void sort_small(t_node **stack_a, int size)
{
  t_node *a;
  t_node *ref;

  t_oplist *op;

  a = *stack_a;
  ref = a;
  if (not_sorted (&a, NULL))
  {
  if (size == 2)
    sa(&a, &op);
  else if ( size >= 3)
  {
    while(not_sorted(&a, NULL))
    {
      if (ALLCON (a->rank, (a->next)->rank, size))
      rotate_stacka(&a, &op);
      else
      sa(&a, &op);
    }
  }
 *stack_a = a;
}
}
