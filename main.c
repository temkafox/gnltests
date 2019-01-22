/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:38:13 by ldonnis           #+#    #+#             */
/*   Updated: 2019/01/20 20:16:03 by ldonnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char const *argv[]) {
	int fd;
	int fd_2;
	int i;
	char *line;
	int status;

	fd = open(argv[1], O_RDONLY);
	i = 1;
	while ((status = get_next_line(fd, &line)) > 0)
	{
		printf("[Return: %d] [Line #%d] %s\n", status, i++, line);
		free(line);
	}
	printf("[Return: %d] [Line #%d] %s\n", status, i++, line);
	if (status == -1)
		printf("-----------\nError\n");
	else if (status == 0)
		printf("-----------\nEnd of file\n");
	close(fd);
	fd_2 = open(argv[2], O_RDONLY);
	while ((status = get_next_line(fd_2, &line)) > 0)
	{
		printf("[Return: %d] [Line #%d] %s\n", status, i++, line);
		free(line);
	}
	printf("[Return: %d] [Line #%d] %s\n", status, i++, line);
	if (status == -1)
		printf("-----------\nError\n");
	else if (status == 0)
		printf("-----------\nEnd of file\n");
	close(fd_2);
	return (argc);
}