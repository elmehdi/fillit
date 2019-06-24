/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:45:31 by elfetoua          #+#    #+#             */
/*   Updated: 2019/05/21 23:50:15 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line_rest(char *holder, char **line)
{
	int		i;
	char	*rst;

	i = 0;
	while (holder[i] != '\n' && holder[i])
		i++;
	*line = ft_strsub(holder, 0, i);
	if (holder[i] == '\n')
		rst = ft_strdup(&holder[i] + 1);
	else
		rst = ft_strnew(0);
	return (rst);
}

void	gnl_helper(int fd, char **holder, int *rd)
{
	char *buff;
	char *tmp;

	buff = ft_strnew(BUFF_SIZE);
	while ((*rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[*rd] = '\0';
		tmp = ft_strjoin((*holder), buff);
		free((*holder));
		(*holder) = tmp;
		if (ft_strchr((*holder), '\n'))
			break ;
	}
	free(buff);
}

int		get_next_line(int fd, char **line)
{
	static char	*holder[FD];
	int			rd;
	char		*tmp;

	rd = 0;
	if (fd < 0 || !line || fd > 4864 || BUFF_SIZE < 0)
		return (-1);
	if (!holder[fd])
		holder[fd] = ft_strnew(0);
	if (!ft_strchr(holder[fd], '\n'))
		gnl_helper(fd, &(holder[fd]), &rd);
	if (rd < 0)
		return (-1);
	if (!rd && !ft_strlen(holder[fd]))
		return (0);
	tmp = ft_line_rest(holder[fd], line);
	free(holder[fd]);
	holder[fd] = tmp;
	return (1);
}
