/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:26:19 by aghounam          #+#    #+#             */
/*   Updated: 2023/11/16 10:53:07 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	if ((dst == NULL && src == NULL) || !size)
	{
		if (src && !size)
			return (ft_strlen(src));
		return (0);
	}
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	if (size <= dstlen)
		return (srclen + size);
	while (src[i] && dstlen + i + 1 < (size))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if (dstlen + i < size)
	{
		dst[dstlen + i] = '\0';
	}
	return (dstlen + srclen);
}
