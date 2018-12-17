/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:51:26 by rsathiad          #+#    #+#             */
/*   Updated: 2018/12/06 15:51:28 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void print_to_oplist(char *str, t_oplist **head)
{
  t_oplist *new;

  new = malloc(sizeof(t_oplist));
  new->op = ft_strdup(str);
  new->next = *head;
  *head = new;
  return;
}

void sort_3(t_packet *s)
{
  int first;
  int second;
  int third;

  first = s->a->rank;
  second = s->a->next->rank;
  third = (s->a->next)->next->rank;
  if ((first < second)  && (second < third) && first < third) //123
    return;
  else if ((first > second) &&(first > third) && (second < third))//312
    ra(&s->a, &s->op);
  else if ((first < second) && (second > third) && (third > first))//132
    {
      rra(&s->a, &s->op);
      sa(&s->a, &s->op);
    }
  else if ((first > second) && (second > third)&&(first > third))//321
    {
      sa(&s->a, &s->op);
      rra(&s->a, &s->op);
    }
  else if ((first > second) && (second < third) && (third > first))//213
    sa(&s->a, &s->op);
  else if((first < second) && (second > third) && (third < first))//231
    rra(&s->a, &s->op);
}
