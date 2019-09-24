/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:54:43 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/24 11:37:36 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	lines_count(const char *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			len++;
		i++;
	}
	return (len);
}

static int	next_line(const char *s, char del)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != del)
		i++;
	return (i);
}

static char	**free_all(char **strs, int size)
{
	while (size-- > 0)
	{
		free(strs[size]);
	}
	free(strs);
	strs = NULL;
	return (strs);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tmp;
	int		offset;
	int		size;
	int		i;

	if (!s)
		return (NULL);
	size = lines_count(s, c);
	if (!(tmp = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	tmp[size] = NULL;
	offset = 0;
	i = 0;
	while (i < size)
	{
		while (*s == c)
			s++;
		offset = next_line(s, c);
		if (!(tmp[i++] = ft_strsub(s, 0, offset)))
			return (free_all(tmp, i - 1));
		s += offset;
	}
	return (tmp);
}
