/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 21:50:52 by smclacke      #+#    #+#                 */
/*   Updated: 2023/04/18 22:54:29 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack **stack)
{
	int	max;

	max = ft_max_num(*stack);
	if ((*stack)->index == max)
		ft_ra(stack);
	else if ((*stack)->next->index == max)
		ft_rra(stack);
	if (!(*stack)->next)
		return ;
	if ((*stack)->index > (*stack)->next->index)
		ft_sa(stack);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int			i;

	i = ft_lstsize((t_list *)*stack_a);
	while (i--)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
	small_sort(stack_a);
	ft_pa(stack_b, stack_a);
	ft_pa(stack_b, stack_a);
	if (!(*stack_a)->next)
		return ;
	if ((*stack_a)->index > (*stack_a)->next->index)
		ft_sa(stack_a);
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;

	max_num = ft_max_num(*stack_a);
	max_bits = ft_max_bits(max_num);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j <= max_num)
		{
			if (((*stack_a)->index >> i) & 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			ft_pa(stack_b, stack_a);
		i++;
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = ft_lstsize((t_list *)*stack_a);
	if (ft_sorted(stack_a) || i <= 1)
		return ;
	if (i <= 3)
		small_sort(stack_a);
	else if (i <= 5)
		big_sort(stack_a, stack_b);
	else
		ft_radix(stack_a, stack_b);
}
