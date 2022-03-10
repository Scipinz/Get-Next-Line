/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 18:29:38 by kblok         #+#    #+#                 */
/*   Updated: 2022/02/15 17:05:56 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*cpy_res(char *strbuff)
{
	char	*result;
	int		length;
	int		idx;

	idx = 0;
	length = ft_strchr(strbuff, '\n') - strbuff;
	result = (char *)malloc(sizeof(char) * (length + 2));
	if (!result)
		return (NULL);
	while (idx < length)
	{
		result[idx] = strbuff[idx];
		idx++;
	}
	result[idx] = '\n';
	result[idx + 1] = '\0';
	return (result);
}

static char	*dup_remainder(char *strbuff)
{
	char	*temp;

	temp = ft_strchr(strbuff, '\n') + 1;
	if (*temp)
	{
		temp = ft_strdup(temp);
		if (!temp)
			return (0);
		free (strbuff);
		return (temp);
	}
	free (strbuff);
	return (0);
}

static char	*find_newline(int fd, char **strbuff, int bytes)
{
	char	*endres;

	if (ft_strchr(*strbuff, '\n'))
	{
		endres = cpy_res(*strbuff);
		if (!endres)
			return (NULL);
		*strbuff = dup_remainder(*strbuff);
		return (endres);
	}
	else if (bytes != 0)
		return (get_next_line(fd));
	endres = *strbuff;
	*strbuff = NULL;
	return (endres);
}

static char	*static_contents(int fd, char **strbuff, char *buff, int bytes)
{
	char	*temp;

	if (*strbuff == NULL && bytes)
	{
		*strbuff = ft_strdup(buff);
		if (!*strbuff)
			return (NULL);
	}
	else
	{
		temp = ft_strjoin(*strbuff, buff);
		if (!temp)
			return (NULL);
		*strbuff = temp;
	}
	return (find_newline(fd, &*strbuff, bytes));
}

char	*get_next_line(int fd)
{
	static char	*strbuff;
	char		buff[BUFFER_SIZE + 1];
	int			bytes;

	bytes = read(fd, buff, BUFFER_SIZE);
	if (fd < 0 || bytes < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buff[bytes] = '\0';
	return (static_contents(fd, &strbuff, buff, bytes));
}
