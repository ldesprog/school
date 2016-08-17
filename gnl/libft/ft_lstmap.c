/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 13:32:38 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/13 13:32:39 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *new2;
	t_list *elem;

	if (lst && f)
	{
		elem = lst;
		new = f(elem);
		if (lst->next != NULL)
		{
			elem = lst->next;
			new->next = f(elem);
			new2 = new->next;
		}
		while (elem->next != NULL)
		{
			elem = elem->next;
			new2->next = f(elem);
			new2 = new2->next;
		}
		return (new);
	}
	return (NULL);
}
