/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:45:00 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/29 02:06:02 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	get_player_info(int fd, t_filler *dest)
{
	char *buff;
	char *tmp;

	get_next_line(fd, &buff);
	tmp = buff;
	if (ft_strcmp(tmp, "p1"))
	{
		dest->me = 'O';
		dest->en = 'X';
	}
	else if (ft_strcmp(tmp, "p2"))
	{
		dest->me = 'O';
		dest->en = 'X';
	}
	free(buff);
	return (1);
}

static t_elem	*init_elem(void)
{
	t_elem *tmp;

	if (!(tmp = (t_elem*)malloc(sizeof(t_elem))))
		return (NULL);
	tmp->x = 0; // col
	tmp->y = 0;	// row
	tmp->data = NULL;
	return (tmp);
}

t_filler *init_filler(void)
{
	t_filler *filler;

	filler = (t_filler*)malloc(sizeof(t_filler));
	filler->token = init_elem();
	filler->map = init_elem();
	filler->me = 0;
	filler->en = 0;
	filler->done = 0;
	return (filler);
}

void pos_set(t_pos *p, int x, int y)
{
	p->x = x;
	p->y = y;
}

void init_data(int fd, t_filler *filler)
{
	if (!get_params(fd, filler))
	{
		return ;
	}
	test_input(filler->map);
	if (!init_imap(filler->map, filler->en, filler->me, &set_me_en))
	{
		return ;
	}
	if (!init_imap(filler->token, '*', '.', &set_str_dot))
	{
		return ;
	}
	if (!get_heat_map(filler))
	{
		return ;
	}
}
