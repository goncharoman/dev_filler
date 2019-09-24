/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:45:00 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/24 11:49:16 by ujyzene          ###   ########.fr       */
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

t_filler *filler_init(void)
{
	t_filler *filler;

	filler = (t_filler*)malloc(sizeof(t_filler));
	filler->token = (t_token*)malloc(sizeof(t_token));
	filler->token->x = 0;
	filler->token->y = 0;
	filler->token->token = NULL;
	filler->map = NULL;
	filler->imap = NULL;
	filler->me = 0;
	filler->en = 0;
	filler->x = 0;
	filler->y = 0;
	filler->res = 0;
	filler->res2 = -1;
	filler->score = 1000000;
	return (filler);
}

static int	get_hvalue(char c, char en, char me)
{
	if (c == '.')
		return (0);
	else if (c == en)
		return (EN);
	else if (c == me)
		return (ME);
	else
		return (-3);
}

int	init_imap(t_filler *dest)
{
	int		**map;
	char	**tmp;
	int		i;
	int		j;

	if (!(map = (int**)malloc(sizeof(int*) * dest->y)))
		return (0);
	tmp = dest->map;
	i = 0;
	while (tmp[i])
	{
		map[i] = (int*)malloc(sizeof(int) * dest->x);
		j = 0;
		while (tmp[i][j])
		{
			map[i][j] = get_hvalue(tmp[i][j], dest->en, dest->me);
			j++;
		}
		i++;
	}
	dest->imap = map;
	get_heat_map(dest);
	return (1);
}
