/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: SarahLouise <SarahLouise@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 18:53:57 by smclacke      #+#    #+#                 */
/*   Updated: 2023/04/22 19:31:22 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// git testing

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
