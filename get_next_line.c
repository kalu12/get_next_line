/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvuceno <luvuceno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:45:17 by luvuceno          #+#    #+#             */
/*   Updated: 2023/03/05 13:45:46 by luvuceno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	line = malloc(sizeof(char) * i + 2);
	i = 0;
	while (buffer[i])
	{
		line[i] = buffer[i];
		if (buffer[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	line[i] = '\0';
	free(buffer);
	return (line);
}

char	*save_remainer(char *buffer)
{
	int		i;
	int		i2;
	char	*remainer;

	i = 0;
	i2 = 0;
	remainer = NULL;
	while (buffer[i])
	{
		if (buffer[i] == '\n' && buffer[i + 1] != '\0')
		{
			remainer = malloc(ft_strlen(buffer) - i);
			i++;
			while (buffer[i])
			{
				remainer[i2] = buffer[i];
				i++;
				i2++;
			}
			remainer[i2] = '\0';
			break ;
		}
		i++;
	}
	return (remainer);
}

void	append_to_buffer(char **buffer, char *tmp_buffer)
{
	int		i;
	int		i2;
	char	*string;

	i = 0;
	string = malloc(sizeof(char) * (ft_strlen(*buffer)
				+ ft_strlen(tmp_buffer) + 1));
	while (*buffer && (*buffer)[i])
	{
		string[i] = (*buffer)[i];
		i++;
	}
	i2 = i;
	i = 0;
	while (tmp_buffer[i])
	{
		string[i2] = tmp_buffer[i];
		i++;
		i2++;
	}
	string[i2] = '\0';
	if (*buffer)
		free (*buffer);
	*buffer = string;
}

int	read_file(char **buffer, const int fd)
{
	char	tmp_buffer[BUFFER_SIZE + 1];
	int		byte_count;

	ft_bzero(tmp_buffer, BUFFER_SIZE + 1);
	byte_count = read(fd, tmp_buffer, BUFFER_SIZE);
	if (byte_count > 0)
		append_to_buffer(buffer, tmp_buffer);
	return (byte_count);
}

char	*get_next_line(const int fd)
{
	static char	*remainer;
	char		*buffer;

	if (fd < 0)
		return (NULL);
	buffer = NULL;
	if (remainer)
		append_remainer_to_buffer(&buffer, &remainer);
	while (!check_for_new_line(buffer))
	{
		if (read_file(&buffer, fd) <= 0)
			break ;
	}
	if (!buffer)
		return (NULL);
	remainer = save_remainer(buffer);
	return (get_line(buffer));
}
