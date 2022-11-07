/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:03:03 by verdant           #+#    #+#             */
/*   Updated: 2022/11/04 12:49:07 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	ft_strclen(char *buf, char c);
char *ft_concat(char *s1, char *s2, size_t s1_len, size_t size);
char	*ft_substr(char *src, size_t start, size_t len);
void	ft_bzero(void *s, size_t n);
char	*get_next_line(int fd);

#endif
