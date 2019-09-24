/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:14:24 by ujyzene           #+#    #+#             */
/*   Updated: 2019/08/11 23:21:29 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	rec_itoa(uintmax_t n, unsigned int base, char *ans, int *index)
{
	const char hex[] = "0123456789ABCDEF";

	if (n >= base)
		rec_itoa(n / base, base, ans, index);
	ans[(*index)++] = hex[n % base];
}

char		*ft_uitoa_base(uintmax_t n, unsigned int base)
{
	char	*ans;
	int		offset;

	if (base <= 0 || base > 16 || !(ans = ft_strnew(33)))
		return (NULL);
	offset = 0;
	rec_itoa(ABS(n), base, ans, &offset);
	ans[offset] = '\0';
	return (ans);
}
