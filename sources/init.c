/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:45:00 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/25 19:53:51 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	get_player_info(int fd, t_filler *dest)
{
	char *buff;
	char *tmp;

	// TODO: добавить error обработчик
	// NOTE: если нет инфомации о игроке или строка не соответсвует формату 	$$$ exec pPLAYER_NUMBER : [PLAYER_NAME]

	get_next_line(fd, &buff);
	tmp = buff;
	while (*tmp)
	{
		if (ft_strcmp(tmp, "p1"))
		{
			dest->me = 'O';
			dest->en = 'X';
			break;
		}
		else if (ft_strcmp(tmp, "p2"))
		{
			dest->me = 'O';
			dest->en = 'X';
			break;
		}
		free(buff);
	}
	return (1);
}

static t_elem	*elem_init(void)
{
	t_elem *tmp;

	if (!(tmp = (t_elem*)malloc(sizeof(t_elem))))
		return (NULL);
	tmp->x = 0; // col
	tmp->y = 0;	// row
	tmp->data = NULL;
	return (tmp);
}

t_filler *filler_init(void)
{
	t_filler *filler;

	filler = (t_filler*)malloc(sizeof(t_filler));
	filler->token = elem_init();
	filler->map = elem_init();
	filler->me = 0;
	filler->en = 0;
	filler->score = 1000000;
	return (filler);
}

void	pos_init(t_pos *p)
{
	p->x = 0;
	p->y = 0;
}

void init_data(int fd, t_filler *filler)
{
	if (!get_params(fd, filler))
	// сообщение об ошибке
		return ;
	if (!init_imap(filler->map, filler->en, filler->me, &set_me_en))
	// сообщение об ошибке
		return ;
	if (!init_imap(filler->token, '*', '.', &set_str_dot))
	// сообщение об ошибке
		return ;
	if (!get_heat_map(filler))
	// сообщение об ошибке
		return ;
}
