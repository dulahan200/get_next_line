/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:48:53 by hmestre-          #+#    #+#             */
/*   Updated: 2023/05/15 21:05:02 by hmestre-         ###   ########.fr       */
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

char	*read_line(int fd, char **str_res, char *check_read)
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
	else if (int_read == 0) 
	{
		*check_read = '\0';
		return(tmp_read);
	}
	else 
	{
		process_results(&tmp_read, str_res, check_read);
	}
		return (tmp_read);
}

char	*process_results(char **s, char **str_res, char *check_read)
{
	char	*tmp;

	if (ft_strchr(*s, '\n'))
	{
		*check_read = '\n';
		*str_res = ft_substr(*s, 0, ft_strchr(*s, '\n') - *s + 1); 
		tmp = ft_substr(ft_strchr(*s,'\n'), 1, strlen_oknul(ft_strchr(*s, '\n') - 1)); 
		if (!tmp)
		{
			return (null_free(s));
		}
		null_free(s);
		*s = tmp;
	}
	return("patata");    ////MUST FIX RETURN VALUE 
}

char	*get_next_line(int fd)
{
	static char *storage = NULL;
	char		*tmp_curr;
	char 		*str_res;
	char		check_read;

	check_read = '0';
	if (!storage)
		storage = ft_strdup("");
	if(!storage)
	{
		null_free(&storage);
		return (NULL);
	}
	str_res = NULL;
	process_results(&storage, &str_res, &check_read);
	while (check_read == '0')
	{
		tmp_curr = ft_strjoin(storage, read_line(fd, &str_res, &check_read));
		
		if (check_read == 'f')
			return (null_free(&storage));
		if (!tmp_curr) 
		//	return (storage); //might need to be NULL
			return (NULL);// with current code, the case of str_res being null before entering gets covered by calling process_results early and not entering the while loop
		storage = tmp_curr;
		null_free(&tmp_curr);
//process results must come here, not inside read_line!!!!!!!!!!!!!!!!!!
	}
	return (str_res);
}
