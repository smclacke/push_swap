/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 15:57:58 by smclacke      #+#    #+#                 */
/*   Updated: 2023/07/02 15:06:33 by SarahLouise   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = malloc(sizeof(*s) * (ft_strlen(s) + 1));
	i = 0;
	if (!str)
		return (0);
	while (*s)
	{
		str[i] = f(i, *s);
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}
