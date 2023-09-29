/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/15 16:38:03 by smclacke      #+#    #+#                 */
/*   Updated: 2023/07/02 15:02:17 by SarahLouise   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}
