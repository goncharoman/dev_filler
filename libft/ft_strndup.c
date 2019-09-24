/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:34:51 by ujyzene           #+#    #+#             */
/*   Updated: 2019/04/05 02:07:20 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char *tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * n + 1)))
		return (NULL);
	*(tmp + n) = '\0';
	while (n-- > 0)
		*(tmp + n) = *(s1 + n);
	return (tmp);
}
