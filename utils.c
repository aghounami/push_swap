/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:36:54 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/23 18:01:08 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	findex(t_swap *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = flstsize(stack) / 2;
	while (stack)
	{
		(stack)->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		i++;
		(stack) = (stack)->next;
	}
}

int	check_if_sorted(t_swap **stacka)
{
	t_swap	*stack;

	stack = *stacka;
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		else
			stack = stack->next;
	}
	return (1);
}

t_swap	*cheapst_move(t_swap **stack_b)
{
	int		cos;
	t_swap	*temp;
	t_swap	*cheapest;

	temp = *stack_b;
	cos = INT_MAX;
	while (temp)
	{
		if (temp->mouve < cos)
		{
			cos = temp->mouve;
			cheapest = temp;
		}
		temp = temp->next;
	}
	return (cheapest);
}

void	cost(t_swap **stacka, t_swap **stackb)
{
	int		size_a;
	int		size_b;
	t_swap	*stack;

	size_a = flstsize(*stacka);
	size_b = flstsize(*stackb);
	stack = *stackb;
	while (stack)
	{
		stack->mouve = 0;
		if (stack->above_median)
			stack->mouve = stack->index;
		else
			stack->mouve = size_b - stack->index;
		if (stack->target_node->above_median)
			stack->mouve += stack->target_node->index;
		else
			stack->mouve += size_a - stack->target_node->index;
		stack = stack->next;
	}
}

