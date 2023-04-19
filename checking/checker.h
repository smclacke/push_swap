/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 19:35:57 by smclacke      #+#    #+#                 */
/*   Updated: 2023/04/19 15:57:12 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../src/push_swap.h"
# include <stdlib.h>
# include <stddef.h>

//------------Checker-------------//
int			operations(char *input, t_stack **stack_a, t_stack **stack_b);
void		handle_input(t_stack **stack_a, t_stack **stack_b);

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
t_stack		*node_new(int value);
void		list_index(t_stack *stack, int list_size);
void		var_to_stack(t_stack **stack, int var);
t_stack		*init_list(int argc, char **argv);
int			ft_sorted(t_stack **stack);

//-------------Utils-------------//
void		free_stack(t_stack **stack);
void		dup_input(t_stack *stack);
int			valid_input(char *argv);
t_stack		*create_stack(int argc, char **argv);

#endif
