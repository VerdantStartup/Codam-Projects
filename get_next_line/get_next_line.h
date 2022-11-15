/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:03:03 by verdant           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/14 21:13:03 by mwilsch          ###   ########.fr       */
=======
/*   Updated: 2022/11/12 19:57:25 by verdant          ###   ########.fr       */
>>>>>>> 9f58dd65869f51596c4230793e30757cb0a894e9
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
