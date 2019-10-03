/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:29:05 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/03 15:40:43 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <libft.h>
# define BUFF_SIZE 32
# define MAX_FD 10
# define OK 1
# define ERROR -1
# define EXIT 0

int	get_next_line(const int fd, char **line);
#endif
