/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:56:27 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/03 18:07:30 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

// следующие 2 функции передавются в вызов init_imap
// нужны для интерпритации смволов в индексной карте

// для filler->map: заменяет симовол нашего игрока на -2, противника на -1
int	set_me_en(char c, char en, char me)
{
	if (c == '.')
		return (0);
	// это для нововй filler VM
	else if (c == en || ft_toupper(c) == en)
		return (EN);
	else if (c == me || ft_toupper(c) == me)
		return (ME);
	else
		return (-3);
}

// для filler->token: заменяет символ '*' на 1 и символ '.' на 0
int set_str_dot(char c, char star, char dot)
{
	if (c == star) // star (*)
		return (1);
	else if (c == dot) // dot (.)
		return (0);
	return (-3);
}

// применяется для t_pos структуры для установки значений x и y
void pos_set(t_pos *p, int x, int y)
{
	p->x = x;
	p->y = y;
}

int return_error(char *msg)
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
