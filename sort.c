/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:43:02 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/18 20:31:58 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void swap_a(z_list *stack)
{
	int tmp;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	printf("sa\n");
}

void rotate_a(z_list **stack)
{
    if (stack && *stack && (*stack)->next)
    {
        z_list *first_node = *stack;
        *stack = (*stack)->next;

        z_list *last_node = *stack;
        while (last_node->next)
            last_node = last_node->next;
        first_node->next = NULL;
        last_node->next = first_node;
        printf("ra\n");
    }
}

void rev_rotate_a(z_list **stack)
{
    if (stack && *stack && (*stack)->next)
    {
        z_list *second_last = *stack;
       while (second_last->next->next)
            second_last = second_last->next;
		z_list *new_head = second_last->next;
        second_last->next = NULL;
        new_head->next = *stack;
        *stack = new_head;
        printf("rra\n");
    }
}


void sort_3(z_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->next->content && (*stack_a)->content < (*stack_a)->next->content)
		rev_rotate_a(stack_a);
	else if ((*stack_a)->content > (*stack_a)->next->next->content && (*stack_a)->next->next->content < (*stack_a)->next->content)
	{
		rotate_a(stack_a);
		swap_a(*stack_a);
	}
	else if ((*stack_a)->content > (*stack_a)->next->next->content && (*stack_a)->next->next->content > (*stack_a)->next->content)
		rotate_a(stack_a);
	else if ((*stack_a)->content > (*stack_a)->next->content && (*stack_a)->next->next->content > (*stack_a)->content)
		swap_a((*stack_a));
	else if ((*stack_a)->next->next->content > (*stack_a)->content && (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		rev_rotate_a(stack_a);
		swap_a(*stack_a);
	}
}
