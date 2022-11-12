/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:03:03 by verdant           #+#    #+#             */
/*   Updated: 2022/11/11 21:57:37 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>

int		ft_strclen(char *buf, bool search_newline);
char	*ft_concat(char *s1, char *s2, int s1_len, int size);
char	*ft_substr(char *src, int start, int len);
char	*get_next_line(int fd);
int		check_char(char *buf);

#endif
