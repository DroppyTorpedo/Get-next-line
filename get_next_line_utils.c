/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:08:32 by rnorvene          #+#    #+#             */
/*   Updated: 2024/12/29 18:08:32 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char character)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->character = character;
	lst->next = NULL;
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
	{
		return (NULL);
	}
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

int	get_next_character(t_list *lst)
{
	while (lst && lst->character != '\n')
	{
		lst = lst->next;
	}
	return (lst != NULL);
}

int	get_length(t_list *lst, int i)
{
	if (!lst)
	{
		return (0);
	}
	while (lst)
	{
		i ++;
		if (lst->character == '\n')
		{
			return (i);
		}
		lst = lst->next;
	}
	return (i);
}