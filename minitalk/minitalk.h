/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:36:33 by verdant           #+#    #+#             */
/*   Updated: 2022/12/20 12:58:57 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h> // Delete when finished

int	ft_atoi(const char *str); // I can delete this as soon as my makefile compiles my libft as well
int	ft_strlen(const char *str); // I can delete this as soon as my makefile compiles my libft as well

// I need to fix my Makefile double main issue
// I need my Makefile from libft to compile printf as well
