/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:20:20 by asanson           #+#    #+#             */
/*   Updated: 2021/01/24 21:34:03 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

size_t			ft_strlen(const char *str);
char			*ft_strdup(char *str);
char			*ft_strjoin(const char *s1, const char *s2);
int				is_line(char *str);
char			*get_rest(char *stock);
char			*get_line(char *stock);
int				get_next_line(int fd, char **line);

#endif
