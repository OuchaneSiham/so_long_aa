/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:11:52 by souchane          #+#    #+#             */
/*   Updated: 2024/02/26 18:55:55 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_check_file(char *f_str)
{
	int fd;
	unsigned long len;
	char *a;
	len = ft_strlen((const char *)f_str);
	a = f_str + (len - 4);
	if (ft_strcmp(a, ".ber") || ft_strlen((const char *)f_str) <= 4)
	{
		printf("error");
		exit(1);
	}
	fd = open(f_str, O_RDONLY);
	if (fd == -1)
	{
		printf("error");
		exit(1);
	}
	return (fd);
}