/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:43:02 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/19 21:07:12 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(t_swap *stack)
{
	int	tmp;

	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	printf("sa\n");
}

void	rotate_a(t_swap **stack)
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
		printf("ra\n");
	}
}

void	rotate_b(t_swap **stack)
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
		printf("rb\n");
	}
}

void	rev_rotate_a(t_swap **stack)
{
	t_swap	*second_last;
	t_swap	*new_head;

	if (stack && *stack && (*stack)->next)
	{
		second_last = *stack;
		while (second_last->next->next)
			second_last = second_last->next;
		new_head = second_last->next;
		second_last->next = NULL;
		new_head->next = *stack;
		*stack = new_head;
		printf("rra\n");
	}
}

void	rev_rotate_b(t_swap **stack)
{
	t_swap	*second_last;
	t_swap	*new_head;

	if (stack && *stack && (*stack)->next)
	{
		second_last = *stack;
		while (second_last->next->next)
			second_last = second_last->next;
		new_head = second_last->next;
		second_last->next = NULL;
		new_head->next = *stack;
		*stack = new_head;
		printf("rrb\n");
	}
}
