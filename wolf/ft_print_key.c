/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:59:22 by ldesprog          #+#    #+#             */
/*   Updated: 2016/10/19 16:59:24 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char	*ft_print_key(int key, t_env *e, int *i, int ligne)
{
	if (e->key->add_new_key == 2 && *i == 1 && ligne == e->key->pos_curseur)
	{
		*i = 2;
		return (ft_print_key(e->key->new_key, e, i, ligne));
	}
	if (key == 53)
		return ("echap");
	if (key == 50)
		return ("~");
	if (key == 18)
		return ("!");
	if (key == 19)
		return ("@");
	if (key == 20)
		return ("#");
	if (key == 21)
		return ("$");
	if (key == 23)
		return ("%");
	if (key == 22)
		return ("^");
	if (key == 26)
		return ("&");
	if (key == 28)
		return ("*");
	if (key == 25)
		return ("(");
	if (key == 29)
		return (")");
	if (key == 27)
		return ("_");
	if (key == 24)
		return ("+");
	if (key == 51)
		return ("delete");
	if (key == 48)
		return ("tab");
	if (key == 12)
		return ("Q");
	if (key == 13)
		return ("W");
	if (key == 14)
		return ("E");
	if (key == 15)
		return ("R");
	if (key == 17)
		return ("T");
	if (key == 16)
		return ("Y");
	if (key == 32)
		return ("U");
	if (key == 34)
		return ("I");
	if (key == 31)
		return ("O");
	if (key == 35)
		return ("P");
	if (key == 33)
		return ("{");
	if (key == 30)
		return ("}");
	if (key == 42)
		return ("|");
	if (key == 0)
		return ("A");
	if (key == 1)
		return ("S");
	if (key == 2)
		return ("D");
	if (key == 3)
		return ("F");
	if (key == 5)
		return ("G");
	if (key == 4)
		return ("H");
	if (key == 38)
		return ("J");
	if (key == 40)
		return ("K");
	if (key == 37)
		return ("L");
	if (key == 41)
		return (":");
	if (key == 39)
		return ("\"");
	if (key == 36)
		return ("return");
	if (key == 257)
		return ("left shift");
	if (key == 6)
		return ("Z");
	if (key == 7)
		return ("X");
	if (key == 8)
		return ("C");
	if (key == 9)
		return ("V");
	if (key == 11)
		return ("B");
	if (key == 45)
		return ("N");
	if (key == 46)
		return ("M");
	if (key == 43)
		return ("<");
	if (key == 47)
		return (">");
	if (key == 44)
		return ("?");
	if (key == 258)
		return ("right shift");
	if (key == 256)
		return ("left control");
	if (key == 261)
		return ("left option");
	if (key == 259)
		return ("left command");
	if (key == 49)
		return ("space");
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
	return ("error");
}
