/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:53:49 by ujyzene           #+#    #+#             */
/*   Updated: 2019/04/05 02:07:20 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(tmp->content = ft_memalloc(content_size)))
		{
			free(tmp);
			tmp = NULL;
		}
		ft_memcpy(tmp->content, content, content_size);
	}
	else
		tmp->content = NULL;
	tmp->content_size = (!content ? 0 : content_size);
	tmp->next = NULL;
	return (tmp);
}
