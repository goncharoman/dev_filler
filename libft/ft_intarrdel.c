/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:43:16 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/29 16:26:04 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_intarrdel(int ***array)
{
	int	**tmp;
	
	tmp = *array;
	while (*tmp)
	{
		ft_memdel(&(*tmp));
		tmp++;
	}
	free(*array);
	*array = NULL;
}