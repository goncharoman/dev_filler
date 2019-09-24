/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 02:20:37 by ujyzene           #+#    #+#             */
/*   Updated: 2019/08/11 23:17:16 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	char_count(long long n)
{
	size_t len;

	len = (n < 0) ? 1 : 0;
	n = ABS(n);
	while ((n /= 10) != 0)
		len++;
	return (++len);
}

static void		rec_itoa(long long n, char *ans, int *index)
{
	if (n >= 10)
		rec_itoa(n / 10, ans, index);
	ans[(*index)++] = '0' + n % 10;
}

char			*ft_itoa(long long n)
{
	char	*ans;
	int		offset;

	if (!(ans = ft_strnew(char_count(n))))
		return (NULL);
	offset = 0;
	if (n < 0)
		ans[offset++] = '-';
	rec_itoa(ABS(n), ans, &offset);
	ans[offset] = '\0';
	return (ans);
}
