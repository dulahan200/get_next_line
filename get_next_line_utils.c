/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:53:34 by hmestre-          #+#    #+#             */
/*   Updated: 2023/05/18 20:20:55 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
size_t	strlen_oknul(const char *s)
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

storage = ft_strjooin(storage, buffer)

char	*ft_strjoin_old(char *s1, char *s2)
{
	size_t	i;
	size_t	s2_len;
	size_t	s1_len;
	char	*res;

	i = 0;
	if(!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if(!s1)
			return NULL;
		s1[0] = '\0';
	}
	s1_len = strlen_oknul(s1);
	s2_len = strlen_oknul(s2);
	res = (char *) malloc (sizeof(char) * (s1_len + s2_len + 1));
	if (res == NULL)
	{
		free(s1);
		return (NULL);
	}
	while (i < s1_len)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		res[i] = s2[i - s1_len];
		i++;
	}
	res[i] = '\0';
	free(&s1);
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	s2_len;
	size_t	s1_len;
	char	*res;

	i = 0;
	s1_len = strlen_oknul(s1);
	s2_len = strlen_oknul(s2);
	res = (char *) malloc (sizeof(char) * (s1_len + s2_len + 1));
	if (res == NULL)
		return (null_free(&s2));
	while (i < s1_len)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		res[i] = s2[i - s1_len];
		i++;
	}
	if (s1_len + s2_len != 0)
	res[i] = '\0';
	free(s1);
	free(s2);
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	len_s;

	len_s = strlen_oknul(s);
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
	while (i < strlen_oknul(s))
	{
		if (s[i] == (char) c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (NULL);
}
/*
size_t	ft_strlcpy(char *dest, t_cchar *src, size_t dstsize)
{
	size_t	i;
	size_t	size_src;

	size_src = 0;
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && i < (dstsize -1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[size_src])
	{
		size_src++;
	}
	return (size_src);
}*/
/*
char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	s2_size;

	s2_size = strlen_oknul(s1);
	s2 = (char *) malloc(s2_size + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s1, s2_size + 1);
	return (s2);
}*/
