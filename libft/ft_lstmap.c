/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:43:43 by ujyzene           #+#    #+#             */
/*   Updated: 2019/04/05 02:07:20 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	*all_free(t_list *lst)
{
	t_list *tmp;

	if (!lst)
		return (NULL);
	while (lst)
	{
		tmp = lst->next;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
	return (NULL);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *map_lst;
	t_list *tmp;

	if (!lst)
		return (NULL);
	tmp = f(lst);
	if (!(tmp = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	map_lst = tmp;
	while (lst->next)
	{
		if (!(tmp->next = ft_lstnew(f(lst->next)->content,
							f(lst->next)->content_size)))
			return (all_free(map_lst));
		lst = lst->next;
		tmp = tmp->next;
	}
	return (map_lst);
}
