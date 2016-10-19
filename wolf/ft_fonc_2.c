/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonc_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:40:06 by ldesprog          #+#    #+#             */
/*   Updated: 2016/10/19 17:40:07 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_len_str(char *str)
{
	int n;
	int i;

	i = 0;
	n = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		n++;
		while (str[i] && str[i] != ' ')
			i++;
		while (str[i] == ' ')
			i++;
	}
	return (n);
}

void	ft_init_key(t_env *env)
{
	env->key = (t_key *)malloc(sizeof(t_key));
	env->key->key_quit = ECHAP;
	env->key->key_menu = TAB;
	env->key->key_menu_v = 0;
	env->key->key_enter = RETURN;
	env->key->key_enter_v = 0;
	env->key->key_up = UP;
	env->key->key_up_v = 0;
	env->key->key_down = DOWN;
	env->key->key_down_v = 0;
	env->key->key_left = LEFT;
	env->key->key_left_v = 0;
	env->key->key_right = RIGHT;
	env->key->key_right_v = 0;
	env->key->add_new_key = 0;
	env->key->time_menu = 0;
	env->key->key_enter_c = 0;
	env->key->key_action = ESPACE;
}

int		ft_red_cross(t_env *e)
{
	ft_free(e);
	return (0);
}

void	ft_init_key_v(t_env *e)
{
	e->key->key_menu_v = 1;
	e->key->key_enter_v = 0;
	e->key->key_up_v = 0;
	e->key->key_down_v = 0;
	e->key->key_left_v = 0;
	e->key->key_right_v = 0;
}
