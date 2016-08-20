/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:47:54 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/06 17:47:57 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*s;
	size_t	i;

	s = (char *)malloc(sizeof(char) * size);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		s[i++] = '\0';
	return ((void *)s);
}
