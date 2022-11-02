/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:03:03 by verdant           #+#    #+#             */
/*   Updated: 2022/11/01 16:46:34 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	ft_strclen(char *buf, char c);
char *ft_concat(char *s1, char *s2, size_t s1_len, size_t size);
char	*ft_substr(char *src, size_t start, size_t len);

#endif
