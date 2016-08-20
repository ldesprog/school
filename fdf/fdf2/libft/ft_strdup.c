/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:05:10 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/06 15:05:11 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		cmp;
	int		i;

	cmp = 0;
	while (s1[cmp])
		cmp++;
	s2 = (char *)malloc(sizeof(char) * cmp);
	if (!s2)
		return (NULL);
	i = 0;
	while (i <= cmp)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
