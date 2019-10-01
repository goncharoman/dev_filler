/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:05:10 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/01 16:34:02 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int str_expand(char **s, int *size)
{
	char *tmp;

	if (!(tmp = ft_strnew(*size + BUFF_SIZE)))
		return (0);
	ft_strncpy(tmp, *s, *size);
	*size += BUFF_SIZE;
	free(*s);
	*s = tmp;
	return (1);
}

char *ft_readline(int fd)
{
	char	*tmp;
	int		err;
	int		i;
	int		size;
	char	c;

	if (fd < 0 || !(tmp = ft_strnew((size = BUFF_SIZE))))
		return (NULL);
	i = 0;
	while ((err = read(fd, &c, 1)) == 1)
	{
		if (c == '\n' || c == '\0')
			break;
		if (i > size - 1)
			if (!str_expand(&tmp, &size))
			{
				err = -1;
				break;
			}
		tmp[i++] = c;
	}
	if (err == -1)
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}
