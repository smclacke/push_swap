/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_upper_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 22:13:52 by smclacke      #+#    #+#                 */
/*   Updated: 2023/07/02 15:02:40 by SarahLouise   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_upper_str(char *str)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
