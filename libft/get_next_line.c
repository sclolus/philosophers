/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 02:08:07 by sclolus           #+#    #+#             */
/*   Updated: 2016/12/20 23:30:27 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static t_list	*ft_goto_fd_lst(int fd, t_list *lst)
{
	t_fd_data	*new;

	if (lst->content && ((t_fd_data*)lst->content)->fd == fd)
		return (lst);
	else if (lst->next)
		return (ft_goto_fd_lst(fd, lst->next));
	else
	{
		if (!(new = (t_fd_data*)malloc(sizeof(t_fd_data))))
			return (0);
		new->fd = fd;
		new->current = new->buf + BUFF_SIZE;
		ft_bzero(new->buf, BUFF_SIZE + 1);
		if (!(lst->next = (t_list*)malloc(sizeof(t_list))))
			return (0);
		lst->next->next = 0;
		lst->next->content = new;
		return (lst->next);
	}
}

static int		ft_join_line(char **line, t_fd_data *current_buf)
{
	char			*tmp_line;

	tmp_line = *line;
	*current_buf->current++ = '\0';
	if (!(*line = ft_strjoin(tmp_line, current_buf->buf)))
		return (-1);
	free(tmp_line);
	return (1);
}

static int		ft_use_garbage(char **line, t_fd_data *current)
{
	char	*tmp;
	char	*tmp_line;

	tmp_line = *line;
	if ((tmp = ft_strchr(current->current, '\n')))
	{
		*tmp = '\0';
		if (!(*line = ft_strjoin(*line, current->current)))
			return (-1);
		free(tmp_line);
		current->current = tmp + 1;
		return (1);
	}
	*line = ft_strjoin(*line, current->current);
	free(tmp_line);
	current->current = current->buf + BUFF_SIZE;
	return (0);
}

static int		ft_get_line(const int fd, char **line, t_fd_data *content)
{
	int	tmp;
	int	bool_wrote;

	bool_wrote = 0;
	while ((tmp = read(fd, content->buf, BUFF_SIZE)) > 0)
	{
		bool_wrote = 1;
		content->buf[tmp] = '\0';
		if ((content->current = ft_strchr(content->buf, '\n')))
			return (ft_join_line(line, content));
		content->current = content->buf + BUFF_SIZE;
		if (ft_join_line(line, content) == -1)
			return (-1);
	}
	return ((tmp == -1) ? -1 : bool_wrote);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	list_fd;
	t_list			*current_lst;
	t_fd_data		*content;
	int				bool_wrote;
	int				tmp;

	bool_wrote = 0;
	if (!(current_lst = ft_goto_fd_lst(fd, &list_fd)) || !line)
		return (-1);
	content = current_lst->content;
	if (!(*line = ft_strnew(0)))
		return (-1);
	if (*(content->current))
	{
		if ((tmp = ft_use_garbage(line, content)) || tmp == -1)
			return (tmp);
		bool_wrote = 1;
	}
	if ((tmp = ft_get_line(fd, line, content)) != 0)
		return (tmp);
	free(current_lst->content);
	current_lst->content = 0;
	return (bool_wrote);
}
