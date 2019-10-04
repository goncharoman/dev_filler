/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:12:50 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/04 17:26:47 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int			init_imap(t_elem *elem, char c1, char c2,
			int (*f)(char, char, char))
{
	int		**imap;
	char	**tmp;
	int		i;
	int		j;

	if (!(imap = (int**)malloc(sizeof(int*) * elem->y)))
		return (0);
	tmp = (char**)elem->data;
	i = 0;
	while (i < elem->y && tmp[i])
	{
		imap[i] = (int*)malloc(sizeof(int) * elem->x);
		j = 0;
		while (j < elem->x && tmp[i][j])
		{
			imap[i][j] = (*f)(tmp[i][j], c1, c2);
			j++;
		}
		while (j < elem->x)
			imap[i][j++] = -3;
		i++;
	}
	ft_strarrdel(&tmp);
	elem->data = (void**)imap;
	return (1);
}

static int	get_elemdata(int fd, t_elem *dest, int e_flag)
{
	char	*buff;
	char	**tmp;
	int		count;

	if (e_flag == E_MAP)
		if (get_next_line(fd, &buff) > 0)
			ft_strdel(&buff);
	count = dest->y;
	if (!(dest->data = (void**)malloc(sizeof(char*) * (count + 1))))
		return (0);
	tmp = (char**)dest->data;
	while (count-- > 0 && get_next_line(fd, &buff) > 0)
	{
		*tmp = e_flag == E_TOKEN ? buff : ft_strdup(buff + 4);
		if (e_flag == E_MAP)
			ft_strdel(&buff);
		tmp++;
	}
	*tmp = NULL;
	return (count == -1 ? 1 : 0);
}

static int	get_elem(int fd, t_elem *dest, char *buff, int e_flag)
{
	char	**params;

	params = ft_strsplit(buff, ' ');
	if (ft_strarrlen(params) != 3)
		return (0);
	dest->y = ft_atoi(params[1]);
	dest->x = ft_atoi(params[2]);
	ft_strarrdel(&params);
	if (dest->y <= 0 || dest->x <= 0)
		return (0);
	return (get_elemdata(fd, dest, e_flag));
}

int			get_params(int fd, t_filler *dest)
{
	char	*buff;
	int		err;

	while ((err = get_next_line(fd, &buff)) > 0)
	{
		if (ft_strncmp(buff, "Plateau", 7) == 0)
		{
			get_elem(fd, dest->map, buff, E_MAP);
		}
		else if (ft_strncmp(buff, "Piece", 5) == 0)
		{
			get_elem(fd, dest->token, buff, E_TOKEN);
			ft_strdel(&buff);
			return (1);
		}
		ft_strdel(&buff);
	}
	return (err);
}
