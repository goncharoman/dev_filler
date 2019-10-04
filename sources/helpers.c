/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:56:27 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/04 15:18:11 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		set_me_en(char c, char en, char me)
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

int		set_str_dot(char c, char star, char dot)
{
	if (c == star)
		return (1);
	else if (c == dot)
		return (0);
	return (-3);
}

void	pos_set(t_pos *p, int x, int y)
{
	p->x = x;
	p->y = y;
}

int		return_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	if (errno != 0)
	{
		ft_putstr_fd("\t{", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('}', 2);
	}
	ft_putchar_fd('\n', 2);
	return (0);
}
