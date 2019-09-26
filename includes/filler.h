/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 01:49:37 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/26 13:33:10 by ujyzene          ###   ########.fr       */
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


typedef struct	s_pos
{
	int x;
	int y;
}				t_pos;

typedef struct	s_filler
{
	t_elem	*map;
	t_elem	*token;
	char	me;
	char	en;
	int		score;
	int		done;
	t_pos	result;
}				t_filler;

t_filler	*filler_init(void);
void		init_data(int fd, t_filler *filler);
void		pos_set(t_pos *p, int x, int y);
int			get_player_info(int fd, t_filler *dest);
int			get_params(int fd, t_filler *dest);
int			init_imap(t_elem *elem, char c1, char c2,
			int (*f)(char, char, char));
int			get_heat_map(t_filler *dest);
int 		solve(t_filler *filler);

int			test(t_filler *test);
int			set_me_en(char c, char en, char me);
int 		set_str_dot(char c, char star, char dot);
#endif
