/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medien.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:19:32 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/19 21:06:47 by aghounam         ###   ########.fr       */
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
	return (sum);
}

int	mini_medien(t_swap *head)
{
	int		min;
	t_swap	*current;

	if (!head || !head)
		return (0);
	min = (head)->content;
	current = head;
	while (current->next)
	{
		if (current->next->content < min)
			min = current->next->content;
		current = current->next;
	}
	return (min);
}
