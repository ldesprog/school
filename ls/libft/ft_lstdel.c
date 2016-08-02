/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:27:25 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/12 17:27:27 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *nxt;

	if (alst && del && *alst)
	{
		nxt = *alst;
		while ((*alst) != NULL)
		{
			del((*alst)->content, (*alst)->content_size);
			nxt = (*alst)->next;
			free(*alst);
			*alst = nxt;
		}
		*alst = NULL;
	}
}
