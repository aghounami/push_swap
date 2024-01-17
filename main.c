/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:20:22 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/17 13:04:45 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void checkarg(char **str)
{
	int i;
	int j;
	j = 1;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (!ft_isdigit(str[j][i]) && str[j][i] != 32 && str[j][i] != '+' && str[j][i] != '-')
				errormsg("Error");
			i++;
		}
		j++;
	}
}

void stack_arg(char **str, z_list **stack_a)
{
	int i = 0;
	static z_list *head = NULL;
	z_list *new;
	while (str[i])
	{
		long content = fatoi(str[i]);
		if (content > INT_MAX || content < INT_MIN)
			errormsg("Error");
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

int main(int argc, char **argv)
{
	// system("leaks push_swap");
	z_list *stack_a = NULL;
	z_list *stack_b = NULL;
	int i = 1;
	char **split;
	if (argc > 1)
	{
		checkarg(argv);
		while (argv[i])
		{
			split = ft_split(argv[i], ' ');
			if (split[0] == NULL)
				errormsg("Error");
			stack_arg(split, &stack_a);
			i++;
		}
		duplicate(stack_a);
		push_algo(&stack_a, &stack_b);
		// algo_swap(stack_a, stack_b);
		// printf("stack b:\n");
		// printf("stack a:\n");
		// sort_3(&stack_a);
		// findex(&stack_a);
		// rotate_a(&stack_a);
		printf("stack b:\n");
		printstack(&stack_b);
		printf("-----------\n");
		printf("stack a:\n");
		printstack(&stack_a);
		while (stack_b)
		{
			printf("%d\n", stack_b->target);
			stack_b = stack_b->next;
		}
	}
	leak(stack_a);
	exit(0);
}
