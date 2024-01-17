/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:31:10 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/17 12:33:33 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void push_a_to_b(z_list **stack_a, z_list **stack_b)
{
    z_list *temp;

    if (stack_a == NULL || *stack_a == NULL)
        return;
    temp = *stack_a;
    *stack_a = (*stack_a)->next;
    temp->next = NULL;
    flstadd_front(stack_b, temp);
    write(1, "pb\n", 3);
}
void push_b_to_a(z_list **stack_b, z_list **stack_a)
{
    z_list *temp;

    if (stack_a == NULL || *stack_a == NULL)
        return;
    temp = *stack_b;
    *stack_b = (*stack_b)->next;
    temp->next = NULL;
    flstadd_front(stack_a, temp);
    write(1, "pa\n", 3);
}