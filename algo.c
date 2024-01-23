/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:14:01 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/23 16:43:44 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	algo_swap(t_swap **stack_a, t_swap **stack_b)
{
	int	med;

	med = flstsize(*stack_a) / 2;
	index_value(*stack_a);
	while (flstsize(*stack_a) > 3 && !check_if_sorted(stack_a))
	{
		if ((*stack_a)->index_value > med)
		{
			push_a_to_b(stack_a, stack_b, 1);
			rotate_b(stack_b, 1);
		}
		else
			push_a_to_b(stack_a, stack_b, 1);
	}
	if (flstsize(*stack_a) == 3)
		sort_3(stack_a);
	next_step(stack_a, stack_b);
}

void	next_step(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*cheapest_node;

	while (*stack_b)
	{
		findex(*stack_a);
		findex(*stack_b);
		b_target(stack_a, stack_b);
		cost(stack_a, stack_b);
		cheapest_node = cheapst_move(stack_b);
		push_top(stack_a, stack_b, cheapest_node);
		push_b_to_a(stack_b, stack_a, 1);
	}
	top(stack_a);
}

void	turk_algo(t_swap **stack_a, t_swap **stack_b)
{
	if (check_if_sorted(stack_a))
		exit(0);
	if (flstsize(*stack_a) == 3)
		sort_3(stack_a);
	if (flstsize(*stack_a) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(*stack_a, 1);
	}
	if (flstsize(*stack_a) > 3)
		algo_swap(stack_a, stack_b);
}

void	push_top(t_swap **stacka, t_swap **stackb, t_swap *cheapest)
{
	while ((*stackb && *stackb != cheapest)
		&& (*stacka && *stacka != cheapest->target_node))
	{
		if ((cheapest)->above_median && cheapest->target_node->above_median)
			rr(stacka, stackb, 1);
		else if (!(cheapest)->above_median
			&& !cheapest->target_node->above_median)
			rrr(stacka, stackb, 1);
		else
			break ;
	}
	while (*stackb && *stackb != cheapest)
	{
		if ((cheapest)->above_median)
			rotate_b(stackb, 1);
		else
			rev_rotate_b(stackb, 1);
	}
	while (*stacka && *stacka != cheapest->target_node)
	{
		if (cheapest->target_node->above_median)
			rotate_a(stacka, 1);
		else
			rev_rotate_a(stacka, 1);
	}
}

void	top(t_swap **stack_a)
{
	t_swap	*min;

	findex(*stack_a);
	min = mini_medien(*stack_a);
	while (*stack_a != min)
	{
		if (min->above_median)
			rotate_a(stack_a, 1);
		else
			rev_rotate_a(stack_a, 1);
	}
}
