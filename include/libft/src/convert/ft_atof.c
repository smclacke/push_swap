/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 16:01:22 by smclacke      #+#    #+#                 */
/*   Updated: 2023/07/02 15:02:26 by SarahLouise   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief parses the array and checks whether there is an positive or negative
 * changes sign variable from positive to negative if '-' is found. 
 * 
 * @param str array to convert
 * @param sign positive or negative 
 * @return index after positive or negative sign
 */
int	check_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

/***
 * @brief 
 * 
 * @param str - array to be converted into a float
 * @return double - or -1 if it fails
*/
double	ft_atof(char *str)
{
	int		i;
	int		sign;
	double	result;
	double	decimal;

	result = 0.0;
	decimal = 1.0;
	sign = 1;
	i = check_sign(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		decimal *= 10;
	}
	if (str[i] == '\0')
		return (sign * result / decimal);
	else
		return (-1);
}
