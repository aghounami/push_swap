/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:14:01 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/19 21:05:51 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
		push_b_to_a(stack_b, stack_a);
	}
	top(stack_a);
}

void	algo_swap(t_swap **stack_a, t_swap **stack_b)
{
	int	min;
	int	med;

	med = flstsize(*stack_a) / 2;
	min = mini_medien(*stack_a);
	if (min >= med)
		med = medien(*stack_a) / 2;
	while (flstsize(*stack_a) > 3)
	{
		if (!check_if_sorted(stack_a))
		{
			if ((*stack_a)->content > med)
			{
				push_a_to_b(stack_a, stack_b);
				rotate_b(stack_b);
			}
			else
				push_a_to_b(stack_a, stack_b);
		}
	}
	if (flstsize(*stack_a) == 3)
		sort_3(stack_a);
	next_step(stack_a, stack_b);
}

void	push_algo(t_swap **stack_a, t_swap **stack_b)
{
	if (check_if_sorted(stack_a))
		exit(0);
	if (flstsize(*stack_a) == 3)
		sort_3(stack_a);
	if (flstsize(*stack_a) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(*stack_a);
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
			rr(stacka, stackb);
		else if (!(cheapest)->above_median
			&& !cheapest->target_node->above_median)
			rrr(stacka, stackb);
		else
			break ;
	}
	while (*stackb && *stackb != cheapest)
	{
		if ((cheapest)->above_median)
			rotate_b(stackb);
		else
			rev_rotate_b(stackb);
	}
	while (*stacka && *stacka != cheapest->target_node)
	{
		if (cheapest->target_node->above_median)
			rotate_a(stacka);
		else
			rev_rotate_a(stacka);
	}
}

void	top(t_swap **stack_a)
{
	t_swap	*tmp;
	int		i;

	i = INT_MAX;
	tmp = *stack_a;
	while (tmp)
	{
		if ((tmp)->content < i)
			i = (tmp)->content;
		(tmp) = (tmp)->next;
	}
	while ((*stack_a)->content != i)
		rotate_a(stack_a);
}
