/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:28:43 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/03 13:02:38 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static int		endline_inx(char *s)
{
	int	inx;

	inx = 0;
	while (*s)
	{
		if (*s++ == '\n')
			return (inx);
		inx++;
	}
	return (-1);
}

static char		*gnl_strjoin(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}

static char		*gnl_strdup(char **s, int offset)
{
	char *tmp;
	char *str;

	tmp = ft_strsub(*s, 0, offset);
	str = ft_strdup(*s + offset + (*(*s + offset) ? 1 : 0));
	free(*s);
	*s = str;
	return (tmp);
}

int				get_next_line(int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			offset;
	static char	*str[MAX_FD];

	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (ERROR);
	if (!str[fd] && !(str[fd] = ft_strnew(BUFF_SIZE)))
		return (ERROR);
	while ((offset = endline_inx(str[fd])) == -1)
	{
		if ((offset = read(fd, buff, BUFF_SIZE)) < 1)
		{
			if (offset == -1)
				return (ERROR);
			if (*str[fd] && (offset = ft_strlen(str[fd])) > 0)
				break ;
			free(str[fd]);
			str[fd] = NULL;
			return (EXIT);
		}
		*(buff + offset) = '\0';
		str[fd] = gnl_strjoin(str[fd], buff);
	}
	*line = gnl_strdup(&str[fd], offset);
	return (OK);
}
