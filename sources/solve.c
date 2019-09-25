/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:42:28 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/25 02:03:23 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int put_try(t_filler *dest, t_solve* r)
{
	t_token *t;

	t = dest->token;
	r->t_y = 0;
	while (r->t_y < t->y)
	{
		r->t_x = 0;
		while (r->t_x < t->x)
		{
			if (t->token[r->t_y][r->t_x] == '*')

			r->t_x++;
		}
		r->t_y++;
	}
}

int put_token(t_filler *dest)
{
	t_solve *r;

	r->m_y = 0;
	while (r->m_y < dest->y)
	{
		r->m_x = 0;
		while (r->m_x < dest->x)
		{
			if (dest->imap[r->m_y][r->m_x] == ME)
			{
				put_try(dest, r);
			}
			r->m_x++;
		}
		r->m_y++;
	}
}
