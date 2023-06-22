/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvuceno <luvuceno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:47:09 by luvuceno          #+#    #+#             */
/*   Updated: 2023/03/05 13:47:12 by luvuceno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, int len)
{
	int		i;
	char	*p;

	i = 0;
	p = s;
	while (i < len)
	{
		*p = (char)0;
		i++;
		p++;
	}
}

int	check_for_new_line(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	append_remainer_to_buffer(char **buffer, char **remainer)
{
	*buffer = *remainer;
	*remainer = NULL;
}
