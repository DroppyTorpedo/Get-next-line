/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:08:55 by rnorvene          #+#    #+#             */
/*   Updated: 2024/12/29 18:08:55 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	char		character;
	struct	s_list	*next;
}				t_list;

t_list		*ft_lstnew(char character);
char		*get_next_line(int fd);
char		*l_to_p(t_list **lst);
void		complete_list(t_list **lst, t_list *last, int fd);
int				get_next_character(t_list *lst);
int				get_length(t_list *lst, int i);
t_list		*ft_lstlast(t_list *lst);
void		empty_list(t_list **lst);

#endif