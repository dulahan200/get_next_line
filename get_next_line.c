/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:48:53 by hmestre-          #+#    #+#             */
/*   Updated: 2023/05/09 19:14:05 by hmestre-         ###   ########.fr       */
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

/*
 * Read_line keeps reading from fd until \n or EOF, returning the
 *  string of read characters. 
 */

char	*read_line(int fd, char *check_read)
{
	char	*tmp_read;
	int		int_read;

	tmp_read = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp_read || BUFFER_SIZE == 0)
		*check_read = -1;
	*(tmp_read + BUFFER_SIZE)  = '\0';
	int_read = read(fd, tmp_read, BUFFER_SIZE); 
	if (int_read == -1 || int_read == 0)
		*check_read = 'f';
	else if	(ft_strchr(tmp_read, '\n'))
		*check_read = '\n';
	else if	(ft_strchr(tmp_read, '\0') == tmp_read + BUFFER_SIZE + 1)
		*check_read = '\0';
//	printf("tmp_read =	|%s|\n", tmp_read);
	return (tmp_read);
}

void	process_results(char **str, char **str_res, char *check_read)
{
	if ft_strchr(str, '\n')
	{
		check_read == '\n';
		str_res = ft_substr(str, 0, ft_strchr(str, '\n') - str + 1); 
		tmp_curr = ft_substr(ft_strchr(str,'\n'), 1, strlen_oknul(ft_strchr(str, '\n') - 1)); 
		if (!tmp_curr)
		{
			printf("error during substring";	////// printf is a forbidden in this project, remember to del line
			return (null_free(&str_current));
		}
		null_free(&str_current);
		str_current = tmp_curr;
	}
	else if	(ft_strchr(str, '\0') == str)
	{
		*check_read = '\0';
		str_res = str;
		null_free(&str);
	}
}

char	*get_next_line(int fd)
{
	static char *str_current = NULL;
	char		*tmp_curr;
	char 		*str_res;
	char		check_read;

	check_read = '0';
	if (!str_current)
		str_current = ft_strdup("");
	if(!str_current)
	{
		null_free(&str_current);
		return (NULL);
	}
	str_res = NULL;
	while (check_read == '0')
	{
		tmp_curr = ft_strjoin(str_current, read_line(fd, &check_read));
		if (check_read == 'f')
		return (str_current); //idk if you can (should) null_free static variables
		if (!tmp_curr) 
			return (str_current); //might need to be NULL
		str_current = tmp_curr;
//		printf("str_current=	|%s|	check_read =	|%d|\n",str_current, check_read);
	}
	if (check_read == '\0')/// a lo bruto, hay que mejorarlo
		return (ret_and_free(&str_current));
	str_res = ft_substr(str_current, 0, ft_strchr(str_current, '\n') - str_current + 1); 
	tmp_curr = ft_substr(ft_strchr(str_current,'\n'), 1, strlen_oknul(ft_strchr(str_current, '\n') - 1)); 
	if (!tmp_curr)
			return (null_free(&str_current));
	null_free(&str_current);
	str_current = tmp_curr;
	return (str_res);
}

/*
char	*get_next_line(int fd)
{
	static char *str_current = NULL;
	char		*tmp_read;
	char		*tmp_curr;
	char 		*str_res;
//	int	i = 1;
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
	tmp_read[0] = '\0'; //// alternative to verify end of read without storing return value
//	printf("lectura num	%d \n", i++);			///////
//		if (read(fd, tmp_read, BUFFER_SIZE) <= 0) 
		if (read(fd, tmp_read, BUFFER_SIZE) == -1) 
			return (NULL);
		if (tmp_read[0] == '\0')
			return (str_current);
//	printf("tmp_read1 =	|%s|\n", tmp_read);
//	printf("str_current2 =	|%s|\n", str_current);
		tmp_curr = ft_strjoin(str_current, tmp_read);
		null_free(&str_current);
		null_free(&tmp_read);
		if (!tmp_curr)
			return (null_free(&str_current));
		str_current = tmp_curr;
	}
//	printf("str_current2 =	|%s|\n", str_current);
	str_res = ft_substr(str_current, 0, ft_strchr(str_current, '\n') - str_current + 1); 
	tmp_curr = ft_substr(ft_strchr(str_current,'\n'), 1, strlen_oknul(ft_strchr(str_current, '\n') - 1)); 
	if (!tmp_curr)
			return (null_free(&str_current));
	null_free(&str_current);
	str_current = tmp_curr;
	return (str_res);
//	ft_strjoin segfault strlen(s1)
//
}*/
