/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 08:07:36 by iabkadri          #+#    #+#             */
/*   Updated: 2022/11/01 08:07:37 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_fprintf(int fd, const char *format, ...);
void	ft_handle(int fd, char spc, va_list ap);
void	ft_putchar(int fd, char c);
void	ft_putstr(int fd, char *s);
void	ft_putnbr(int fd, long nbr);

#endif
