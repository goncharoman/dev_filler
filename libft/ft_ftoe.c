/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:17:57 by ujyzene           #+#    #+#             */
/*   Updated: 2019/08/11 23:16:03 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#define EXP(f) (f.spec.exp - 1023)
#define NRM(f) (f.spec.mnts | 0x10000000000000)
#define SGN(n, x) (n < 0 ? -x : x)
#define TEN(n) ((n << 3) + (n << 1))
#define ABS(n) (n < 0 ? -n : n)

static double	delta(size_t n)
{
	double x;

	x = 0.5;
	n += 3;
	while (n-- > 1)
		x *= 0.1;
	return (x);
}

static void		put_fracpart(char *s, t_float_cast f, size_t *prec, int *e)
{
	uintmax_t		frac_part;

	s += ft_strlen(s);
	if (EXP(f) >= 0)
		frac_part = (NRM(f) << (EXP(f) + 1)) & 0x1fffffffffffff;
	else
	{
		(*e)--;
		frac_part = (NRM(f) & 0x1fffffffffffff) >> -(EXP(f) + 1);
		while ((frac_part = TEN(frac_part)) >> 53 == 0)
		{
			frac_part &= 0x1fffffffffffff;
			(*e)--;
		}
		*s++ = (frac_part >> 53) + '0';
		frac_part &= 0x1fffffffffffff;
		*s++ = '.';
	}
	while ((*prec)-- > 0)
	{
		frac_part = TEN(frac_part);
		*s++ = (frac_part >> 53) + '0';
		frac_part &= 0x1fffffffffffff;
	}
}

static void		put_intpart(char *s, uintmax_t n, size_t *prec, int *e)
{
	uintmax_t exp;

	exp = 1;
	s += ft_strlen(s);
	while (n / exp >= 10)
	{
		exp *= 10;
		(*e)++;
	}
	*s++ = '0' + n / exp;
	*s++ = '.';
	while ((exp /= 10) > 0 && *prec > 0)
	{
		*s++ = '0' + (n / exp) % 10;
		(*prec)--;
	}
}

static void		put_exp(char *s, int exp)
{
	char *tmp;

	ft_strcat(s, exp > 0 ? "e+" : "e-");
	if (ABS(exp) < 10)
		ft_strcat(s, "0");
	ft_strcat(s, (tmp = ft_itoa(ABS(exp))));
	free(tmp);
}

char			*ft_ftoe(double n, size_t prec, int sign)
{
	char			*ans;
	t_float_cast	f;
	int				e;
	uintmax_t		int_part;

	e = 0;
	f.n = n + delta(prec);
	if (n == 0.0)
		return (ft_strdup("0.0"));
	if (!(ans = ft_strnew(16)))
		return (NULL);
	if (f.spec.sign)
		*ans = '-';
	if (sign && !f.spec.sign)
		*ans = '+';
	int_part = EXP(f) < 0 ? 0 : NRM(f) >> (52 - EXP(f));
	if (int_part > 0)
		put_intpart(ans, int_part, &prec, &e);
	put_fracpart(ans, f, &prec, &e);
	put_exp(ans, e);
	return (ans);
}
