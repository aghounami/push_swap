/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:14:01 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/19 00:12:55 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void push_algo(z_list **stack_a, z_list **stack_b)
{
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

void algo_swap(z_list **stack_a, z_list **stack_b)
{
	z_list *cheapest_node;
	int medd = flstsize(*stack_a) / 2;
	while (flstsize(*stack_a) > 3)
	{
		if ((*stack_a)->content > medd)
		{
			push_a_to_b(stack_a, stack_b);
			rotate_a(stack_b);
		}
		else
			push_a_to_b(stack_a, stack_b);
	}
	sort_3(stack_a);
	while (*stack_b)
	{
		findex(*stack_a);
		findex(*stack_b);
		b_target(stack_a, stack_b);
		cost(stack_a, stack_b);
		cheapest_node = next_step(stack_b);
		push_top(stack_a, stack_b, cheapest_node);
		push_b_to_a(stack_b, stack_a);
		top(stack_a);
	}
}

z_list *next_step(z_list **stack_b)
{
	int cos = INT_MAX;
	z_list *temp = *stack_b;
	z_list *cheapest;
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

void cost(z_list **stacka, z_list **stackb)
{
	int size_a;
	int size_b;
	z_list *stack;

	size_a = flstsize(*stacka);
	size_b = flstsize(*stackb);
	stack = *stackb;
	while (stack)
	{
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
void push_top(z_list **stacka, z_list **stackb, z_list *cheapest)
{
	while (*stackb && *stackb != cheapest)
	{
		if ((cheapest)->above_median)
			rotate_a(stackb);
		else
			rev_rotate_a(stackb);
	}
	while (*stacka && *stacka != cheapest->target_node)
	{
		if (cheapest->target_node->above_median)
			rotate_a(stacka);
		else
			rev_rotate_a(stacka);
	}
}

void top(z_list **stack_a)
{
	z_list *tmp = *stack_a;
	int i = INT_MAX;
	while (tmp)
	{
		if ((tmp)->content < i)
			i = (tmp)->content;
		(tmp) = (tmp)->next;
	}
	while ((*stack_a)->content != i)
		rotate_a(stack_a);
}