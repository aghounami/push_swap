/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:28:17 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/19 21:06:16 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	fatoi(const char *str)
{
	long			i;
	unsigned long	result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		if (!ft_isdigit(str[i]))
			errormsg("Error");
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		errormsg("Error");
	return (result * sign);
}

void	duplicate(t_swap *stack)
{
	int		tmp;
	t_swap	*runner;

	while (stack != NULL)
	{
		tmp = stack->content;
		runner = stack->next;
		while (runner != NULL)
		{
			if (runner->content == tmp)
				errormsg("Error");
			runner = runner->next;
		}
		stack = stack->next;
	}
}

void	errormsg(char *s)
{
	fprintf(stderr, "%s\n", s);
	exit(1);
}

void	leak(t_swap *list)
{
	t_swap	*next;

	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
}
