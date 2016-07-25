/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:56:40 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/10 16:56:42 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_itoa_suite(char *num, int n, int nb)
{
	if (n < -9)
		ft_itoa_suite(num, (n / 10), (nb - 1));
	num[nb] = (n % 10 * -1 + 48);
}

char		*ft_itoa(int n)
{
	char	*num;
	int		nb;
	int		neg;
	int		n2;

	neg = 1;
	nb = 0;
	if (n > 0)
		neg = -1;
	n *= neg;
	n2 = n;
	while (n2 <= -1 && nb++ >= 0)
		n2 /= 10;
	num = (char *)ft_malloc(sizeof(char), (nb + 1));
	if (neg == 1)
	{
		nb++;
		if (n != 0)
			num[0] = '-';
	}
	ft_itoa_suite(num, n, (nb - 1));
	num[nb] = '\0';
	return (num);
}
