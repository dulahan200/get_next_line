/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:35:42 by hmestre-          #+#    #+#             */
/*   Updated: 2023/05/18 19:48:49 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <string.h>
// #include "get_next_line_bonus.h"


int     main (int argc, char**	argv)
{
	int		fd;
	char	*str;
	int		i;
	i = 0;
	if (argc == 2)
	{
	fd = open(argv[1], O_RDONLY);
		while (i++ < 3)
		{
			printf("invocation num %d\n", i);
			str = get_next_line(fd);
			printf("str(main) =	|%s|\n", str);
			printf("\n");
		}
	}
}
