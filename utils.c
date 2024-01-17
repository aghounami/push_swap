/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:36:54 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/17 12:58:36 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int med(z_list *stack)
{
    int max = INT_MIN;
    int min = INT_MAX;
    z_list *tmp = stack;
    while (stack)
    {
        if (stack->content > max)
            max = stack->content;
        stack = stack->next;
    }
    while (tmp)
    {
        if (tmp->content < min)
            min = tmp->content;
        tmp = tmp->next;
    }
    return ((max + min) / 2);
}

int find_target(z_list *stack_a, int b)
{
    int target = INT_MIN;
    z_list *stack__a = stack_a;
    while (stack_a)
    {
        if (stack_a->content > b)
        {
            if (target == INT_MIN || stack_a->content < target)
                target = stack_a->content;
        }
        stack_a = stack_a->next;
    }
    if (target == INT_MIN)
    {
        target = INT_MAX;
        while (stack__a)
        {
            if(stack__a->content < target)
                target = stack__a->content;
            stack__a = stack__a->next;
        }
    }
    return (target);
}

void b_target(z_list *stack_a, z_list *stack_b)
{
    while (stack_b)
    {
        stack_b->target = find_target(stack_a, stack_b->content);
        stack_b = stack_b->next;
    }
}

void findex(z_list **stack)
{
    int i = 0;
    z_list *ind_stack = *stack;
    while (ind_stack)
    {
        (ind_stack)->index = i;
        i++;
        (ind_stack) = (ind_stack)->next;
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