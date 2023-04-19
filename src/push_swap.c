/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 22:14:34 by smclacke      #+#    #+#                 */
/*   Updated: 2023/04/19 17:17:10 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = create_stack(argc, argv);
	stack_b = NULL;
	dup_input(stack_a);
	list_index(stack_a, ft_lstsize((t_list *)stack_a));
	ft_print_stack(stack_a);
	if (ft_lstsize((t_list *)stack_a) <= 1)
		free_stack(&stack_a);
	ft_sort(&stack_a, &stack_b);
	ft_print_stack(stack_a);
	free_stack(&stack_a);
	return (0);
}
