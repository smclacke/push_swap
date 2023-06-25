/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/15 16:11:24 by smclacke      #+#    #+#                 */
/*   Updated: 2023/06/25 16:45:18 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_sorted(t_stack **stack)
{
	t_stack	*var;

	var = *stack;
	while (var && var->next)
	{
		if (var->index > var->next->index)
			return (0);
		var = var->next;
	}
	return (1);
}

int	ft_max_bits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while (max_num > 0)
	{
		max_num >>= 1;
		max_bits++;
	}
	return (max_bits);
}

int	ft_max_num(t_stack *stack)
{
	int			max;
	t_stack		*var;

	max = INT_MIN;
	var = stack;
	while (var)
	{
		if (var->index > max)
			max = var->index;
		var = var->next;
	}
	return (max);
}
