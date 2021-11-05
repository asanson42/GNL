/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:51:15 by asanson           #+#    #+#             */
/*   Updated: 2021/01/24 21:25:31 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_rest(char *stock)
{
	char	*nrest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stock)
		return (0);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (0);
	}
	nrest = malloc(sizeof(char) * ((ft_strlen(stock) - i) + 1));
	if (!nrest)
		return (0);
	i++;
	while (stock[i])
		nrest[j++] = stock[i++];
	nrest[j] = '\0';
	free(stock);
	return (nrest);
}

char	*get_line(char *stock)
{
	int		i;
	char	*nline;

	i = 0;
	if (!stock)
		return (0);
	while (stock[i] && stock[i] != '\n')
		i++;
	nline = malloc(sizeof(char) * (i + 1));
	if (!nline)
		return (0);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		nline[i] = stock[i];
		i++;
	}
	nline[i] = '\0';
	return (nline);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*stock = 0;
	int			ret;

	ret = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (!is_line(stock) && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (stock == 0)
			stock = ft_strdup("");
		stock = ft_strjoin(stock, buff);
	}
	*line = get_line(stock);
	stock = get_rest(stock);
	if (ret == 0)
		return (0);
	return (1);
}
