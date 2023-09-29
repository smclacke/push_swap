/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ishex.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: SarahLouise <SarahLouise@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 16:01:48 by smclacke      #+#    #+#                 */
/*   Updated: 2023/07/02 15:03:41 by SarahLouise   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_ishex(int c)
{
	c = ft_toupper(c);
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))
		return (42);
	else
		return (0);
}
