/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:20:22 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/19 22:47:24 by aghounam         ###   ########.fr       */
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
				errormsg("Error");
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
			return ;
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

int	main(int argc, char **argv)
{
	t_swap	*stack_a;
	t_swap	*stack_b;
	char	**split;
	int		i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
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
	}
	leak(stack_a);
	leak(stack_b);
	exit(0);
}
