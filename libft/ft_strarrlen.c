/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:43:24 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/29 03:15:05 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int ft_strarrlen(char **strarr)
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
