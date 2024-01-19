/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:38:02 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/19 21:06:27 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_swap	*listnew(int content)
{
	t_swap	*new;

	new = (t_swap *)malloc(sizeof(t_swap));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_swap	*listlast(t_swap *lst)
{
	if (lst)
	{
		while (lst)
		{
			if (!lst->next)
				return (lst);
			lst = lst->next;
		}
	}
	return (lst);
}

void	listadd_back(t_swap **lst, t_swap *new)
{
	t_swap	*last;

	if (!lst || !new)
		return ;
	last = listlast(*lst);
	if (*lst)
		last->next = new;
	else
		*lst = new;
}

int	flstsize(t_swap *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	flstadd_front(t_swap **lst, t_swap *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
