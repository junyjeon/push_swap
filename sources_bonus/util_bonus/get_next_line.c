/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:43:40 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/20 05:07:19 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

static char	*buf_read(int fd, char *buf, char *save)
{
	ssize_t		read_size;
	char		*tmp;

	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (0);
		buf[read_size] = '\0';
		if (!read_size)
			break ;
		if (!save)
		{
			save = ft_strdup("");
			save[0] = '\0';
		}
		tmp = save;
		save = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (save);
}

static char	*split_idx(char **save, char *line)
{
	int			i;
	char		*tmp;

	if (!(*save) || (*save)[0] == '\0')
	{
		free(*save);
		*save = NULL;
		return (0);
	}
	i = 0;
	while ((*save)[i] != '\n' && (*save)[i])
		i++;
	if ((*save)[i] == '\n')
		i++;
	line = ft_substr((*save), 0, i);
	if (!(*save)[i])
	{
		free(*save);
		*save = NULL;
		return (line);
	}
	tmp = *save;
	*save = ft_substr(tmp, i, ft_strlen(*save) - i);
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	save = buf_read(fd, buf, save);
	free(buf);
	line = 0;
	line = split_idx(&save, line);
	return (line);
}
