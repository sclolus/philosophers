/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 05:02:58 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/18 18:45:10 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

static void		ft_get_file_content_string(t_string *string, int fd)
{
	static char	buffer[BUFF_SIZE];
	ssize_t		n;

	while ((n = read(fd, buffer, BUFF_SIZE)))
		ft_t_string_concat_len(string, buffer, n);
}

char			*ft_get_file_content(char *filename)
{
	t_string	string;
	int			fd;

	if (!(string.string = (char*)malloc(sizeof(char) * 256)))
		ft_error_exit(1, (char*[]){ERR_GET_FILE_CONTENT_MALLOC}, EXIT_FAILURE);
	string.capacity = 256;
	string.len = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_error(2, (char*[]){ERR_FILE_OPEN
					, filename}, 0);
		free(string.string);
		return (NULL);
	}
	string.string[0] = '\0';
	ft_get_file_content_string(&string, fd);
	return (string.string);
}
