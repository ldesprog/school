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
		reste2->contenue = ft_strdup(ft_strchr(buf, '\n') + 1);
	else
		reste2->contenue = ft_strdup(buf);
	return (reste2->contenue);
}

int			ft_save_reste(t_list_get **reste, char *buf, int fd, int ret)
{
	t_list_get	*reste2;

	if (ret == 1)
	{
		reste2 = *reste;
		while (reste2 && reste2->fd != fd)
			if (reste2->fd != fd)
				reste2 = reste2->next;
		if (reste2)
		{
			if (reste2->contenue)
				free(reste2->contenue);
			reste2->contenue = ft_save_reste2(buf, reste2);
			free(buf);
			return (ret);
		}
		reste2 = (t_list_get *)malloc(sizeof(t_list_get));
		reste2->next = *reste;
		reste2->fd = fd;
		reste2->contenue = ft_save_reste2(buf, reste2);
		*reste = reste2;
	}
	free(buf);
	return (ret);
}

void		ft_init_gnl(char **buf, char **line, int *nb_char, int *ret)
{
	*buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	*line = (char *)malloc(sizeof(char));
	**line = 0;
	*nb_char = 0;
	*ret = 0;
}

int			get_next_line(int const fd, char **line)
{
	char				*buf;
	int					ret;
	int					nb_char;
	static t_list_get	*reste;

	if (line == NULL)
		return (-1);
	ft_init_gnl(&buf, line, &nb_char, &ret);
	ft_strcpy(buf, ft_get_reste(reste, &nb_char, fd, buf));
	while (ft_strchr(buf, '\n') == NULL)
	{
		nb_char += ret;
		*line = ft_remalloc(*line, nb_char);
		ft_strncat(*line, buf, nb_char);
		ft_bzero(buf, BUFF_SIZE + 1);
		if ((ret = read(fd, buf, BUFF_SIZE)) <= 0 && nb_char == 0)
			return (ft_save_reste(&reste, buf, fd, ret));
		if (ret == 0 && nb_char > 0)
			return (ft_save_reste(&reste, buf, fd, 1));
	}
	nb_char += ft_strchr(buf, '\n') - buf + 1;
	*line = ft_remalloc(*line, nb_char);
	ft_strlcat(*line, buf, nb_char);
	return (ft_save_reste(&reste, buf, fd, 1));
}
