/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 01:49:37 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/24 02:41:06 by ujyzene          ###   ########.fr       */
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

typedef struct	s_token
{
	int		x;
	int		y;
	char	**token;
}				t_token;

typedef struct	s_filler
{
	char	**map;
	t_token *token;
	int		**imap;
	char	me;
	char	en;
	int		x;
	int		y;
	int		res;
	int		res2;
	int		score;
}				t_filler;

t_filler	*filler_init(void);
int			get_player_info(int fd, t_filler *dest);
int			get_params(int fd, t_filler *dest);
int			init_imap(t_filler *dest);
int			test(t_filler *test);
void		get_heat_map(t_filler *dest);
#endif
