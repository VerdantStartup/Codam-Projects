/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:36:33 by verdant           #+#    #+#             */
/*   Updated: 2022/12/19 11:10:06 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h> // Delete when finished

int	ft_atoi(const char *str);
int	ft_strlen(const char *str);

// Finished main logic but I have have to double check the
// The subject and do some stress-tests
// I also still do not understand the handler I copied from stackoverflow
// I also still have to include libft and prinft
// To do that I need a makefile in the first place