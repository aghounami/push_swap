/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:25:49 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/23 18:12:30 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	so_rt(char *split, t_swap **stack_a, t_swap **stack_b)
{
	if (strcmp(split, "sa") == 0)
		swap_a(*stack_a, 0);
	else if (strcmp(split, "sb") == 0)
		swap_b(*stack_b, 0);
	else if (strcmp(split, "ss") == 0)
		ss(*stack_a, *stack_b, 0);
	else if (strcmp(split, "ra") == 0)
		rotate_a(stack_a, 0);
	else if (strcmp(split, "rb") == 0)
		rotate_b(stack_b, 0);
	else if (strcmp(split, "rr") == 0)
		rr(stack_a, stack_b, 0);
	else if (strcmp(split, "rra") == 0)
		rev_rotate_a(stack_a, 0);
	else if (strcmp(split, "rrb") == 0)
		rev_rotate_b(stack_b, 0);
	else if (strcmp(split, "rrr") == 0)
		rrr(stack_a, stack_b, 0);
	else if (strcmp(split, "pa") == 0)
		push_b_to_a(stack_b, stack_a, 0);
	else if (strcmp(split, "pb") == 0)
		push_a_to_b(stack_a, stack_b, 0);
	else
		errormsg("Error\n", *stack_a);
}

int	check_line(char *str)
{
	if (strcmp(str, "sa\n") == 0
		|| strcmp(str, "sb\n") == 0
		|| strcmp(str, "ss\n") == 0
		|| strcmp(str, "ra\n") == 0
		|| strcmp(str, "rb\n") == 0
		|| strcmp(str, "rr\n") == 0
		|| strcmp(str, "rra\n") == 0
		|| strcmp(str, "rrb\n") == 0
		|| strcmp(str, "rrr\n") == 0
		|| strcmp(str, "pa\n") == 0
		|| strcmp(str, "pb\n") == 0)
		return (1);
	else
		message_exit("Error\n");
	return (0);
}

void	next_check(t_swap **stack_a, t_swap **stack_b, char **split)
{
	while (*split)
	{
		so_rt(*split, stack_a, stack_b);
		split++;
	}
	if (check_if_sorted(stack_a) && flstsize(*stack_b) == 0)
	{
		write(1, "OK\n", 3);
		ft_free(*stack_a);
		ft_free(*stack_b);
		exit(0);
	}
	if (flstsize(*stack_b) != 0 || check_if_sorted(stack_a) == 0)
	{
		write(1, "KO\n", 3);
		ft_free(*stack_a);
		ft_free(*stack_b);
		exit(0);
	}
}

void	checker(t_swap **stack_a, t_swap **stack_b)
{
	char	*str;
	char	*line;
	char	**split;

	str = calloc(1, 1);
	if (!str)
		exit(1);
	line = get_next_line(0);
	while (line != NULL)
	{
		check_line(line);
		str = ft_strjoin(str, line);
		free(line);
		line = get_next_line(0);
	}
	split = ft_split(str, '\n');
	next_check(stack_a, stack_b, split);
	exit(0);
}
