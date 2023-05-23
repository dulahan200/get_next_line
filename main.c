/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:35:42 by hmestre-          #+#    #+#             */
/*   Updated: 2023/05/23 20:01:03 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <string.h>
// #include "get_next_line_bonus.h"
//leaks -atExit -- ./a.out

int     main (int argc, char**	argv)
{
	int		fd;
	char	*str;
	int		i;
	i = 0;

	str = NULL;
/*	fd = open("test_files/nl", O_RDONLY);
			printf("invocation num 1");
			str = get_next_line(fd);
			printf("str(main) =	|%s|\n", str);
			free(str);
			printf("\n");
			close(fd);
	fd = open("test_files/NULL", O_RDONLY);
			printf("invocation num 2");
			str = get_next_line(fd);
			printf("str(main) =	|%s|\n", str);
			free(str);
			printf("\n");
*/
	fd = open(argv[1], O_RDONLY);
		while (i++ < 3)
		{
			printf("invocation num %d\n", i);
			str = get_next_line(fd);
			printf("str(main) =	|%s|\n", str);
			printf("\n");
			free(str);
		}
}
