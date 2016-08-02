/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:40:14 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/06 10:40:16 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*inter;
	char	*dst2;
	size_t	i;

	i = 0;
	inter = (char *)malloc(sizeof(char) * 10);
	while (i < len)
		inter[i++] = *(char *)src++;
	dst2 = (char *)dst;
	i = 0;
	while (i < len)
	{
		dst2[i] = inter[i];
		i++;
	}
	return (dst);
}
