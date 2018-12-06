/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:26:25 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/18 20:13:37 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../libft/includes/libft.h"

void execute_checker (char **int_array)
{
	char	*commands_entered;
	char	**command_array;
	int		commands;
	int		not_valid;

	commands = 0;
	not_valid = 0;
	commands_entered = NULL;
	command_array = NULL;
	while (get_next_line(1, &commands_entered))
	{
		not_valid = check_if_valid(commands_entered);
		if (not_valid)
			ft_printf("Invalid value : %s", commands_entered);
		else
		{
			commands++;
			command_array = create_array_for(commands_entered, command_array);
		}
	}
	if (sorted(*int_array, command_array))
		return (sort_success());
	else
		return (sort_failure());
}

int check_if_valid(char *command)
{
	int		i;
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

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(command, commands_list[i].name) == 0)
				i++;
		else
			break ;
	}
	if (i == 11)
		return (1);
	return (0);
}

char **create_array_for(char *command, char **array)
{
	static int	array_size = 0;
	char		**ret;

	ret = (char **)malloc(sizeof(char *) * (array_size + 2));
	ret[array_size] = ft_strdup(command);
	array_size++;
	ret[array_size] = NULL;
	if (array != NULL)
		ft_free_dblarray(&array);
	return (ret);
}
int main (int argc, char ** argv)
{
	int i;

	i = 0;
	if (argc != 1)
	{
		while ((argv[i] != NULL) && (ft_isinteger(argv[i])))
				i++;
		if (argv[i] == NULL)
			execute_checker(argv++);
		else
			ft_printf("Error cannot process this argumment : %s\n",argv[i]);
	}
	else
		ft_printf("Check the number of arguments!!\n");
		return 0;
}
