/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 22:31:32 by smclacke      #+#    #+#                 */
/*   Updated: 2023/04/19 15:51:07 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stack(t_stack **stack)
{
	t_stack	*var;

	while (*stack)
	{
		var = *stack;
		*stack = (*stack)->next;
		free(var);
	}
}

void	dup_input(t_stack *stack)
{
	t_stack	*var;
	t_stack	*first;

	var = stack->next;
	first = stack;
	while (var)
	{
		stack = first;
		while (stack)
		{
			if (var->num == stack->num && var != stack)
				ft_error();
			stack = stack->next;
		}
		var = var->next;
	}
}

int	valid_input(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' && !argv[i + 1])
		return (0);
	if (argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

t_stack	*create_stack(int argc, char **argv)
{
	int			i;
	int			j;
	long		argv_tmp;
	char		**arr;
	t_stack		*stack_a;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		j = 0;
		arr = ft_split(argv[i], ' ');
		while (arr[j])
		{
			argv_tmp = ft_atoi(arr[j]);
			if ((argv_tmp < INT_MIN || argv_tmp > INT_MAX)
				|| (!valid_input(arr[j])))
				ft_error();
			j++;
			var_to_stack(&stack_a, argv_tmp);
		}
		ft_free_arr(arr);
		i++;
	}
	return (stack_a);
}
