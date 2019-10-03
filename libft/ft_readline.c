/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:05:10 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/03 13:11:04 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	str_expand(char **s, int *size)
{
	char	*tmp;

	if (!(tmp = ft_strnew(*size + BUFF_SIZE)))
		return (0);
	ft_strncpy(tmp, *s, *size);
	*size += BUFF_SIZE;
	free(*s);
	*s = tmp;
	return (1);
}

static void	write_buff(char fd, char **s, int size)
{
	int		i;
	int		err;
	char	c;

	i = 0;
	while ((err = read(fd, &c, 1)) == 1)
	{
		if (c == '\n' || c == '\0')
			break ;
		if (i > size - 1)
			if (!str_expand(s, &size))
			{
				err = -1;
				break ;
			}
		*s[i++] = c;
	}
	if (err == -1)
	{
		free(*s);
		*s = NULL;
	}
}

char		*ft_readline(int fd)
{
	char	*tmp;

	if (fd < 0 || !(tmp = ft_strnew(BUFF_SIZE)))
		return (NULL);
	write_buff(fd, &tmp, BUFF_SIZE);
	return (tmp);
}
