/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 02:08:37 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/24 12:09:09 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void fill_heat(t_filler *dest, int i, int x, int y)
{
	if (x + 1 < dest->x && dest->imap[y][x + 1] == i)
		dest->imap[y][x] = i + 1;
	if (y + 1 < dest->y && dest->imap[y + 1][x] == i)
		dest->imap[y][x] = i + 1;
	if (x + 1 < dest->x && y + 1 < dest->y && dest->imap[y + 1][x + 1] == i)
		dest->imap[y][x] = i + 1;
	if (x + 1 < dest->x && y - 1 >= 0 && dest->imap[y - 1][x + 1] == i)
		dest->imap[y][x] = i + 1;
	if (x - 1 >= 0 && dest->imap[y][x - 1] == i)
		dest->imap[y][x] = i + 1;
	if (y - 1 >= 0 && dest->imap[y - 1][x] == i)
		dest->imap[y][x] = i + 1;
	if (x - 1 >= 0 && y - 1 >= 0 && dest->imap[y - 1][x - 1] == i)
		dest->imap[y][x] = i + 1;
	if (x - 1 >= 0 && y + 1 < dest->y && dest->imap[y + 1][x - 1] == i)
		dest->imap[y][x] = i + 1;
}

void fill_heat_map(t_filler *dest)
{
	int i;
	int x;
	int y;

	i = 1;
	while (i < dest->x)
	{
		y = 0;
		while (y < dest->y)
		{
			x = 0;
			while (x < dest->x)
			{
				if (dest->imap[y][x] == 0)
					fill_heat(dest, i, x, y);
				x++;
			}
			y++;
		}
		i++;
	}
}

static void enemy_heat(t_filler *dest, int x, int y)
{
	if (x + 1 < dest->x && dest->imap[y][x + 1] == EN)
		dest->imap[y][x] = 1;
	if (y + 1 < dest->y && dest->imap[y + 1][x] == EN)
		dest->imap[y][x] = 1;
	if (x + 1 < dest->x && y + 1 < dest->y && dest->imap[y + 1][x + 1] == EN)
		dest->imap[y][x] = 1;
	if (x + 1 < dest->x && y - 1 >= 0 && dest->imap[y - 1][x + 1] == EN)
		dest->imap[y][x] = 1;
	if (x - 1 >= 0 && dest->imap[y][x - 1] == EN)
		dest->imap[y][x] = 1;
	if (y - 1 >= 0 && dest->imap[y - 1][x] == EN)
		dest->imap[y][x] = 1;
	if (x - 1 >= 0 && y - 1 >= 0 && dest->imap[y - 1][x - 1] == EN)
		dest->imap[y][x] = 1;
	if (x - 1 >= 0 && y + 1 < dest->y && dest->imap[y + 1][x - 1] == EN)
		dest->imap[y][x] = 1;
}

void	init_heat_map(t_filler *dest)
{
	int x;
	int y;

	y = 0;
	while (y < dest->y)
	{
		x = 0;
		while (x < dest->x)
		{
			if (dest->imap[y][x] == 0)
				enemy_heat(dest, x, y);
			x++;
		}
		y++;
	}
}

void	get_heat_map(t_filler *dest)
{
	init_heat_map(dest);
	fill_heat_map(dest);
}
