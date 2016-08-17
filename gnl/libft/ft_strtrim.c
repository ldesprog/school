/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 21:20:43 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/09 21:20:45 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*s2;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = 0;
	while (s[i + j])
		j++;
	j--;
	while ((s[i + j] == ' ' || s[i + j] == '\n' || s[i + j] == '\t') && j != -1)
		j--;
	s2 = (char *)malloc(sizeof(char) * (j + 2));
	if (s2 == NULL)
		return (NULL);
	k = -1;
	j++;
	while (++k < j)
		s2[k] = s[i + k];
	s2[k] = '\0';
	return (s2);
}
