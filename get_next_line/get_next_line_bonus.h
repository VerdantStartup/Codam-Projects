/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:07:29 by mwilsch           #+#    #+#             */
/*   Updated: 2022/11/14 21:03:24 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
// #include <stdio.h>
// #include <fcntl.h>

int		ft_strclen(char *buf, bool search_newline);
char	*ft_concat(char *s1, char *s2, int s1_len);
char	*ft_substr(char *src, int start, int len);
char	*get_next_line(int fd);
int		check_char(char *buf);
void	ft_bzero(void *s, size_t n);

#endif
