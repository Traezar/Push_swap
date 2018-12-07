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

#define allcon(x, y, size) ((con1 && con2) || con3)
#define con1(x, y) (x >= y)
#define con2(x, y) (x == y - 1)
#define con3(x, y, size) (x == size && (y == 1)

int not_sorted(t_node **stack_a, t_node **stack_b, int size)
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

  t_node *op;

  a = *stack_a;
  ref = a;
  if (not_sorted (a, b, size))
  {
  if (size == 2)
    sa(stack_a, op);
  else if ( size >= 3 && size <= 5)
  {
    while(not_sorted(a, b , size))
    while (allcon(a->rank, (a->next)->rank, size) && a->next != NULL)
    {
      rotate_best();
      while(not_sorted)




      a = *stack_a;
    }

  }
}
