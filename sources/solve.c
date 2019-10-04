/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:42:28 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/04 15:22:20 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int			score_count(t_elem elem, t_pos map, t_pos p, int *score)
{
	int	**board;

	board = (int**)elem.data;
	if (map.y + p.y < 0 || map.y + p.y >= elem.y ||
		map.x + p.x < 0 || map.x + p.x >= elem.x)
		return (0);
	if (board[map.y + p.y][map.x + p.x] == ME ||
		board[map.y + p.y][map.x + p.x] == EN)
	{
		if (p.x != 0 || p.y != 0)
			return (0);
	}
	if (board[map.y + p.y][map.x + p.x] != ME)
		*score += board[map.y + p.y][map.x + p.x];
	return (1);
}

int			score_before(t_filler *filler, t_pos map, t_pos p, int *score)
{
	t_pos	tmp;
	t_pos	d;
	int		**board;

	board = (int**)filler->token->data;
	pos_set(&tmp, p.x, p.y);
	while (p.y >= 0)
	{
		while (p.x >= 0)
		{
			if (board[p.y][p.x] == 1)
			{
				pos_set(&d, p.x - tmp.x, p.y - tmp.y);
				if (!score_count(*filler->map, map, d, score))
					return (0);
			}
			p.x--;
		}
		p.x = filler->token->x - 1;
		p.y--;
	}
	return (1);
}

int			score_after(t_filler *filler, t_pos map, t_pos p, int *score)
{
	t_pos	tmp;
	t_pos	d;
	int		**board;

	board = (int**)filler->token->data;
	pos_set(&tmp, p.x, p.y);
	while (p.y < filler->token->y)
	{
		while (p.x < filler->token->x)
		{
			if (board[p.y][p.x] == 1)
			{
				pos_set(&d, p.x - tmp.x, p.y - tmp.y);
				if (!score_count(*filler->map, map, d, score))
					return (0);
			}
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
	return (1);
}

static int	foreach_elem(t_elem *elem, t_pos *p, int des)
{
	int			**tmp;
	int			inx;
	static int	x[2];
	static int	y[2];

	inx = des == ME;
	tmp = (int**)elem->data;
	while (y[inx] < elem->y)
	{
		while (x[inx] < elem->x)
		{
			if (tmp[y[inx]][x[inx]] == des)
			{
				p->x = x[inx]++;
				p->y = y[inx];
				return (1);
			}
			x[inx]++;
		}
		x[inx] = 0;
		y[inx]++;
	}
	y[inx] = 0;
	return (0);
}

int			solve(t_filler *filler)
{
	t_pos	map;
	t_pos	token;
	int		score;

	init_result(filler);
	pos_set(&map, 0, 0);
	pos_set(&token, 0, 0);
	while (foreach_elem(filler->map, &map, ME))
	{
		while (foreach_elem(filler->token, &token, 1))
		{
			score = 0;
			if (score_before(filler, map, token, &score) &&
				score_after(filler, map, token, &score))
			{
				save_result(filler, map, token, score);
			}
		}
	}
	return (1);
}
