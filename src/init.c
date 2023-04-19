/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 17:45:35 by smclacke      #+#    #+#                 */
/*   Updated: 2023/04/18 22:52:52 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	list_index(t_stack *stack, int list_size)
{
	t_stack	*list_end;
	t_stack	*var;

	while (list_size-- > 0)
	{
		list_end = NULL;
		var = stack;
		while (var)
		{
			if (!var->index && (!list_end || var->num > list_end->num))
				list_end = var;
			var = var->next;
		}
		if (list_end)
			list_end->index = list_size;
	}
}

void	var_to_stack(t_stack **stack, int var)
{
	t_stack	*new;
	t_stack	*node;

	if (!*stack)
	{
		*stack = node_new(var);
		return ;
	}
	node = *stack;
	while (node->next)
		node = node->next;
	new = node_new(var);
	node->next = new;
}
