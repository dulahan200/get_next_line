/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:48:53 by hmestre-          #+#    #+#             */
/*   Updated: 2023/05/23 17:32:56 by hmestre-         ###   ########.fr       */
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

static int	read_line(int fd, char **storage);
static char	*process_results(char **s);

int	null_free(char **str, int err_code)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (err_code);
}

/*read_line stores in a buffer a loop read on fd that stops on \n or EOF
 * RETURN VALUES
 * -1	malloc fails
 * -2	read fails
 * 0	EOF without \n
 * >0	end of line within buffer
 */
static int	read_line(int fd, char **storage)
{
	char	*tmp_read;
	int		int_read;

	int_read = 1;
	tmp_read = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp_read)
		return (null_free(storage, -1));
	while (int_read > 0 && !ft_strchr(*storage, '\n'))
	{
		int_read = read(fd, tmp_read, BUFFER_SIZE);
		if (int_read == -1)
		{
			null_free(storage, -2);
			return (null_free(&tmp_read, -2));
		}
		else if (int_read > 0)
		{
			tmp_read[int_read] = '\0';
			*storage = ft_strjoin(*storage, tmp_read);
			if (!storage)
			{
				free (tmp_read);
				return (null_free(storage, -1));
			}
		}
	}
	free(tmp_read);
	return (int_read);
}

static char	*process_results(char **s)
{
	char	*tmp;
	char	*str_res;

	str_res = NULL;
	if (!*s)
	{
		null_free(s, 0); //not sure if it adds value
		return (NULL);
	}
	if (ft_strchr(*s, '\n'))
	{
		str_res = ft_substr(*s, 0, ft_strchr(*s, '\n') - *s + 1);
		tmp = ft_substr(ft_strchr(*s, '\n'), 1, strlen_oknul(ft_strchr(*s, '\n') ));
		null_free(s, 0);
		*s = tmp;
		if (!tmp)
			return (NULL);
	//	tmp = NULL; //not really needed but helps with paco nullchecks
		return (str_res);
	}
	else if (strlen_oknul(*s) >0)
	{
		str_res = ft_substr(*s, 0, ft_strchr(*s, '\0') - *s);
	}
		null_free(s, 0);
	return (str_res);
}

char	*get_next_line(int fd)
{
	static char *storage = NULL;
	char		*str_res;
	int			err;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_res = NULL;
	err = read_line(fd, &storage);
	if (storage == NULL || err < 0)
		return (NULL);
	str_res = process_results(&storage);
	if (err == 0)
		null_free(&storage, 0);
	return (str_res);
}
