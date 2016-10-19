/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_key_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:37:48 by ldesprog          #+#    #+#             */
/*   Updated: 2016/10/19 17:37:50 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char	*ft_print_key_error(t_env *e, int *i, int ligne)
{
	*i = -2;
	if (ligne == 0)
		return (ft_print_key(e->key->key_quit, e, i, ligne));
	if (ligne == 1)
		return (ft_print_key(e->key->key_menu, e, i, ligne));
	if (ligne == 2)
		return (ft_print_key(e->key->key_enter, e, i, ligne));
	if (ligne == 3)
		return (ft_print_key(e->key->key_up, e, i, ligne));
	if (ligne == 4)
		return (ft_print_key(e->key->key_down, e, i, ligne));
	if (ligne == 5)
		return (ft_print_key(e->key->key_right, e, i, ligne));
	if (ligne == 6)
		return (ft_print_key(e->key->key_left, e, i, ligne));
	if (ligne == 7)
		return (ft_print_key(e->key->key_action, e, i, ligne));
	return ("error");
}

char	*ft_print_key_8(int key, t_env *e, int *i, int ligne)
{
	if (key == 82)
		return ("0 (pad)");
	if (key == 65)
		return (". (pad)");
	if (key == 76)
		return ("enter (pad)");
	if (key == 123)
		return ("left");
	if (key == 124)
		return ("right");
	if (key == 125)
		return ("down");
	if (key == 126)
		return ("up");
	return (ft_print_key_error(e, i, ligne));
}

char	*ft_print_key_7(int key, t_env *e, int *i, int ligne)
{
	if (key == 67)
		return ("* (pad)");
	if (key == 89)
		return ("7 (pad)");
	if (key == 91)
		return ("8 (pad)");
	if (key == 92)
		return ("9 (pad)");
	if (key == 78)
		return ("- (pad)");
	if (key == 86)
		return ("4 (pad)");
	if (key == 87)
		return ("5 (pad)");
	if (key == 88)
		return ("6 (pad)");
	if (key == 69)
		return ("+ (pad)");
	if (key == 83)
		return ("1 (pad)");
	if (key == 84)
		return ("2 (pad)");
	if (key == 85)
		return ("3 (pad)");
	return (ft_print_key_8(key, e, i, ligne));
}

char	*ft_print_key_6(int key, t_env *e, int *i, int ligne)
{
	if (key == 260)
		return ("right command");
	if (key == 262)
		return ("right option");
	if (key == 269)
		return ("right control");
	if (key == 279)
		return ("fn");
	if (key == 115)
		return ("home");
	if (key == 116)
		return ("page up");
	if (key == 117)
		return ("right delete");
	if (key == 119)
		return ("end");
	if (key == 121)
		return ("page down");
	if (key == 71)
		return ("clear (pad)");
	if (key == 81)
		return ("= (pad)");
	if (key == 75)
		return ("/ (pad)");
	return (ft_print_key_7(key, e, i, ligne));
}
