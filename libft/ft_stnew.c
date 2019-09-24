/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 02:00:42 by roman             #+#    #+#             */
/*   Updated: 2019/04/05 02:07:20 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_stack	*ft_stnew(size_t size)
{
	t_stack	*tmp;

	tmp = (t_stack*)malloc(sizeof(t_stack));
	tmp->size = size;
	tmp->top = -1;
	tmp->array = (int*)malloc(sizeof(int) * size);
	return (tmp);
}
