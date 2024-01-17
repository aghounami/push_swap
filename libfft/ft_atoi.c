/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:46:12 by aghounam          #+#    #+#             */
/*   Updated: 2023/11/17 15:25:30 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	final(unsigned long int nbr, int po, int count)
{
	long	num;

	if (nbr > 9223372036854775807 || count >= 20)
	{
		if (po == 1)
			return (-1);
		else
			return (0);
	}
	num = nbr * po;
	return (num);
}

static unsigned long	loop(const char *str, unsigned long result, int *count)
{
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		*count += 1;
		str++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	result;
	int				sign;
	int				count;

	i = 0;
	result = 0;
	sign = 1;
	count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	result = loop(str + i, result, &count);
	return (final(result, sign, count));
}
