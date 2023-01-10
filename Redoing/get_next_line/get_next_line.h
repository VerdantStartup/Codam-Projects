/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:20:13 by Verdant           #+#    #+#             */
/*   Updated: 2023/01/10 16:01:51 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// BUFFERSIZE = 1kb

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> // delete this when finished
# include <stdio.h> // delete this when finished
# include <string.h> // delete this when finished


/*			Utills			*/
int		ft_strclen(char *s, char c);
int		search_char(char *buffer, char c);

/*			Main			*/

char	*join_buffers(char *buf1, char *buf2);
char	*read_file(char *buffer, int fd);
char	*modify(char buffer[], char *line);
char	*get_next_line(int fd);

#endif
