/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 02:45:51 by ujyzene           #+#    #+#             */
/*   Updated: 2019/04/05 02:07:20 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrev(char *str)
{
	char	tmp;
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(str);
	while (++i < --len)
	{
		tmp = *(str + i);
		*(str + i) = *(str + len);
		*(str + len) = tmp;
	}
	return (str);
}
