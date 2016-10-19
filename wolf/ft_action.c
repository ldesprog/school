/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:24:28 by ldesprog          #+#    #+#             */
/*   Updated: 2016/10/19 17:24:30 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_change_map(t_env *e)
{
	ft_free_map(e);
	ft_init_env(e);
	e->end = 0;
	e->nb += 1;
	if (e->nb >= e->ac)
		e->nb = 1;
	ft_init_map(e, e->av[e->nb]);
}

void	ft_destroy_case(t_env *e, int mode)
{
	t_pos a;
	t_pos t;

	if (mode == 1)
		ft_init_wall_hori(e, e->player->dir, &a, &t);
	else
		ft_init_wall_verti(e, e->player->dir, &a, &t);
	if (e->map[(int)a.y / e->size][(int)a.x / e->size] == 4)
		e->map[(int)a.y / e->size][(int)a.x / e->size] = 0;
}

void	ft_action_3(t_env *e, float dist, int nb_case, int mode)
{
	if (dist < 1500)
	{
		if (nb_case == 3)
			ft_change_map(e);
		else if (nb_case == 4)
			ft_destroy_case(e, mode);
	}
}

void	ft_action_2(t_env *e)
{
	if (e->b == -1 || (e->a != -1 && e->a < e->b))
		ft_action_3(e, e->a, e->nb_case_a, 1);
	else
		ft_action_3(e, e->b, e->nb_case_b, 2);
}

void	ft_action(t_env *e)
{
	if (e->player->dir != 0 && e->player->dir != 180)
		e->a = ft_wall_hori(e, e->player->dir);
	else
		e->a = -1;
	if (e->player->dir != 90 && e->player->dir != 270)
		e->b = ft_wall_verti(e, e->player->dir);
	else
		e->b = -1;
	ft_action_2(e);
}
