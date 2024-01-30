/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medien.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:19:32 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/29 15:28:50 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	medien(t_swap *head)
{
	int		max;
	int		min;
	int		sum;
	t_swap	*current;

	min = INT_MAX;
	max = INT_MIN;
	current = head;
	while (current != NULL)
	{
		if (current->content > max)
			max = current->content;
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	sum = max + min;
	return (sum / 2);
}

t_swap	*mini_medien(t_swap *head)
{
	int		min;
	t_swap	*current;
	t_swap	*min_node;

	if (!head || !head)
		return (0);
	current = head;
	min = INT_MAX;
	while (current)
	{
		if (current->content < min)
		{
			min = current->content;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}
