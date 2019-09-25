/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 02:08:37 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/25 14:53:50 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void fill_heat(t_elem *dest, int i, int x, int y)
{
	int	**map;

	map = (int**)dest->data;
	if (x + 1 < dest->x && map[y][x + 1] == i)
		map[y][x] = i + 1;
	if (y + 1 < dest->y && map[y + 1][x] == i)
		map[y][x] = i + 1;
	if (x + 1 < dest->x && y + 1 < dest->y && map[y + 1][x + 1] == i)
		map[y][x] = i + 1;
	if (x + 1 < dest->x && y - 1 >= 0 && map[y - 1][x + 1] == i)
		map[y][x] = i + 1;
	if (x - 1 >= 0 && map[y][x - 1] == i)
		map[y][x] = i + 1;
	if (y - 1 >= 0 && map[y - 1][x] == i)
		map[y][x] = i + 1;
	if (x - 1 >= 0 && y - 1 >= 0 && map[y - 1][x - 1] == i)
		map[y][x] = i + 1;
	if (x - 1 >= 0 && y + 1 < dest->y && map[y + 1][x - 1] == i)
		map[y][x] = i + 1;
}

void fill_heat_map(t_elem *dest)
{
	int i;
	int x;
	int y;
	int **map;

	map = (int**)dest->data;
	i = 1;
	while (i < dest->x)
	{
		y = 0;
		while (y < dest->y)
		{
			x = 0;
			while (x < dest->x)
			{
				if (map[y][x] == 0)
					fill_heat(dest, i, x, y);
				x++;
			}
			y++;
		}
		i++;
	}
}

static void enemy_heat(t_elem *dest, int x, int y)
{
	int	**map;

	map = (int**)dest->data;
	if (x + 1 < dest->x && map[y][x + 1] == EN)
		map[y][x] = 1;
	if (y + 1 < dest->y && map[y + 1][x] == EN)
		map[y][x] = 1;
	if (x + 1 < dest->x && y + 1 < dest->y && map[y + 1][x + 1] == EN)
		map[y][x] = 1;
	if (x + 1 < dest->x && y - 1 >= 0 && map[y - 1][x + 1] == EN)
		map[y][x] = 1;
	if (x - 1 >= 0 && map[y][x - 1] == EN)
		map[y][x] = 1;
	if (y - 1 >= 0 && map[y - 1][x] == EN)
		map[y][x] = 1;
	if (x - 1 >= 0 && y - 1 >= 0 && map[y - 1][x - 1] == EN)
		map[y][x] = 1;
	if (x - 1 >= 0 && y + 1 < dest->y && map[y + 1][x - 1] == EN)
		map[y][x] = 1;
}

void	init_heat_map(t_elem *dest)
{
	int x;
	int y;
	int	**map;

	map = (int**)dest->data;
	y = 0;
	while (y < dest->y)
	{
		x = 0;
		while (x < dest->x)
		{
			if (map[y][x] == 0)
				enemy_heat(dest, x, y);
			x++;
		}
		y++;
	}
}

int		get_heat_map(t_filler *dest)
{
	init_heat_map(dest->map);
	fill_heat_map(dest->map);
	return (1);
}
