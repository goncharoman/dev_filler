/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:57:25 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/04 15:17:34 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	runstr_check(char *s, char *player_call, int *player_nbr)
{
	int	ans[2];

	if (ft_strncmp(s, "$$$ ", 4) == 0)
		s += 4;
	if (ft_strncmp(s, "exec ", 5) == 0)
		s += 5;
	if ((ans[0] = !!ft_strncmp(s, "p1 : ", 5)) == 0 ||
		(ans[1] = !!ft_strncmp(s, "p2 : ", 5)) == 0)
		s += 5;
	if (ft_strstr(s, player_call) != NULL)
	{
		*player_nbr = ans[0] == 0 ? 1 : 2;
		return (1);
	}
	return (0);
}

int	imap_check(t_elem *elem)
{
	int	x;
	int	y;
	int	**map;

	map = (int**)elem->data;
	y = 0;
	while (y < elem->y)
	{
		x = 0;
		while (x < elem->x)
		{
			if (map[y][x] == -3)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_params(t_filler *filler)
{
	return (filler->map->x > 0 && filler->map->y > 0 &&
			filler->token->x > 0 && filler->token->y > 0);
}
