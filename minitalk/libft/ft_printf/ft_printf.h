/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:09:38 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/25 13:44:32 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
size_t	ft_strclen(const char *s, char c);
size_t	ft_strlen(char *s);
size_t	ft_putstr_fd(char *s, int fd);
size_t	ft_putnbr(int nb);
size_t	ft_base_toa(unsigned long nb, int base_nb, char *base_str);
size_t	ft_puthex(unsigned int nb, char c);
size_t	ft_putptr(unsigned long nb);
size_t	ft_putuint(unsigned int nb);

#endif