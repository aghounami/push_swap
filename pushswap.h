/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:21:22 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/23 18:05:52 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H


# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./utils_bonus/get_next_line.h"

typedef struct s_swap
{
	int				content;
	int				index;
	int				mouve;
	int				index_value;
	int				above_median;
	struct s_swap	*target_node;
	struct s_swap	*next;
}	t_swap;

t_swap	*listnew(int content);
t_swap	*listlast(t_swap *lst);
void	listadd_back(t_swap **lst, t_swap *new);
int		flstsize(t_swap *lst);
long	fatoi(const char *str);
void	swap_a(t_swap *stack, int flag);
void	swap_b(t_swap *stack, int flag);
void	ss(t_swap *stacka, t_swap *stackb, int flag);
void	rotate_a(t_swap **stack, int flag);
void	rotate_b(t_swap **stack, int flag);
void	rev_rotate_a(t_swap **stack, int flag);
void	rev_rotate_b(t_swap **stack, int flag);
void	sort_3(t_swap **stack_a);
void	duplicate(t_swap *stack);
void	errormsg(char *s, t_swap *stack);
void	ft_free(t_swap *list);
void	flstadd_front(t_swap **lst, t_swap *new);
void	push_a_to_b(t_swap **stack_a, t_swap **stack_b, int flag);
void	turk_algo(t_swap **stack_a, t_swap **stack_b);
void	algo_swap(t_swap **stack_a, t_swap **stack_b);
void	b_target(t_swap **stack_a, t_swap **stack_b);
void	findex(t_swap *stack);
void	push_b_to_a(t_swap **stack_b, t_swap **stack_a, int flag);
void	find_target(t_swap **stack_a, t_swap *stack_b);
void	cost(t_swap **stacka, t_swap **stackb);
t_swap	*cheapst_move(t_swap **stack_b);
void	top(t_swap **stack_a);
void	push_top(t_swap **stacka, t_swap **stackb, t_swap *cheapest);
void	rr(t_swap **stacka, t_swap **stackb, int flag);
void	rrr(t_swap **stacka, t_swap **stackb, int flag);
int		medien(t_swap *head);
int		check_if_sorted(t_swap **stacka);
void	next_step(t_swap **stack_a, t_swap **stack_b);
void	index_value(t_swap *stacka);
int		ft_isdigit(int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(const char *s, int start, int len);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
void	checker(t_swap **stack_a, t_swap **stack_b);
void	so_rt(char *split, t_swap **stack_a, t_swap **stack_b);
void	next_check(t_swap **stack_a, t_swap **stack_b, char **split);
void	checkarg(char **str);
void	stack_arg(char **str, t_swap **stack_a);
void	message_exit(char *str);
t_swap	*mini_medien(t_swap *head);
void	ft_putstr_fd(char *s, int fd);

#endif
