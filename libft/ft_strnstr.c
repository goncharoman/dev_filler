/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:45:40 by ujyzene           #+#    #+#             */
/*   Updated: 2019/04/05 02:07:20 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	if (!*needle)
		return ((char*)haystack);
	while (len-- > 0 && *haystack)
	{
		i = 0;
		while (*(needle + i) == *(haystack + i) && i <= len)
			if (!*(needle + i++ + 1))
				return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
