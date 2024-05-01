/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 22:31:32 by smclacke      #+#    #+#                 */
/*   Updated: 2024/05/01 12:43:30 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
				ft_error("Error");
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

t_stack	*node_new(int node)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->num = node;
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_stack	*ft_print_stack(t_stack *stack)
{
	t_stack	*list;

	list = stack;
	printf("\n------------- List -------------\n\n");
	while (list)
	{
		printf("node:		%d	|	index:		%d\n", list->num, list->index);
		list = list->next;
	}
	printf("\n");
	return (stack);
}
