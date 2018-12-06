/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:25:49 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/18 12:00:09 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"


typedef struct s_stack
{
	int num;
	struct s_stack *next;
}	t_stack;

typedef struct s_command
{
	char *name;
	void (*f)(t_stack **a, t_stack **b);
}	t_command;


void execute_checker (char **int_array);
void initialise_stack_a(t_stack **head_of_a,char **int_array);
void reverse_stack_order(t_stack **head_of_stack);
void push_front_stack(t_stack **head_of_stack,t_stack **ptr_to_node);
void push_back_stack(t_stack **head_of_stack,t_stack **ptr_to_node);
int check_if_valid(char *command);
char **create_array_for(char *command, char **array);
int check_sorted(t_stack *head_of_a);
int execute_command(t_stack **head_of_a, t_stack **head_of_b, char **command_array, t_command list[]);
int sorted(char *int_array, char **commands_array);

void exec_sa(t_stack **head_of_a, t_stack **head_of_b);
void exec_sb(t_stack **head_of_a, t_stack **head_of_b);
void exec_ss(t_stack **head_of_a, t_stack **head_of_b);
void exec_pa(t_stack **head_of_a, t_stack **head_of_b);
void exec_pb(t_stack **head_of_a, t_stack **head_of_b);
void exec_ra(t_stack **head_of_a, t_stack **head_of_b);
void exec_rb(t_stack **head_of_a, t_stack **head_of_b);
void exec_rr(t_stack **head_of_a, t_stack **head_of_b);
void exec_rra(t_stack **head_of_a, t_stack **head_of_b);
void exec_rrb(t_stack **head_of_a, t_stack **head_of_b);
void exec_rrr(t_stack **head_of_a, t_stack **head_of_b);
void sort_success(void);
void sort_failure(void);
