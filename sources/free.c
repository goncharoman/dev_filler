/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:01:05 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/01 13:44:52 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

// общая функция освобождения структуры t_elem
void free_elem(t_elem **elem)
{
	int i;

	i = 0;
	if (elem == NULL || *elem == NULL)
		return ;
	while (i < (*elem)->y)
		free((*elem)->data[i++]);
	free((*elem)->data);
	free(*elem);
	*elem = NULL;
}

// освобождает только filler->map и filler->token
// (вызывается в конце каждого цыкла выполения решения)
void free_data(t_filler *filler)
{
	free_elem(&(filler->map));
	free_elem(&(filler->token));
}

// высвобождает пямять всего filler'а (вызывается по окончанию программы)
void free_filler(t_filler *filler)
{
	free_data(filler);
	free(filler);
}
