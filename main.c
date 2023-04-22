/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmestre- <hmestre-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:35:42 by hmestre-          #+#    #+#             */
/*   Updated: 2023/04/22 22:25:35 by hmestre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include "get_next_line_bonus.h"

int     main (void)
{
	int		fd;
	char	*str;
	int		i;

	fd = open("test2", O_RDONLY);
	
	while (i++ < 3)
	{
	printf("invocation num %d\n", i);
	str = get_next_line(fd);
//	printf("str =	%s\n", str);
	printf("\n");
	}
}
