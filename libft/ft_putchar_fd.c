/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:55:28 by ujyzene           #+#    #+#             */
/*   Updated: 2019/04/05 02:07:20 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_print(int c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putchar_fd(int c, int fd)
{
	if (c < 0x80)
	{
		ft_print(c, fd);
	}
	else if (c < 0x800)
	{
		ft_print(0xC0 | (c >> 6), fd);
		ft_print(0x80 | (c & 0x3F), fd);
	}
	else if (c < 0x10000)
	{
		ft_print(0xE0 | (c >> 12), fd);
		ft_print(0x80 | ((c >> 6) & 0x3F), fd);
		ft_print(0x80 | (c & 0x3F), fd);
	}
	else if (c < 0x200000)
	{
		ft_print(0xF0 | (c >> 18), fd);
		ft_print(0x80 | ((c >> 12) & 0x3F), fd);
		ft_print(0x80 | ((c >> 6) & 0x3F), fd);
		ft_print(0x80 | (c & 0x3F), fd);
	}
}
