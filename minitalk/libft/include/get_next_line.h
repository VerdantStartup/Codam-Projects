/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:01:38 by mwilsch           #+#    #+#             */
/*   Updated: 2022/11/15 16:01:40 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

int		ft_strclen(char *buf, bool search_newline);
char	*ft_concat(char *s1, char *s2, int s1_len);
char	*ft_substr(char *src, int start, int len);
char	*get_next_line(int fd);
int		check_char(char *buf);

#endif
