/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:33:20 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/01 12:20:34 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

// сохраняем результат
void save_result(t_filler *filler, t_pos map, t_pos token, int score)
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

// инициализируем елементы структуры filler храняшие результат
void init_result(t_filler *filler)
{
	filler->score = 0;
	filler->tmp_score = 0;
	filler->result.x = 0;
	filler->result.y = 0;
	filler->tmp_result.x = 0;
	filler->tmp_result.y = 0;
}

// вывод результата
void print_result(t_filler *filler)
{
	t_pos p;

	p = (filler->result.x == 0 && filler->result.y == 0) ?
		filler->tmp_result : filler->result;
	ft_putnbr(p.y);
	ft_putchar(' ');
	ft_putnbr(p.x);
	ft_putchar('\n');
}
