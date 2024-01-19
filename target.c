/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:32:34 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/19 22:05:48 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	target_min(t_swap *stack_b, t_swap **stack_a)
{
	int		target;
	t_swap	*stacka;

	target = INT_MAX;
	stacka = *stack_a;
	while (stacka)
	{
		if (stacka->content < target)
		{
			stack_b->target_node = stacka;
			target = stacka->content;
		}
		stacka = stacka->next;
	}
}

void	find_target(t_swap **stack_a, t_swap *stack_b)
{
	int		target;
	t_swap	*stack__a;

	target = INT_MIN;
	stack__a = *stack_a;
	while (stack__a)
	{
		if (stack__a->content > stack_b->content)
		{
			if (target == INT_MIN || stack__a->content < target)
			{
				stack_b->target_node = stack__a;
				target = stack__a->content;
			}
		}
		stack__a = stack__a->next;
	}
	if (target == INT_MIN)
		target_min(stack_b, stack_a);
}

void	b_target(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*node_b;

	node_b = *stack_b;
	while (node_b)
	{
		find_target(stack_a, node_b);
		node_b = node_b->next;
	}
}
