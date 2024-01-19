/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:31:10 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/19 21:06:59 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_a_to_b(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*temp;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	flstadd_front(stack_b, temp);
	printf("pb\n");
}

void	push_b_to_a(t_swap **stack_b, t_swap **stack_a)
{
	t_swap	*temp;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	flstadd_front(stack_a, temp);
	printf("pa\n");
}

void	rrr(t_swap **stacka, t_swap **stackb)
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
		printf("rrr\n");
	}
}

void	rr(t_swap **stacka, t_swap **stackb)
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
		printf("rr\n");
	}
}

void	sort_3(t_swap **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->content < (*stack_a)->next->content)
		rev_rotate_a(stack_a);
	else if ((*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->next->content < (*stack_a)->next->content)
	{
		rotate_a(stack_a);
		swap_a(*stack_a);
	}
	else if ((*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->next->content > (*stack_a)->next->content)
		rotate_a(stack_a);
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->next->next->content > (*stack_a)->content)
		swap_a((*stack_a));
	else if ((*stack_a)->next->next->content > (*stack_a)->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		rev_rotate_a(stack_a);
		swap_a(*stack_a);
	}
}
