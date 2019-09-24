/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:42:04 by ujyzene           #+#    #+#             */
/*   Updated: 2019/04/12 01:30:52 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	is_allowed(char c, int base)
{
	if (base < 10)
		return ('0' <= c && c < '0' + base);
	else
		return (('0' <= c && c < '0' + base) ||
				('a' <= c && c < 'a' + base - 10));
}

static int	get_item(char *s, int base, int *digit)
{
	*s = ft_tolower(*s);
	if (!is_allowed(*s, base))
		return (0);
	return (get_item(s + 1, base, digit) + ft_pow(base, (*digit)++) *
			(ft_isdigit(*s) ? *s - '0' : 10 + *s - 'a'));
}

int			ft_atoi_base(const char *str, int base)
{
	int n;

	n = 0;
	if (base == 10)
		return (ft_atoi(str));
	while (ft_isspace(*str))
		str++;
	return (get_item((char*)str, base, &n));
}
