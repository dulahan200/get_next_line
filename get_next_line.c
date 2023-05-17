/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:48:53 by hmestre-          #+#    #+#             */
/*   Updated: 2023/05/17 19:59:58 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  DESCRIPTION
 *  this function returns a line read from a file descriptor
 *  EOL is defined by a /n or EOF (\0) char
 *
 * INPUTS
 * fd = file descriptor
 * BUFFER_SIZE -> defined by the compiler call -D BUFFER_SIZE=n (if not
 * defined during compilation it is = 42 as per header file).
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
 *
 * PSEUDOCODE:
 * 1 check if storage exist.Create empty string if not
 *
 * 2 reading loop (if no newline in storage)
 * 	2a Read a step of buffer size and store in tmp_read
 * 	2b concatenate the reading to storage
 * 	2c check for newlines and end of file
 * 3 process results
 *  3a split string onto str_result and storage (for next g_n_l call)
 *  3b Memory cleanup
 *
*/
#include "get_next_line.h"


char	*ret_and_free(char**	str)
{
	char	*tmp;

	tmp = *str;
	null_free(str);
	return tmp;
}

char	*null_free(char**	str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*read_line(int fd, char *check_read)
{
	/*char	*tmp_read;
	int		int_read;

	tmp_read = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp_read || BUFFER_SIZE == 0)
		*check_read = -1;
	*(tmp_read + BUFFER_SIZE)  = '\0';
	int_read = read(fd, tmp_read, BUFFER_SIZE);
	if (int_read == -1)
		*check_read = 'f';
	else if (int_read == 0)
		*check_read = '\0';
		return (tmp_read);*/
	char	*tmp_read;
	int		int_read;

	tmp_read = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(!tmp_read){
		*check_read = -1;
		return NULL;
	}
	tmp_read[0] = '\0';
	int_read = read(fd, tmp_read, BUFFER_SIZE);
	if (int_read == -1)
	{
		free(tmp_read);
		*check_read = 'f';
		return NULL;
	}
	tmp_read[int_read] = '\0';
	if (int_read == 0)
	{
		*check_read = '\0';
		return (tmp_read);
	}
	return (tmp_read);
}

char	*process_results(char **s, char **str_res, char *check_read)
{
	char	*tmp;
	if (*s)
		return("ko");
	if (ft_strchr(*s, '\n'))
	{
		*check_read = '\n';
		*str_res = ft_substr(*s, 0, ft_strchr(*s, '\n') - *s + 1);
		tmp = ft_substr(ft_strchr(*s,'\n'), 1, strlen_oknul(ft_strchr(*s, '\n') - 1));
		if (!tmp)
		{
			free(*s);
			return (NULL);
		}
		free(*s);
		*s = tmp;
	return("ok");
	}
	*str_res = *s;
	return("ok");
}

char	*get_next_line(int fd)
{
	static char *storage = NULL;
	char 		*str_res;
	char		check_read;
	char 		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	line = NULL;
	check_read = '0';
	str_res = NULL;
	process_results(&storage, &str_res, &check_read);
	while (check_read == '0')
	{
		line = read_line(fd, &check_read);
		if(line == NULL || check_read == -1)
			return (null_free(&storage));
		storage = ft_strjoin(storage, line);
		if(!storage)
		{
			free(line);
			return (null_free(&storage));
		}
		if (check_read == 'f')
		{
			free(line);
			return null_free(&storage);
		}
		free(line);
		process_results(&storage, &str_res, &check_read);
	}
	return (str_res);
}

