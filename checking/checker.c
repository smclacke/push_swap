/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 19:26:34 by smclacke      #+#    #+#                 */
/*   Updated: 2023/04/19 15:52:12 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	operations(char *args, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(args, "pa\n") == 0)
		ft_push(stack_b, stack_a);
	else if (ft_strcmp(args, "pb\n") == 0)
		ft_push(stack_a, stack_b);
	else if (ft_strcmp(args, "sa\n") == 0)
		ft_swap(stack_a);
	else if (ft_strcmp(args, "sb\n") == 0)
		ft_swap(stack_b);
	else if (ft_strcmp(args, "ss\n") == 0)
		ft_ss(stack_a, stack_b);
	else if (ft_strcmp(args, "ra\n") == 0)
		ft_rotate(stack_a);
	else if (ft_strcmp(args, "rb\n") == 0)
		ft_rotate(stack_b);
	else if (ft_strcmp(args, "rr\n") == 0)
		ft_rr(stack_a, stack_b);
	else if (ft_strcmp(args, "rra\n") == 0)
		ft_rev_rot(stack_a);
	else if (ft_strcmp(args, "rrb\n") == 0)
		ft_rev_rot(stack_b);
	else if (ft_strcmp(args, "rrr\n") == 0)
		ft_rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	handle_input(t_stack **stack_a, t_stack **stack_b)
{
	char	*buffer;

	buffer = get_next_line(0);
	while (buffer)
	{
		if (!operations(buffer, stack_a, stack_b))
			ft_error();
		free (buffer);
		buffer = get_next_line(0);
	}
}

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
	handle_input(&stack_a, &stack_b);
	if (ft_sorted(&stack_a) && !stack_b)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	free_stack(&stack_a);
	return (0);
}
