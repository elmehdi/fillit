/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 20:44:57 by elfetoua          #+#    #+#             */
/*   Updated: 2019/06/20 20:56:22 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	validation_part3(t_bloc *blc, int i, char *line)
{
	while (blc)
	{
		if (blc->next == NULL)
		{
			ft_strcpy(blc->fill[i - 1], line);
			if (i <= 4)
				break ;
		}
		else if (blc->next != NULL)
			blc = blc->next;
	}
}

t_bloc	*validation_part2(int fd, t_bloc *head, t_bloc *blc, int i)
{
	t_bloc	*new;
	char	*line;

	while (get_next_line(fd, &line) > 0)
	{
		if ((i % 5) != 0)
		{
			blc = head;
			validation_part3(blc, i, line);
		}
		else
		{
			i = 0;
			new = nd_creat();
			add(head, new);
		}
		i++;
	}
	return (head);
}

void	validation(char *stream, int i)
{
	int		fd;
	t_bloc	*blc;
	t_bloc	*head;

	i = 1;
	blc = nd_creat();
	head = blc;
	fd = open(stream, O_RDONLY);
	//head = validation_part2(fd, head, blc, i);
	printf("%s", head->fill[i++]);
	while(head)
	{
		int		j = 0;
		while(j < 4)
			printf("%s", head->fill[j++]);
		head = head->next;
	}
}
