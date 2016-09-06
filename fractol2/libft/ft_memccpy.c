/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:23:54 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/05 17:23:56 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (*(char *)src != (unsigned char)c && n-- != 0)
	{
		*(char *)dst++ = *(char *)src++;
	}
	if (*(char *)src == (unsigned char)c && n != 0)
	{
		*(char *)dst++ = *(char *)src++;
		return (dst);
	}
	return (NULL);
}
