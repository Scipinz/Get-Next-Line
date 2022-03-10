/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 18:21:15 by kblok         #+#    #+#                 */
/*   Updated: 2022/02/16 11:29:16 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		idx;

	ptr = malloc((ft_strlen(str) + 1) * sizeof(char));
	idx = 0;
	if (!ptr)
		return (0);
	while (str[idx] != '\0')
	{
		ptr[idx] = str[idx];
		idx++;
	}
	ptr[idx] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*str3;
	int		idx1;
	int		idx2;

	idx1 = 0;
	idx2 = 0;
	if (!str1 || !str2)
		return (0);
	str3 = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!str3)
		return (0);
	while (str1[idx1] != '\0')
	{
		str3[idx1] = str1[idx1];
		idx1++;
	}
	while (str2[idx2] != '\0')
	{
		str3[idx1] = str2[idx2];
		idx1++;
		idx2++;
	}
	str3[idx1] = '\0';
	free(str1);
	return (str3);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return (((char *)str) + ft_strlen(str));
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
		{
			return ((char *)str + i);
		}
		i++;
	}
	if (str[i] == (unsigned char)c)
	{
		return ((char *)str + i);
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}
