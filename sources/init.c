/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:45:00 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/04 12:08:59 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

// определяем из первой строки передаваемой программе
// какой символ имеет наш игрок
int	get_player_info(int fd, t_filler *dest, char *player_call)
{
	char *buff;
	int player_nbr;

	// get_next_line(fd, &buff);
	buff = ft_readline(fd);
	if (!runstr_check(buff, player_call, &player_nbr))
	{
		free(buff);
		return (0);
	}
	if (player_nbr == 1)
	{
		dest->me = 'O';
		dest->en = 'X';
	}
	else if (player_nbr == 2)
	{
		dest->me = 'X';
		dest->en = 'O';
	}
	free(buff);
	return (1);
}

// инициализация структуры t_elem
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

// общяя инициализация filler структуры
t_filler *init_filler(void)
{
	t_filler *filler;

	filler = (t_filler*)malloc(sizeof(t_filler));
	filler->token = NULL;
	filler->map = NULL;
	filler->me = 0;
	filler->en = 0;
	return (filler);
}

// инициализация элементов filler->map и filler->token
int init_filler_elems(t_filler *filler)
{
	if (filler->map == NULL)
		if (!(filler->map = init_elem()))
			return (0);
	if (filler->token == NULL)
		if (!(filler->token = init_elem()))
			return (0);
	return (1);
}

int init_data(int fd, t_filler *filler)
{
	int err;

	if (!init_filler_elems(filler))
		return(return_error("ERROR: filler initialization error"));
	if ((err = get_params(fd, filler)) != 1)
	{
		if (err == -1)
			return (return_error("ERROR: read error"));
		return (0);
	}
	if (!check_params(filler))
		return (return_error("ERROR: wrong params"));
	if (!init_imap(filler->map, filler->en, filler->me, &set_me_en))
		return(return_error("ERROR: filler imap initialization error"));
	if (!imap_check(filler->map))
		return (return_error("ERROR: wrong MAP"));
	if (!init_imap(filler->token, '*', '.', &set_str_dot))
		return(return_error("ERROR: filler itoken initialization error"));
	if (!imap_check(filler->token))
		return (return_error("ERROR: wrong TOKEN"));
	if (!get_heat_map(filler))
		return(return_error("ERROR: heat map initialization error"));
	return (1);
}
