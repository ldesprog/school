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

char	*ft_print_key_5(int key, t_env *e, int *i, int ligne)
{
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
	return (ft_print_key_6(key, e, i, ligne));
}

char	*ft_print_key_4(int key, t_env *e, int *i, int ligne)
{
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
	return (ft_print_key_5(key, e, i, ligne));
}

char	*ft_print_key_3(int key, t_env *e, int *i, int ligne)
{
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
	return (ft_print_key_4(key, e, i, ligne));
}

char	*ft_print_key_2(int key, t_env *e, int *i, int ligne)
{
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
	return (ft_print_key_3(key, e, i, ligne));
}

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
	return (ft_print_key_2(key, e, i, ligne));
}
