/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:24:37 by seozkan           #+#    #+#             */
/*   Updated: 2022/12/20 21:24:37 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(unsigned long long nbr, int base, char *str, int *nbr_list);
int	ft_nbr(unsigned long long nbr, int base, char *str, int mod);
int	ft_format(va_list args, char format);
int	ft_printf(const char *str, ...);
#endif