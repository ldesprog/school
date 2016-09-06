/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:48:54 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/07 12:48:55 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	s = (char *)malloc(sizeof(char) * size);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i++ < size)
		s[i] = '\0';
	return (s);
}
