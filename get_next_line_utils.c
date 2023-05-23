/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:53:34 by hmestre-          #+#    #+#             */
/*   Updated: 2023/05/23 20:38:47 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen0(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s && (*s != '\0'))
	{
		counter++;
		s++;
	}
	return (counter);
}

int	null_free(char **str, int err_code)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (err_code);
}

char	*ft_strjoin(char *s1, char *s2)
{
	ssize_t	i;
	ssize_t	s2_len;
	ssize_t	s1_len;
	char	*res;

	i = -1;
	s1_len = strlen0(s1);
	s2_len = strlen0(s2);
	res = (char *) malloc (sizeof(char) * (s1_len + s2_len + 1));
	if (res == NULL)
	{
		free(s1);
		return (NULL);
	}
	while (++i < s1_len)
		res[i] = s1[i];
	while (i < s1_len + s2_len)
	{
		res[i] = s2[i - s1_len];
		i++;
	}
	if (s1_len + s2_len != 0)
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	len_s;

	len_s = strlen0(s);
	i = 0;
	if (start >= len_s)
		sub_str = malloc(sizeof(char) * 1);
	else if (len >= len_s - start + 1)
		sub_str = malloc(sizeof(char) * (len_s - start + 1));
	else
		sub_str = malloc(sizeof(char) * (len + 1));
	if (sub_str == NULL)
		return (NULL);
	while (start + i < len_s && i < len)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (i < strlen0(s))
	{
		if (s[i] == (char) c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (NULL);
}
