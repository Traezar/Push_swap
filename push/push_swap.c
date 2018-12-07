/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:26:10 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/18 11:02:42 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

t_array *get_params(char **int_array)
{
	t_array *array;
	char **ptr;
	int i;

	i = 0;
	ptr = int_array;
	array = malloc(sizeof(t_array));
	while (ptr[i] != '\0')
		i++;
	array->size = ++i;
	array->stack =  create_stack_array(int_array, array->size);
	array->largest_value = get_largest_value(array);
	array->smallest_value = get_smallest_value(array);
	return (array);
}

void execute_push_swap (char ** int_array)
{
	t_node *ranker;
	t_array *array;
	int middle;

	middle = 0;
	array = get_params(int_array);
	ranker = create_stack_array(int_array, array->size);
	sort(&ranker);
	rank(&ranker);
	assign_rank_to_stack_elements(ranker, &array);
	sort_with_commands(&array);
	return ;
}

int main (int argc, char ** argv)
{
	int i;
	char **array;

	i = 0;
	if (argc > 2)
	{
		while(argv[i] != NULL)
		{
			if (ft_isinteger(argv[i]))
				i++;
			else
			{
				ft_printf("This argument is invalid : %s", argv[i]);
				exit(0);
			}
		}
			execute_push_swap(++argv);
	}
	else if (argc == 2)
	{
		array = ft_strsplit(argv[1],' ');
		execute_push_swap(array);
	}
	else
	ft_printf("Invalid number of arguments to Push_swap!");
	return (0);
}
