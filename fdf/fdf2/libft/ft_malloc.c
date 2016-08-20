/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 02:55:04 by ldesprog          #+#    #+#             */
/*   Updated: 2015/01/28 02:55:06 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(int i)
{
	void	*new;

	new = (void	*)malloc(i);
	if (!new)
		exit(0);
	return (new);
}
