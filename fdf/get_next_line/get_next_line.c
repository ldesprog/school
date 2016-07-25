/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 14:53:54 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/24 14:53:56 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_get_reste(t_list_get *reste, int *nb_char, int fd, char *buf)
{
	t_list_get	*reste2;

	if (reste == NULL)
		return (buf);
	reste2 = reste;
	while (reste2 && reste2->fd != fd)
		reste2 = reste2->next;
	if (reste2 == NULL)
		return (buf);
	if (ft_strchr(reste2->contenue, '\n') == NULL)
		*nb_char = ft_strlen(reste2->contenue);
	return (reste2->contenue);
}

char		*ft_save_reste2(char *buf, t_list_get *reste2)
{
	if (ft_strchr(buf, '\n'))
	{
		reste2->contenue = (char *)malloc(sizeof(char) *
			(ft_strlen(ft_strchr(buf, '\n'))));
		reste2->contenue = ft_strdup(ft_strchr(buf, '\n') + 1);
	}
	else
	{
		reste2->contenue = (char *)malloc(sizeof(char) * (ft_strlen(buf)));
		reste2->contenue = ft_strdup(buf);
	}
	return (reste2->contenue);
}

t_list_get	*ft_save_reste(char *buf, t_list_get **reste, int fd)
{
	t_list_get	*reste2;

	reste2 = *reste;
	while (reste2 && reste2->fd != fd)
	{
		if (reste2->fd != fd)
			reste2 = reste2->next;
	}
	if (reste2)
	{
		if (reste2->contenue)
			free(reste2->contenue);
		reste2->contenue = ft_save_reste2(buf, reste2);
		return (*reste);
	}
	reste2 = (t_list_get *)malloc(sizeof(t_list_get));
	reste2->next = *reste;
	reste2->fd = fd;
	reste2->contenue = ft_save_reste2(buf, reste2);
	return (reste2);
}

int			ft_send_save(t_list_get **reste, char *buf, int fd)
{
	*reste = ft_save_reste(buf, reste, fd);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	char				*buf;
	int					ret;
	int					nb_char;
	static t_list_get	*reste;

	buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	ft_bzero(buf, BUFF_SIZE + 1);
	nb_char = 0;
	ret = 0;
	ft_strcpy(buf, ft_get_reste(reste, &nb_char, fd, buf));
	while (ft_strchr(buf, '\n') == NULL)
	{
		nb_char += ret;
		*line = ft_remalloc(*line, nb_char);
		ft_strncat(*line, buf, nb_char);
		ft_bzero(buf, BUFF_SIZE + 1);
		if ((ret = read(fd, buf, BUFF_SIZE)) <= 0 && nb_char == 0)
			return (ret);
		if (ret == 0 && nb_char > 0)
			return (ft_send_save(&reste, "\0", fd));
	}
	nb_char += ft_strchr(buf, '\n') - buf + 1;
	*line = ft_remalloc(*line, nb_char);
	ft_strlcat(*line, buf, nb_char);
	return (ft_send_save(&reste, buf, fd));
}
