/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 15:39:55 by smclacke      #+#    #+#                 */
/*   Updated: 2024/05/15 15:45:09 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_atoi(const char *str)
{
	long	neg;
	long	num;
	long	i;

	i = 0;
	neg = 1;
	num = 0;
	while ((ft_isspace(str[i])))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	if ((num * neg) > INT_MAX || (num * neg) < INT_MIN)
		ft_error("Error");
	return (num * neg);
}
