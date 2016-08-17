/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:54:33 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/09 20:54:35 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*sf;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	sf = (char *)malloc(sizeof(char) * (i + j) + 1);
	if (sf == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		sf[i] = s1[i];
	while (s2[++j])
		sf[i + j] = s2[j];
	sf[i + j] = '\0';
	return (sf);
}
