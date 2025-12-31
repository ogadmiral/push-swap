/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:55:46 by mdamouh           #+#    #+#             */
/*   Updated: 2025/11/30 14:18:16 by mdamouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_fill_tmp(int fd, char *tmp)
{
	char	*buffer;
	ssize_t	bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!tmp)
		tmp = ft_emptystr();
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && tmp && !ft_strchr(tmp, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (free(tmp), NULL);
		}
		buffer[bytes] = '\0';
		if (bytes > 0)
			tmp = ft_strjoin(tmp, buffer);
	}
	free(buffer);
	return (tmp);
}

char	*ft_line(char *tmp)
{
	int		i;
	char	*line;

	i = 0;
	if (!tmp || !tmp[i])
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_next(char *tmp)
{
	int		i;
	int		c;
	char	*newtmp;

	i = 0;
	if (!tmp)
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
	{
		free(tmp);
		return (NULL);
	}
	i++;
	newtmp = malloc(ft_strlen(tmp) - i + 1);
	if (!newtmp)
		return (NULL);
	c = 0;
	while (tmp[i])
		newtmp[c++] = tmp[i++];
	newtmp[c] = '\0';
	free(tmp);
	return (newtmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp[1048576];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp[fd] = ft_fill_tmp(fd, tmp[fd]);
	if (!tmp[fd])
		return (NULL);
	line = ft_line(tmp[fd]);
	tmp[fd] = ft_next(tmp[fd]);
	return (line);
}
