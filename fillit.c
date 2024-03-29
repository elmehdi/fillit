/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:35:05 by elfetoua          #+#    #+#             */
/*   Updated: 2019/06/27 05:45:27 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	usage(void)
{
	write(1, "usage: ./fillit target_file\n", 28);
}

int 			main(int argc, char **argv)
{
	int		i;
	if (argc != 2)
		usage();
	else
	{
		i = 0;
		if (verification(argv[1]))
			if (validation(argv[1], i))
				write(1, "0the file is valid", 18);
			else
				write(1, "the file isn't valid", 21);
		else
			write(1, "the file isn't valid", 21);
	}
}