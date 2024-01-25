/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:09:07 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/23 18:13:06 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	checkarg(char **str)
{
	int	i;
	int	j;

	j = 1;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (!ft_isdigit(str[j][i]) && str[j][i] != 32 &&
				str[j][i] != '+' && str[j][i] != '-')
				message_exit("Error\n");
			i++;
		}
		j++;
	}
}

void	stack_arg(char **str, t_swap **stack_a)
{
	static t_swap	*head = NULL;
	int				i;
	t_swap			*new;
	long			content;

	i = 0;
	while (str[i])
	{
		content = fatoi(str[i]);
		if (content > INT_MAX || content < INT_MIN)
			errormsg("Error\n", *stack_a);
		if (!head)
			head = listnew(content);
		else
		{
			new = listnew(content);
			listadd_back(&head, new);
			new = NULL;
		}
		free(str[i]);
		i++;
	}
	*stack_a = head;
	free(str);
}

void	rev_rotate_a(t_swap **stack, int flag)
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
		if (flag == 1)
			write(1, "rra\n", 4);
	}
}

void	rev_rotate_b(t_swap **stack, int flag)
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
		if (flag == 1)
			write(1, "rrb\n", 4);
	}
}

void	message_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}
