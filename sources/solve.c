/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:42:28 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/25 22:24:24 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		score_count(t_elem elem, t_pos map, t_pos p, t_pos tmp, int *score)
{
	int **board;

	board = (int**)elem.data;
	if (map.y + p.y - tmp.y < 0 || map.y + p.y - tmp.y >= elem.y ||
			map.x + p.x - tmp.x < 0 || map.x + p.x - tmp.x >= elem.x)
		return (1);
	if (board[map.y + p.y - tmp.y][map.x + p.x - tmp.x] == ME ||
			board[map.y + p.y - tmp.y][map.x + p.x - tmp.x] == EN)
	{
		if (p.x != tmp.x || p.y != tmp.y)
			return (1);
	}
	if (board[map.y + p.y - tmp.y][map.x + p.x - tmp.x] != ME)
		*score += board[map.y + p.y - tmp.y][map.x + p.x - tmp.x];
	return (0);
}

int			score_before(t_filler *filler, t_pos map, t_pos p, int *score)
{
	t_pos	tmp;
	int		**board;

	board = (int**)filler->token->data;
	tmp.x = p.x;
	tmp.y = p.y;
	while (p.y >= 0)
	{
		while (p.x >= 0)
		{
			if (board[p.y][p.x] == 1)
				if (score_count(*filler->map, map, p, tmp, score))
					return (0);
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
	int		**board;

	board = (int**)filler->token->data;
	tmp.x = p.x;
	tmp.y = p.y;
	while (p.y < filler->token->y)
	{
		while (p.x < filler->token->x)
		{
			if (board[p.y][p.x] == 1)
				if (score_count(*filler->map, map, p, tmp, score))
					return (0);
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

int solve(t_filler *filler)
{
	t_pos	map;
	t_pos	token;
	int		score;

	pos_init(&map);
	pos_init(&token);
	while (foreach_elem(filler->map, &map, ME))
	{
		while (foreach_elem(filler->token, &token, 1))
		{
			score = 0;
			if (score_before(filler, map, token, &score) &&
				score_after(filler, map, token, &score))
				{
					// FILE *f = fopen("../log.txt", "a+");
					// fprintf(f, "score: %d\n", score);
					// fclose(f);
					printf("score: %d\n", score);
				}
		}
	}
	return (1);
}
