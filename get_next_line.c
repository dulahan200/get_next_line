/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:48:53 by hmestre-          #+#    #+#             */
/*   Updated: 2023/04/29 21:00:20 by hmestre-         ###   ########.fr       */
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
 * 1 check if str_current exist.Create empty string if not
 *
 * 2 reading loop (if no newline in str_current)
 * 	2a Read a step of buffer size and store in tmp_read
 * 	2b concatenate the reading to str_current
 * 	2c check for newlines and end of file
 * 3 process results
 *  3a split string onto str_result and str_current (for next g_n_l call)
 *  3b Memory cleanup
 *
*/
#include "get_next_line.h"

char	*null_free(char**	str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}


char	*get_next_line(int fd)
{
	static char *str_current = NULL;
	char		*tmp_read;
	char		*tmp_leaks;
	char 		*str_res;
//	int	i = 1;

//	printf("Buffer size =	%d\n", BUFFER_SIZE);
	if (!str_current)
		str_current = ft_strdup("");
	if(!str_current)
	{
		null_free(&str_current);
		return (NULL);
	}
	while (!ft_strchr(str_current,'\n'))
	{
	tmp_read = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp_read || BUFFER_SIZE == 0)
		return (NULL);
	*(tmp_read + BUFFER_SIZE)  = '\0';
//	printf("lectura num	%d \n", i++);
		if (read(fd, tmp_read, BUFFER_SIZE) <= 0) 
			return (NULL);
//	printf("tmp_read1 =	|%s|\n", tmp_read);
//	printf("str_current2 =	|%s|\n", str_current);
		tmp_leaks = ft_strjoin(str_current, tmp_read);
		null_free(&str_current);
		null_free(&tmp_read);
		if (!tmp_leaks)
			return (null_free(&str_current));
		str_current = tmp_leaks;
	}
//	printf("str_current2 =	|%s|\n", str_current);
	str_res = ft_substr(str_current, 0, ft_strchr(str_current, '\n') - str_current + 1); 
	tmp_leaks = ft_substr(ft_strchr(str_current,'\n'), 1, ft_strlen(ft_strchr(str_current, '\n') - 1)); 
	if (!tmp_leaks)
			return (null_free(&str_current));
	null_free(&str_current);
	str_current = tmp_leaks;
	return (str_res);
//	ft_strjoin segfault strlen(s1)
//
}
