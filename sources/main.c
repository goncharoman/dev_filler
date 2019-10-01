/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:53:51 by ujyzene           #+#    #+#             */
/*   Updated: 2019/10/01 22:43:24 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int main(int argc, char *argv[])
{
	t_filler	*filler;

	if (argc != 0)
		argc = 0;
	filler = init_filler();
	if (!get_player_info(0, filler, argv[0]))
	{
		free_filler(filler);
		return (return_error("ERROR: wrong player info string"));
	}
	while (1)
	{
		if (!init_data(0, filler))
			break;
		solve(filler);
		print_result(filler);
		free_data(filler);
	}
	free_filler(filler);
	return (1);
}
