/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:31:10 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/20 21:42:06 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_a_to_b(t_swap **stack_a, t_swap **stack_b, int flag)
{
	t_swap	*temp;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	flstadd_front(stack_b, temp);
	if (flag == 1)
		write(1, "pb\n", 3);
}

void	push_b_to_a(t_swap **stack_b, t_swap **stack_a, int flag)
{
	t_swap	*temp;

	if (stack_b == NULL || *stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	flstadd_front(stack_a, temp);
	if (flag == 1)
		write(1, "pa\n", 3);
}

void	rrr(t_swap **stacka, t_swap **stackb, int flag)
{
	t_swap	*second_last;
	t_swap	*new_head;

	if ((stacka && *stacka && (*stacka)->next)
		&& (stackb && *stackb && (*stackb)->next))
	{
		second_last = *stacka;
		while (second_last->next->next)
			second_last = second_last->next;
		new_head = second_last->next;
		second_last->next = NULL;
		new_head->next = *stacka;
		*stacka = new_head;
		second_last = *stackb;
		while (second_last->next->next)
			second_last = second_last->next;
		new_head = second_last->next;
		second_last->next = NULL;
		new_head->next = *stackb;
		*stackb = new_head;
		if (flag == 1)
			write(1, "rrr\n", 4);
	}
}

void	rr(t_swap **stacka, t_swap **stackb, int flag)
{
	t_swap	*first_node;
	t_swap	*last_node;

	if ((stacka && *stacka && (*stacka)->next)
		&& (stackb && *stackb && (*stackb)->next))
	{
		first_node = *stacka;
		*stacka = (*stacka)->next;
		last_node = *stacka;
		while (last_node->next)
			last_node = last_node->next;
		first_node->next = NULL;
		last_node->next = first_node;
		first_node = *stackb;
		*stackb = (*stackb)->next;
		last_node = *stackb;
		while (last_node->next)
			last_node = last_node->next;
		first_node->next = NULL;
		last_node->next = first_node;
		if (flag == 1)
			write(1, "rr\n", 3);
	}
}

void	sort_3(t_swap **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->content < (*stack_a)->next->content)
		rev_rotate_a(stack_a, 1);
	else if ((*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->next->content < (*stack_a)->next->content)
	{
		rotate_a(stack_a, 1);
		swap_a(*stack_a, 1);
	}
	else if ((*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->next->content > (*stack_a)->next->content)
		rotate_a(stack_a, 1);
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->next->next->content > (*stack_a)->content)
		swap_a((*stack_a), 1);
	else if ((*stack_a)->next->next->content > (*stack_a)->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		rev_rotate_a(stack_a, 1);
		swap_a(*stack_a, 1);
	}
}
