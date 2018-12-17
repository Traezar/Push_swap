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

int rotate_or_swap_ascending(int rank, int next_rank, int  size)
{
  if ((rank < next_rank) && (rank - 1 != next_rank)
  && (rank != next_rank - 1)
  && (rank != size && (next_rank != 1)))
    return (0);
  return (1);
}

int rotate_or_swap_descending(int rank, int next_rank, int  size)
{
  if ((rank > next_rank) && (rank + 1 != next_rank)
  && (rank != next_rank + 1)
  && (rank != 1 && (next_rank != size)))
    return (0);
  return (1);
}

int not_sorted(t_node **stack_a, t_node **stack_b)
{
  t_node *a;
  t_node *b;

  a = *stack_a;
  b = *stack_b;
  if(b != NULL)
    return 1;
  else
    while ( a->next != NULL)
    {
      if (a->rank <= (a->next)->rank)
        a = a->next;
      else
        return 1;
    }
  return 0;
}
