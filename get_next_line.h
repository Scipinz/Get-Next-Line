/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 12:24:26 by kblok         #+#    #+#                 */
/*   Updated: 2022/02/16 11:29:30 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);

#endif