/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:48:53 by hmestre-          #+#    #+#             */
/*   Updated: 2023/05/21 12:35:07 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  DESCRIPTION
 *  this function returns a line read from a file descriptor
 *  EOL is defined by a /n or EOF (\0) char
 *
 * INPUTS
 * fd = file descriptor
 * BUFFER_SIZE -> defined by the compiler call -D BUFFER_SIZE=n (if not
 * defined during compilation it is = 1 as per header file).
 *
 * OUTPUTS
 * returned value = read line (correct behaviour) or NULL (if any error ocurs)
 *
 * REQUIRED FILES
 * get_net_line.h
 *
 * EXTERNAL/LIBRARY FUNCTIONS
 * ft_str_len, ft_substr, ft_strjoin, null_free
 *
 
*/
#include "get_next_line.h"

//	tmp_read[0] = '\0';

char	*null_free(char**	str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*read_line(int fd, char **storage, char *check_read)
{
	char	*tmp_read;
	int		int_read;
	char	*str_res;

	str_res = NULL;
	while (*check_read == '0')
	{
		tmp_read = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!tmp_read || BUFFER_SIZE == 0)
			return (NULL);
		int_read = read(fd, tmp_read, BUFFER_SIZE);
		if (int_read == -1)
			return (null_free(&tmp_read));
		if (int_read == 0)
			*check_read = '\0';
		else
		{
			*(tmp_read + BUFFER_SIZE)  = '\0';
			*storage = ft_strjoin(*storage, tmp_read);
			if (!storage)
				return (null_free(storage));
		}
		str_res = (process_results(storage, check_read));
	}
return (str_res);
}

char	*process_results(char **s, char *check_read)
{
	char	*tmp;
	char	*str_res;

	str_res = NULL;
	if (!*s)
		return(null_free(s));
	if (ft_strchr(*s, '\n'))
	{
		*check_read = '\n';
		str_res = ft_substr(*s, 0, ft_strchr(*s, '\n') - *s + 1);
		tmp = ft_substr(ft_strchr(*s,'\n'), 1, strlen_oknul(ft_strchr(*s, '\n') - 1));
		if (!tmp)
			null_free(s);
		free(*s);
		*s = tmp;
	}
	return (str_res);
}

char	*get_next_line(int fd)
{
	static char *storage = NULL;
	char 		*str_res;
	char		check_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	check_read = '0';
	str_res = NULL;
	str_res = process_results(&storage, &check_read);
	str_res = read_line(fd, &storage, &check_read);
	if (str_res == NULL)
		null_free(&storage);
	return (str_res);
}


char	*ret_and_free(char**	str)
{
	char	*tmp;

	tmp = *str;
	null_free(str);
	return tmp;
}

