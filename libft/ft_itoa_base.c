/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:14:24 by ujyzene           #+#    #+#             */
/*   Updated: 2019/08/11 23:18:44 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

inline static int	bound_values(intmax_t n, char *str)
{
	if (n == INTMAX_MIN)
		ft_strcpy(str, "-9223372036854775808");
	else if (n == INTMAX_MAX)
		ft_strcpy(str, "9223372036854775807");
	else
		return (0);
	return (1);
}

static void			rec_itoa(intmax_t n, int base, char *ans, int *index)
{
	const char hex[] = "0123456789ABCDF";

	if (n >= base)
		rec_itoa(n / base, base, ans, index);
	ans[(*index)++] = hex[n % base];
}

/*
** return NULL if base < 0 or base > 16 or alloced error
*/

char				*ft_itoa_base(intmax_t n, unsigned int base, int sign)
{
	char	*ans;
	int		offset;

	if (base <= 0 || base > 16 || !(ans = ft_strnew(33)))
		return (NULL);
	offset = 0;
	if (bound_values(n, ans))
		return (ans);
	if (base == 10)
	{
		if (n < 0)
			ans[offset++] = '-';
		else if (sign)
			ans[offset++] = '+';
	}
	rec_itoa(ABS(n), base, ans, &offset);
	ans[offset] = '\0';
	return (ans);
}
