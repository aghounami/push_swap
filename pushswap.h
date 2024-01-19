/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:21:22 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/19 22:49:31 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <libc.h>
# include "./libfft/libft.h"

typedef struct s_swap
{
	int				content;
	int				index;
	int				mouve;
	int				cost;
	int				above_median;
	struct s_swap	*target_node;
	struct s_swap	*next;
}	t_swap;

t_swap	*listnew(int content);
t_swap	*listlast(t_swap *lst);
void	listadd_back(t_swap **lst, t_swap *new);
int		flstsize(t_swap *lst);
long	fatoi(const char *str);
void	swap_a(t_swap *stack);
void	rotate_a(t_swap **stack);
void	rotate_b(t_swap **stack);
void	rev_rotate_a(t_swap **stack);
void	rev_rotate_b(t_swap **stack);
void	sort_3(t_swap **stack_a);
void	duplicate(t_swap *stack);
void	errormsg(char *s);
void	leak(t_swap *list);
void	flstadd_front(t_swap **lst, t_swap *new);
void	push_a_to_b(t_swap **stack_a, t_swap **stack_b);
void	push_algo(t_swap **stack_a, t_swap **stack_b);
void	algo_swap(t_swap **stack_a, t_swap **stack_b);
void	b_target(t_swap **stack_a, t_swap **stack_b);
void	findex(t_swap *stack);
void	printstack(t_swap **stack);
void	push_b_to_a(t_swap **stack_b, t_swap **stack_a);
void	find_target(t_swap **stack_a, t_swap *stack_b);
void	cost(t_swap **stacka, t_swap **stackb);
t_swap	*cheapst_move(t_swap **stack_b);
void	top(t_swap **stack_a);
void	push_top(t_swap **stacka, t_swap **stackb, t_swap *cheapest);
void	rr(t_swap **stacka, t_swap **stackb);
void	rrr(t_swap **stacka, t_swap **stackb);
int		medien(t_swap *head);
// void	target_min(t_swap *stack_b, t_swap **stack_a);
int		check_if_sorted(t_swap **stacka);
int		mini_medien(t_swap *head);
void	next_step(t_swap **stack_a, t_swap **stack_b);

#endif
