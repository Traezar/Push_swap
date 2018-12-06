/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:32:49 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/18 10:32:51 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../libft/includes/libft.h"

int check_sorted(t_stack *head_of_a)
{
  t_stack *stack_a;
  stack_a = head_of_a;
  if (stack_a == NULL || stack_a->next == NULL)
    return (1);
  while (stack_a != NULL && stack_a->next != NULL)
  {
    if (stack_a->next ==NULL)
      return(1);
    else if (stack_a->num >= (stack_a->next)->num)
      stack_a = stack_a->next;
    else
      return(0);
  }
  return(0);
}

int execute_command(t_stack **head_of_a, t_stack **head_of_b,char ** command_array, t_command list[])
{

  int count;
  int index;

  count = 0;
  while (command_array[count] != NULL)
  {
    index = 0;
    while (index < 11)
    {
      if (ft_strcmp(command_array[count], list[index].name) == 0)
      {
        list[index].f(head_of_a, head_of_b);
        break;
      }
      index++;
    }
    count++;
  }
  return (check_sorted(*head_of_a));
}

int sorted(char *int_array, char **commands_array)
{
  t_stack* head_of_a;
  t_stack* head_of_b;
  int sorted;
  t_command commands_list[]={
    {"sa", &exec_sa},
    {"sb", &exec_sb},
    {"ss", &exec_ss},
    {"pa", &exec_pa},
    {"pb", &exec_pa},
    {"ra", &exec_ra},
    {"rb", &exec_rb},
    {"rr", &exec_rr},
    {"rra", &exec_rra},
    {"rrb", &exec_rrb},
    {"rrr", &exec_rrr}
  };

  sorted = 0;
  head_of_a = NULL;
  head_of_b = NULL;
  initialise_stack_a(&head_of_a, &int_array);
  sorted = execute_command(&head_of_a, &head_of_b, commands_array, commands_list);
  return (1);
}
