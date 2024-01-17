/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:14:01 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/17 12:52:13 by aghounam         ###   ########.fr       */
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
    {
        algo_swap(stack_a, stack_b);
        b_target(*stack_a, *stack_b);
    }
}

void algo_swap(z_list **stack_a, z_list **stack_b)
{
    int medd = med(*stack_a);
    while (flstsize(*stack_a) > 3)
    {
        z_list *stack;
        if ((*stack_a)->content >= medd)
        {
            stack = (*stack_a)->next;
            push_a_to_b(stack_a, stack_b);
            rotate_a(stack_b);
            *stack_a = stack;
        }
        else
        {
            stack = (*stack_a)->next;
            push_a_to_b(stack_a, stack_b);
            *stack_a = stack;
        }
    }
    // exit (1);
    sort_3(stack_a);
}
