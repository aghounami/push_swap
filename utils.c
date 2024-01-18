/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:36:54 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/19 00:14:44 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void find_target(z_list **stack_a, z_list *stack_b)
{
    int target = INT_MIN;
    z_list *stack__a = *stack_a;
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
    {
        target = INT_MAX;
        z_list *stacka = *stack_a;
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
}

void b_target(z_list **stack_a, z_list **stack_b)
{
    z_list *lisbt = *stack_b;
    while (lisbt)
    {
        find_target(stack_a, lisbt);
        printf("Target : %d | for %d\n", lisbt->target_node->content, lisbt->content);
        lisbt = lisbt->next;
    }
}

void findex(z_list *stack)
{
    int i = 0;
    int median;
    
    if (!stack)
        return ;
    median = flstsize(stack) / 2;
    while (stack)
    {
        (stack)->index = i;
        if (i <= median)
            stack->above_median = 1;
        else
            stack->above_median = 0;
        i++;
        (stack) = (stack)->next;
    }
}

void printstack(z_list **stack)
{
    z_list *print = *stack;
    while (print)
    {
        printf("%d\n", print->content);
        print = print->next;
    }
}
