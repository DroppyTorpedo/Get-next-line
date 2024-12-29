/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:08:16 by rnorvene          #+#    #+#             */
/*   Updated: 2024/12/29 18:08:16 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*lst;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	complete_list(&lst, ft_lstlast(lst), fd);
	return (l_to_p(&lst));
}

void	complete_list(t_list **lst, t_list *last, int fd)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_lus;
	int		i;

	while (!get_next_character(*lst))
	{
		bytes_lus = read(fd, buffer, BUFFER_SIZE);
		if (bytes_lus <= 0)
			break ;
		i = 0;
		if (!*lst)
			*lst = ft_lstnew(buffer[i++]);
		if (!last)
			last = *lst;
		while (i < bytes_lus)
		{
			last->next = ft_lstnew(buffer[i]);
			last = last->next;
			i++;
		}
	}
	if (bytes_lus == -1)
		empty_list(lst);
}

void	empty_list(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

char	*l_to_p(t_list **lst)
{
	char	*line;
	t_list	*tmp;
	int		len;
	int		i;

	if (*lst == NULL)
		return (NULL);
	len = get_length(*lst, 0);
	line = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		line[i] = (*lst)->character;
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
		i++;
	}
	line[len] = '\0';
	return (line);
}