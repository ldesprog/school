/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:06:24 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/04 15:06:26 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char		*res;
	size_t		i;
	size_t		j;

	if (s2[0] == '\0')
		return ((char*)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		res = (char*)&s1[i];
		while (s1[i++] == s2[j] && i <= n)
		{
			if (s2[++j] == '\0')
				return (res);
			if (s1[i] == s2[j - 1] && s1[i] != s2[j])
				i--;
		}
	}
	return (NULL);
}
