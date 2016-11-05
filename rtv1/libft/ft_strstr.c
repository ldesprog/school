/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:03:49 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/04 16:03:51 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (s2[0] == '\0')
		return ((char*)s1);
	i = 0;
	while (s1[i])
	{
		j = 0;
		res = (char*)&s1[i];
		while (s1[i++] == s2[j])
		{
			if (s2[++j] == '\0')
				return (res);
			if (s1[i] == s2[j - 1] && s1[i] != s2[j])
				i--;
		}
	}
	return (NULL);
}
