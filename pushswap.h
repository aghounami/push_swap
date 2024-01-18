/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:21:22 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/19 00:11:21 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <libc.h>
# include "./libfft/libft.h"

typedef struct z_list
{
	int				content;
	int				index;
	int				mouve;
	int				cost;
	int				above_median;
	struct z_list	*target_node;
	struct z_list	*next;
}	z_list;


z_list	*listnew(int content);
z_list	*listlast(z_list *lst);
void	listadd_back(z_list **lst, z_list *new);
int		flstsize(z_list *lst);
long	fatoi(const char *str);
void	swap_a(z_list *stack);
void	rotate_a(z_list **stack);
void	rev_rotate_a(z_list **stack);
void	sort_3(z_list **stack_a);
void	duplicate(z_list *stack);
void	errormsg(char *s);
void	leak(z_list *list);
void	flstadd_front(z_list **lst, z_list *new);
void	push_a_to_b(z_list **stack_a, z_list **stack_b);
void	push_algo(z_list **stack_a, z_list **stack_b);
void	algo_swap(z_list **stack_a, z_list **stack_b);
int		med(z_list *stack);
void 	b_target(z_list **stack_a, z_list **stack_b);
void	findex(z_list *stack);
void	printstack(z_list **stack);
void	push_b_to_a(z_list **stack_b, z_list **stack_a);
void	find_target(z_list **stack_a, z_list *stack_b);
// void	cheapest(z_list *stack, int m, int size);
void	cost(z_list **stacka, z_list **stackb);
z_list	*next_step(z_list **stack_b);
void	top(z_list **stack_a);
void	push_top(z_list **stacka, z_list **stackb, z_list *cheapest);

#endif
