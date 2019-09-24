/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 22:50:56 by ujyzene           #+#    #+#             */
/*   Updated: 2019/04/05 02:07:20 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dst_size;
	size_t src_size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dstsize < dst_size + 1)
		return (src_size + dstsize);
	else
	{
		dst += dst_size;
		dstsize -= dst_size;
		while (--dstsize > 0)
			if (*src)
				*dst++ = *src++;
			else
				*dst++ = '\0';
		*dst++ = '\0';
	}
	return (dst_size + src_size);
}
