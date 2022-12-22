/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:09:38 by mwilsch           #+#    #+#             */
/*   Updated: 2022/12/21 16:13:11 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int			ft_printf(const char *format, ...);
size_t	ft_strclen(const char *s, char c);
size_t	ft_strlen_printf(char const *str); // Exchange this when including libft in makefile for ft_printf as well
size_t	ft_putstr(char *s);
size_t	ft_putnbr(int nb);
size_t	ft_base_toa(unsigned long nb, int base_nb, char *base_str);
size_t	ft_puthex(unsigned int nb, char c);
size_t	ft_putptr(unsigned long nb);
size_t	ft_putuint(unsigned int nb);

#endif