/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 18:13:41 by smclacke      #+#    #+#                 */
/*   Updated: 2023/06/25 16:45:16 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// ROTATE:
//		ra = (rotate a) shift up all elements of stack a by 1
//		rb = (rotate b) shift up all elements of stack b by 1
//		rr = ra and rb at the same time
//		first element becomes the last

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack)
	{
		first = *stack;
		last = *stack;
		while (last->next)
			last = last->next;
		*stack = first->next;
		first->next = NULL;
		last->next = first;
	}
}

void	ft_ra(t_stack **stack)
{	
	ft_rotate(stack);
	ft_putendl("ra");
}

void	ft_rb(t_stack **stack)
{
	ft_rotate(stack);
	ft_putendl("rb");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putendl("rr");
}
