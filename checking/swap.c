/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 18:12:07 by smclacke      #+#    #+#                 */
/*   Updated: 2023/06/25 16:44:35 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

// SWAP:
//		sa = (swap a) swap first two elements at the top of stack a
//		sb = (swap b) swap first two elements at the top of stack b
//		ss = sa and sb at the same time

void	ft_swap(t_stack **stack)
{
	t_stack	*swap;

	if (!*stack || !(*stack)->next)
		return ;
	swap = (*stack)->next;
	(*stack)->next = swap->next;
	swap->next = *stack;
	*stack = swap;
}

void	ft_sa(t_stack **stack)
{
	ft_swap(stack);
	ft_putendl("sa");
}

void	ft_sb(t_stack **stack)
{
	ft_swap(stack);
	ft_putendl("sb");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putendl("ss");
}
