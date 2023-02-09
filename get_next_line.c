/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:48:53 by hmestre-          #+#    #+#             */
/*   Updated: 2022/12/27 20:13:10 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  DESCRIPTION
 *  this function returns a line read from a file descriptor
 *
 * INPUTS
 * fd = file descriptor
 * 
 * OUTPUTS
 * returned value = read line (correct behaviour) or NULL (if any error ocurs)
 *
 * EXTERNAL FUNCTIONS
 * ft_str_len, ft_substr, ft_strjoin, free_str

//buffer size is defined by the compiler call -D BUFFER_SIZE=n

 pseudocode:
 * 1 check if str_current exist.Create empty string if not
 *
 * 2 reading loop (if no newline in str_current)
 * 	2a Read a step of buffer size and store in tmp_read
 * 	2b concatenate the reading to str_current
 * 	2c check for newlines
 * 3 process results and cleanup 
 *
 *
*/
#include "get_next_line.h"

char *free_str(int numOfStrings, char **str, ... )
{
	va_list	ap;
	char	** str_i
	
	va_start(ap, str);
	while (i < numOfStrings)
	{
		str_i = (va_arg(ap, char**);
		free(*str_i);
		*str_i = NULL;
	}
	va_end;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char *str_current = NULL;
	char		*tmp_read;
	char		*tmp_leaks;
	char 		*str_res;

	if (!str_current)
		str_current = ft_strdup("");	
	tmp_read = malloc(sizeof(char) * BUFFER_SIZE);
	if (!tmp_read)
		return (NULL);
	while (!ft_strchr(str_current,'\n'))
	{
		if (read(fd, tmp_read, BUFFER_SIZE) == -1) 
			return (NULL);
		tmp_leaks = ft_strjoin(str_current, tmp_read);
		if (!tmp_leaks)
			return (free_str(1, &tmp_read, &str_current));
		free_str(1, &str_current);
		str_current = tmp_leaks;
	}
	// must code the scenario where it reads end of fd
	str_res = ft_substr(str_current, 0, str_current - ft_strchr(str_current, '\n') + 1);
	tmp_leaks = ft_substr(ft_strchr(str_current,'\n'), 1, ft_strlen(ft_strchr(str_current, '\n') - 1);
	if (!tmp_leaks)
	//check what happens when the read is exactly a line vs a failed malloc
		return (free_str(1, &tmp_read));
	free_str(1, &str_current);
	str_current = tmp_leaks;
	free_str(1, tmp_leak);
	free_str(1, tmp_read);
	return (str_res);
//	probably missing: returned line must contain newline.
//	ft_strjoin segfault strlen(s1)
//
}
/*
char	*get_next_line(int fd)
{
	char 		*str_res;
	static char *str_previous;
	char		*tmp_read;
// estas lineas antes del while inicializan tmp_read (creo que es necesario)
	tmp_read  = (tmp_read + ft_strlen(tmp_read)) = malloc(sizeof(char) * BUFFER_SIZE);
	if (!tmp_read)
		return NULL;
	read(fd, tmp_read + ft_strlen(tmp_read));
	while (ft_strchr(tmp_read,'\n') == NULL)
	{
	if (!(tmp_read + ft_strlen(tmp_read)) = malloc(sizeof(char) * BUFFER_SIZE))       //are () needed? //malloc de tmp_read ampliando a buffer size
		return (NULL);
	if (read(fd, tmp_read +ft_strlen(tmp_read))); //buffer size is defined by the compiler call -D BUFFER_SIZE=n
	}
	str_res = ft_substr(tmp_read, 0, tmp_read - ft_strchr(tmp_read, '\n'));
	str_res = ft_strjoin_withfree(str_previous, tmp);
	free(str_previous);
	str_previous = malloc(ft_strlen()
	}
	*/

