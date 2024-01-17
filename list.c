/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:38:02 by aghounam          #+#    #+#             */
/*   Updated: 2024/01/16 22:53:16 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


z_list	*listnew(int content)
{
	z_list	*new;

	new = (z_list *)malloc(sizeof(z_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

z_list	*listlast(z_list *lst)
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

void	listadd_back(z_list **lst, z_list *new)
{
	z_list	*last;

	if (!lst || !new)
		return ;
	last = listlast(*lst);
	if (*lst)
		last->next = new;
	else
		*lst = new;
}

int	flstsize(z_list *lst)
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

void	flstadd_front(z_list **lst, z_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
