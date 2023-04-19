/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 18:12:56 by smclacke      #+#    #+#                 */
/*   Updated: 2023/04/18 22:53:28 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// PUSH:
//		pa = (push a) take first element at top 
//			of stack b and put to top of stack a
//		pb = (push b) take first element at top 
//			of stack a and put to top of stack b

void	ft_push(t_stack **stack_og, t_stack **stack_new)
{
	t_stack	*push;

	push = *stack_og;
	if (!(*stack_og))
		return ;
	*stack_og = (*stack_og)->next;
	if (!stack_new)
		*stack_new = push;
	else
	{
		push->next = *stack_new;
		*stack_new = push;
	}
}

void	ft_pa(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_putendl("pa");
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_putendl("pb");
}
