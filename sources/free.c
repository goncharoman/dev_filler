/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:01:05 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/04 15:11:02 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	free_elem(t_elem **elem)
{
	int	i;

	i = 0;
	if (elem == NULL || *elem == NULL)
		return ;
	while (i < (*elem)->y)
		free((*elem)->data[i++]);
	free((*elem)->data);
	free(*elem);
	*elem = NULL;
}

void	free_data(t_filler *filler)
{
	free_elem(&(filler->map));
	free_elem(&(filler->token));
}

void	free_filler(t_filler *filler)
{
	free_data(filler);
	free(filler);
}
