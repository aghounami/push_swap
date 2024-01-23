/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:25:05 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/23 18:17:18 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
				errormsg("Error\n", stack_a);
			stack_arg(split, &stack_a);
			i++;
		}
		duplicate(stack_a);
		turk_algo(&stack_a, &stack_b);
	}
	ft_free(stack_a);
	ft_free(stack_b);
	exit(0);
}
