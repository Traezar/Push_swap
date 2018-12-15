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
