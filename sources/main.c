/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:53:51 by ujyzene           #+#    #+#             */
/*   Updated: 2019/09/24 11:55:09 by ujyzene          ###   ########.fr       */
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
		get_params(0, filler);
		init_imap(filler);
		test(filler);
	}
	return (0);
}
