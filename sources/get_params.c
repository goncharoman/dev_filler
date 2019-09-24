/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:12:50 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/24 11:54:23 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int get_board(int fd, t_filler *dest)
{
	char *buff;
	char **tmp;
	int count;

	// пропускаем первую строку с нумерацией cols
	if (get_next_line(fd, &buff) > 0)
		ft_strdel(&buff);
	// читаем строки в dest->map
	count = dest->y;
	if (!(dest->map = (char**)malloc(sizeof(char*) * (count + 1))))
		return (0);
	tmp = dest->map;
	while (count-- > 0 && get_next_line(fd, &buff) > 0)
	{
		// убираем первые 4 байта (в VM это отступ для нумерации строк)
		*tmp = ft_strdup(buff + 4);
		ft_strdel(&buff);
		tmp++;
	}
	*tmp = NULL;
	// если неправильно проитается первая строка [:71] или карта не соответсвует размерам, то count не будет равен 0
	return (count == -1 ? 1: 0);
}

static int map_init(int fd, t_filler *dest, char *buff)
{
	char **params;

	// убираем первые 7 байт из строки "Plateau [row] [col]:"" и разбираем на 2 параметра
	params = ft_strsplit(buff, ' ');

	// TODO: добавить error обработчик
	// NOTE: если params != 2 ошибка
	if (ft_strarrlen(params) != 3)
		return (0);
	// записываем размеры карты
	dest->y = ft_atoi(params[1]);
	dest->x = ft_atoi(params[2]);
	// инициализируем саму карту
	// прокидываем ошибку
	ft_strarrdel(&params);
	return (get_board(fd, dest));
}

static int get_token(int fd, t_filler *dest)
{
	// аналогично get_board
	char *buff;
	char **tmp;
	int count;

	count = dest->token->y;
	if (!(dest->token->token = (char**)malloc(sizeof(char*) * (count + 1))))
		return (0);
	tmp = dest->token->token;
	while (count-- > 0 && get_next_line(fd, &buff) > 0)
	{
		*tmp = buff;
		tmp++;
	}
	*tmp = NULL;
	return (count == -1 ? 1: 0);
}

static int token_init(int fd, t_filler *dest, char *buff)
{
	// аналогично map_init
	char **params;

	params = ft_strsplit(buff + 5, ' ');
	if (ft_strarrlen(params) != 2)
		return (0);
	dest->token->y = ft_atoi(params[0]);
	dest->token->x = ft_atoi(params[1]);
	ft_strarrdel(&params);
	return (get_token(fd, dest));
}

int get_params(int fd, t_filler *dest)
{
	char *buff;

	while (get_next_line(fd, &buff) > 0)
	{
		if (ft_strncmp(buff, "Plateau", 7) == 0)
			map_init(fd, dest, buff);
		else if (ft_strncmp(buff, "Piece", 5) == 0)
			if (token_init(fd, dest, buff))
			{
				ft_strdel(&buff);
				return (1);
			}
		ft_strdel(&buff);
	}
	return (0);
}
