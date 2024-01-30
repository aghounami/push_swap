/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:43:02 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/30 17:04:08 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(t_swap *stack, int flag)
{
	int	tmp;

	if (stack && stack->next)
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
		if (flag == 1)
			write(1, "sa\n", 3);
	}
}

void	swap_b(t_swap *stack, int flag)
{
	int	tmp;

	if (stack && stack->next)
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
		if (flag == 1)
			write(1, "sb\n", 3);
	}
}

void	ss(t_swap *stacka, t_swap *stackb, int flag)
{
	int	tmp;

	if (stacka && stacka->next && stackb && stackb->next)
	{
		tmp = stacka->content;
		stacka->content = stacka->next->content;
		stacka->next->content = tmp;
		tmp = stackb->content;
		stackb->content = stackb->next->content;
		stackb->next->content = tmp;
		if (flag == 1)
			write(1, "ss\n", 3);
	}
}

void	rotate_a(t_swap **stack, int flag)
{
	t_swap	*first_node;
	t_swap	*last_node;

	if (stack && *stack && (*stack)->next)
	{
		first_node = *stack;
		*stack = (*stack)->next;
		last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		first_node->next = NULL;
		last_node->next = first_node;
		if (flag == 1)
			write(1, "ra\n", 3);
	}
}

void	rotate_b(t_swap **stack, int flag)
{
	t_swap	*first_node;
	t_swap	*last_node;

	if (stack && *stack && (*stack)->next)
	{
		first_node = *stack;
		*stack = (*stack)->next;
		last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		first_node->next = NULL;
		last_node->next = first_node;
		if (flag == 1)
			write(1, "rb\n", 3);
	}
}
