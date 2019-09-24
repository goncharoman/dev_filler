/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:17:57 by ujyzene           #+#    #+#             */
/*   Updated: 2019/08/12 17:08:14 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#define EXP(f) (f.spec.exp - 1023)
#define NRM(f) (f.spec.mnts | 0x10000000000000)
#define SGN(n, x) (n < 0 ? -x : x)
#define MNAN 0x8000000000000

static double	delta(double x, int n)
{
	while (n-- > 1)
		x *= 0.1;
	return (x);
}

static void		this_itoa(uintmax_t n, char *ans, int *index)
{
	if (n >= 10)
		this_itoa(n / 10, ans, index);
	ans[(*index)++] = '0' + n % 10;
}

static void		set_intpart(char *s, t_float_cast f)
{
	int	offset;

	offset = 0;
	if (EXP(f) >= 0)
		this_itoa((uintmax_t)(NRM(f) >> (52 - EXP(f))), s, &offset);
	else
		*s = '0';
}

static void		set_afterpoint(char *s, t_float_cast f, unsigned int prec)
{
	const short		exp = EXP(f);
	const uintmax_t	mnts = NRM(f);
	uintmax_t		frac_part;
	int				i;

	s += ft_strlen(s);
	if (exp >= 0)
		frac_part = (mnts << (exp + 1)) & 0x1fffffffffffff;
	else
		frac_part = (mnts & 0x1fffffffffffff) >> -(exp + 1);
	i = -1;
	while (++i < (int)prec)
	{
		frac_part = (frac_part << 3) + (frac_part << 1);
		s[i] = (frac_part >> 53) + '0';
		frac_part &= 0x1fffffffffffff;
	}
}

char			*ft_ftoa(double n, unsigned int prec, int sign)
{
	char			*ans;
	t_float_cast	f;

	f.n = n + SGN(n, delta(prec > 1 ? 0.5 : 0.51, prec + 1));
	if (f.spec.exp == 0x7ff)
	{
		if (!f.spec.sign)
			return (ft_strdup(!!(f.spec.mnts & MNAN) ? "NAN" : "INF"));
		return (ft_strdup("-INF"));
	}
	if (!(ans = ft_strnew(18 + prec)))
		return (NULL);
	if (f.spec.sign)
		*ans = '-';
	if (sign && !f.spec.sign)
		*ans = '+';
	set_intpart(f.spec.sign || sign ? ans + 1 : ans, f);
	if (prec > 0)
	{
		ft_strcat(ans, ".");
		set_afterpoint(ans, f, prec);
	}
	return (ans);
}
