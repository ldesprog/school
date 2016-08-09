/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:52:56 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/06 13:53:03 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (((unsigned char)*(char *)s1) != ((unsigned char)*(char *)s2))
		{
			return (((unsigned int)(unsigned char)(*(char *)s1)) \
			- ((unsigned int)(unsigned char)(*(char *)s2)));
		}
		s1++;
		s2++;
	}
	return (0);
}
