/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 18:14:37 by smclacke      #+#    #+#                 */
/*   Updated: 2023/04/19 02:50:12 by SarahLouise   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// REVERSE ROTATE:
//		rra = (reverse rotate a) shift down all elements of stack a by 1
//		rrb = (reverse rotate b) shift down all elements of stack b by 1
//		rrr = rra and rrb at same time
//		last element becomes the fist

void	ft_rev_rot(t_stack **stack)
{
	t_stack	*top;
	t_stack	*var;

	if (!*stack || !(*stack)->next)
		return ;
	top = *stack;
	while (top->next)
	{
		var = top;
		top = top->next;
	}
	top->next = *stack;
	var->next = NULL;
	*stack = top;
}

void	ft_rra(t_stack **stack)
{
	ft_rev_rot(stack);
	ft_putendl("rra");
}

void	ft_rrb(t_stack **stack)
{
	ft_rev_rot(stack);
	ft_putendl("rrb");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rot(stack_a);
	ft_rev_rot(stack_b);
	ft_putendl("rrr");
}
