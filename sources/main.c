/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:53:51 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/30 03:35:10 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int main(void)
{
	t_filler	*filler;

	filler = init_filler();
	get_player_info(0, filler);
	while (1)
	{
		if (!init_data(0, filler))
			break;
		solve(filler);
		// test(filler);
		print_result(filler);
		free_data(filler);
	}
	free_filler(filler);
	return (0);
}
