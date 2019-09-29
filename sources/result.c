/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:33:20 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/28 22:21:07 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void save_result(t_filler *filler, t_pos map, t_pos token, int score)
{
	if (!filler->done)
	{
		if ((score <= filler->score && score > 0) ||
			(score > 0 && filler->score == 0))
		{
			filler->score = score;
			pos_set(&(filler->result), map.x - token.x, map.y - token.y);
		}
		else
		{
			filler->tmp_score = score;
			pos_set(&(filler->tmp_result), map.x - token.x, map.y - token.y);
		}
	}
	// FILE *f = fopen("../log.txt", "a+");
	// fprintf(f, "--------test--------\n");
	// fprintf(f, "this score\t%d\n", score);
	// fprintf(f, "filler->score\t%d\nfiller->result.y\t%d\nfiller->result.x\t%d\n",
	// 	filler->score, filler->result.y, filler->result.x);
	// fprintf(f, "filler->tmp_score\t%d\nfiller->tmp_result.y\t%d\nfiller->tmp_result.x\t%d\n",
	// 	filler->tmp_score, filler->tmp_result.y, filler->tmp_result.x);
	// fprintf(f, "map.y\t%d\nmap.x\t%d\n", map.y, map.x);
	// fprintf(f, "token.y\t%d\ntoken.x\t%d\n", token.y, token.x);
	// fprintf(f, "-----------end----------\n");
	// fclose(f);
}

void init_result(t_filler *filler)
{
	filler->score = 0;
	filler->tmp_score = 0;
	filler->result.x = 0;
	filler->result.y = 0;
	filler->tmp_result.x = 0;
	filler->tmp_result.y = 0;
}

void print_result(t_filler *filler)
{
	t_pos p;

	p = (filler->result.x == 0 && filler->result.y == 0 &&
		filler->tmp_result.x != 0 && filler->tmp_result.y != 0) ?
		filler->tmp_result : filler->result;
	ft_putnbr(p.y);
	ft_putchar(' ');
	ft_putnbr(p.x);
	ft_putchar('\n');
	FILE *f = fopen("../log.txt", "a+");
	fprintf(f, "OUT RESULT : %d %d\n", p.y, p.x);
	fclose(f);
}
