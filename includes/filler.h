/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 01:49:37 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/25 14:58:23 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <libft.h>
# include <fcntl.h>

# define ME -2
# define EN -1

# define E_MAP		0
# define E_TOKEN	1

typedef struct	s_elem
{
	int		x;
	int		y;
	void	**data;
}				t_elem;


typedef struct	s_solve
{
	int m_x;
	int m_y;
	int t_x;
	int t_y;
}				t_solve;

typedef struct	s_filler
{
	t_elem	*map;
	t_elem	*token;
	char	me;
	char	en;
	int		score;
}				t_filler;

t_filler	*filler_init(void);
void		init_data(int fd, t_filler *filler);
int			get_player_info(int fd, t_filler *dest);
int			get_params(int fd, t_filler *dest);
int			init_imap(t_filler *dest);
int			get_heat_map(t_filler *dest);
int			test(t_filler *test);
#endif
