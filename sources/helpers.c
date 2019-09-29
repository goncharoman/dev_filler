/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:56:27 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/29 15:13:17 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	set_me_en(char c, char en, char me)
{
	if (c == '.')
		return (0);
	else if (c == en || ft_toupper(c) == en)
		return (EN);
	else if (c == me || ft_toupper(c) == me)
		return (ME);
	else
		return (-3);
}

int set_str_dot(char c, char star, char dot)
{
	if (c == star) // star (*)
		return (1);
	else if (c == dot) // dot (.)
		return (0);
	return (-1);
}

void free_data(t_filler *filler)
{
	// ft_arrdel(&(filler->map->data));
	// ft_arrdel(&(filler->token->data));
	ft_memdel((void**)&(filler->map))  ;
	ft_memdel((void**)&(filler->token));
}
