/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:53:51 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/25 14:59:12 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int main(void)
{
	t_filler	*filler;

	// TEST
	// int f = open("test", O_RDONLY);

	filler = filler_init();
	get_player_info(0, filler);
	while (1)
	{
		init_data(0, filler);
		test(filler);
	}
	return (0);
}
