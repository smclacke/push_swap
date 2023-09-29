/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 22:14:28 by smclacke      #+#    #+#                 */
/*   Updated: 2023/09/29 16:39:53 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int					num;
	int					index;
	struct s_stack		*next;
}		t_stack;

//----------Operations-----------//
// PUSH
void		ft_push(t_stack **stack_og, t_stack **stack_new);
void		ft_pa(t_stack **stack_b, t_stack **stack_a);
void		ft_pb(t_stack **stack_a, t_stack **stack_b);
// SWAP
void		ft_swap(t_stack **stack);
void		ft_sa(t_stack **stack);
void		ft_sb(t_stack **stack);
void		ft_ss(t_stack **stack_a, t_stack **stack_b);
// ROTATE
void		ft_rotate(t_stack **stack);
void		ft_ra(t_stack **stack);
void		ft_rb(t_stack **stack);
void		ft_rr(t_stack **stack_a, t_stack **stack_b);
// REVERSE ROTATE
void		ft_rev_rot(t_stack **stack);
void		ft_rra(t_stack **stack);
void		ft_rrb(t_stack **stack);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b);

//-------------Init--------------//
void		list_index(t_stack *stack, int list_size);
void		var_to_stack(t_stack **stack, int var);
void		ft_stacking(char **arr, t_stack **stack_a);
t_stack		*create_stack(int argc, char **argv);

//-------------Sort--------------//
void		small_sort(t_stack **stack);
void		big_sort(t_stack **stack_a, t_stack **stack_b);
void		ft_radix(t_stack **stack_a, t_stack **stack_b);
void		ft_sort(t_stack **stack_a, t_stack **stack_b);

//----------Sort_utils-----------//
int			ft_sorted(t_stack **stack);
int			ft_max_bits(int max_num);
int			ft_max_num(t_stack *stack);

//-------------Utils-------------//
void		free_stack(t_stack **stack);
void		dup_input(t_stack *stack);
int			valid_input(char *argv);
t_stack		*node_new(int value);
t_stack		*ft_print_stack(t_stack *stack);

#endif
