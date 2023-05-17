/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:35:42 by hmestre-          #+#    #+#             */
/*   Updated: 2023/05/17 19:52:00 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
// #include "get_next_line_bonus.h"


int     main (int argc, char**	argv)
{
	int		fd;
	char	*folder;
	char	*file;
	char	*str;
	int		i;
	i = 0;
	if (argc == 2)
	{
	folder = strdup("test_files/");
	file = strcat(folder, argv[1]);
	printf("%s\n", file);
	fd = open(file, O_RDONLY);
//		printf("fd = %d\n", fd);
		while (i++ < 3)
		{
			printf("invocation num %d\n", i);
			str = get_next_line(fd);
			printf("str(main) =	|%s|\n", str);
			printf("\n");
		}
	}
}
