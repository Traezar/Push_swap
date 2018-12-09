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

int rotate_or_swap(int rank, int next_rank, int  size)
{
  if (((rank >= next_rank) && (rank != next_rank - 1)) ||
    (rank == size && (next_rank == 1)))
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

void sort_small(t_node **stack_a, int size)
{
  t_node *a;
  t_node *b;
  t_node *ref;

  t_oplist *op;

  a = *stack_a;
  b = NULL;
  ref = a;
  if (not_sorted (&a, &b))
  {
      if (size == 2)
        sa(&a, &op);
      else if ( size >= 3)
      {
        while(not_sorted (&a, &b))
        {
          if (rotate_or_swap(a->rank, (a->next)->rank, size))
          rotate_stacka(1,&a, &op);
          else
          sa(&a, &op);
        }
      }
      *stack_a = a;
  }
  else
    ft_printf("List is already sorted !!!!: O.K");
  return ;
}
