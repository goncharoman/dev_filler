/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 23:21:19 by ujyzene           #+#    #+#             */
/*   Updated: 2019/04/05 02:07:20 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *tmp_dst;
	char *tmp_src;

	if (len == 0 || dst == src)
		return (dst);
	tmp_dst = (char*)dst;
	tmp_src = (char*)src;
	if (tmp_dst < tmp_src)
	{
		while (len-- > 0)
			*tmp_dst++ = *tmp_src++;
	}
	else
	{
		tmp_dst = tmp_dst + len - 1;
		tmp_src = tmp_src + len - 1;
		while (len-- > 0)
			*tmp_dst-- = *tmp_src--;
	}
	return (dst);
}
