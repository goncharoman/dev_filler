/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:43:24 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/03 13:11:33 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strarrlen(char **strarr)
{
	int len;

	len = 0;
	while (*strarr)
	{
		len++;
		strarr++;
	}
	return (len);
}
