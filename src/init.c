/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 17:45:35 by smclacke      #+#    #+#                 */
/*   Updated: 2024/05/15 15:45:05 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	list_index(t_stack *stack, int list_size)
{
	t_stack	*list_end;
	t_stack	*var;

	while (list_size-- > 0)
	{
		list_end = NULL;
		var = stack;
		while (var)
		{
			if (!var->index && (!list_end || var->num > list_end->num))
				list_end = var;
			var = var->next;
		}
		if (list_end)
			list_end->index = list_size;
	}
}

void	var_to_stack(t_stack **stack, int var)
{
	t_stack	*new;
	t_stack	*node;

	if (!*stack)
	{
		*stack = node_new(var);
		return ;
	}
	node = *stack;
	while (node->next)
		node = node->next;
	new = node_new(var);
	node->next = new;
}

void	ft_stacking(char **arr, t_stack **stack_a)
{
	int		j;
	long	argv_tmp;

	j = 0;
	while (arr[j])
	{
		argv_tmp = ft_atoi(arr[j]);
		if ((argv_tmp < INT_MIN || argv_tmp > INT_MAX)
			|| (!valid_input(arr[j])))
			ft_error("Error");
		j++;
		var_to_stack(stack_a, argv_tmp);
	}
}

t_stack	*create_stack(int argc, char **argv)
{
	int			i;
	char		**arr;
	t_stack		*stack_a;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		arr = ft_split(argv[i], ' ');
		if (!arr || !arr[0])
			ft_error("Error");
		ft_stacking(arr, &stack_a);
		ft_free_arr(arr);
		i++;
	}
	return (stack_a);
}
