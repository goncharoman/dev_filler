/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 22:45:41 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/23 22:59:23 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strarrdel(char ***strarr)
{
	int		count;
	int		i;
	char	**tmp;

	if (!strarr || !*strarr)
		return ;
	count = ft_strarrlen(*strarr);
	tmp = *strarr;
	i = 0;
	while (i < count)
		ft_strdel(&(tmp[i++]));
	free(*strarr);
	*strarr = NULL;
}
