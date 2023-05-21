/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:48:53 by hmestre-          #+#    #+#             */
/*   Updated: 2023/05/18 20:03:17 by hmestre-         ###   ########.fr       */
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
	char buffer[BUFFER_SIZE + 1];
	int  num_bites;

	num_bites= 1;
	buffer[0] = '\0';
	while(num_bites && !ft_strchr(buffer, '\n'))
	{
		num_bites = read(fd, buffer, BUFFER_SIZE);
		if(num_bites == -1)
		{
			free(storage);
			return NULL;
		}
		buffer[num_bite] = '\0';
		if(num_bite > 0)
			storage = ft_strjoin(storage, buffer);
	}
	return storage;
}
	/*char	*tmp_read;
	int		int_read;

	tmp_read = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp_read || BUFFER_SIZE == 0)
		*check_read = 'm';
	*(tmp_read + BUFFER_SIZE)  = '\0';
	int_read = read(fd, tmp_read, BUFFER_SIZE);
	if (int_read == -1)
		*check_read = 'f';
	else if (int_read == 0)
		*check_read = '\0';
		return (tmp_read);*/

	/*
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
	*/
}

/**/
char	*process_results(char **s, char **str_res, char *check_read)
{
	char	*tmp;
	if (!*s)
		return("no storage");
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
	*str_res = *s; ///tengo que remirar esto
	return("ok");
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
	//En storage ya tengo una linea
	if(!storage || (storage && !ft_strchr(storage, '\n')))
		storage = read_in_bucle(fd, storage);
	if(!storage)
		return(NULL)
	//Si ya tengo una linea, no me hacve falta leer
	//Si no tengo una linea si que me hace falta leer
	//   -- LLamo a la funcion leer hasta que en buffer tenga una linea, final de arvchivo,     //      o error
	// Si storage es NULL , salgo con NULL
	// Si no , llamo a funcion extraer una linea de Storage
	// Si linea = NULL algo a fallado, salgo limpio con NULL
	// Coje mi Storage, y me lo limpias quitando la primera linea que encuentre
	process_results(&storage, &str_res, &check_read);
	while (check_read == '0')
	{
		storage = ft_strjoin(storage, read_line(fd, &check_read));
		if(check_read == 'm' || check_read == 'f')
			return (null_free(&storage));
		if(!storage)
			return (null_free(&storage));
		process_results(&storage, &str_res, &check_read);
	}
	return (str_res);
}


char	*ret_and_free(char**	str)
{
	char	*tmp;

	tmp = *str;
	null_free(str);
	return tmp;
}

