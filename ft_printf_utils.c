/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:09:03 by seozkan           #+#    #+#             */
/*   Updated: 2022/12/23 14:09:03 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
		i += ft_putchar(*str++);
	return (i);
}

int	ft_putnbr(unsigned long long nbr, int base, char *str, int *nbr_list)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (nbr)
	{
		nbr_list[i++] = nbr % base;
		nbr = nbr / base;
	}
	while (i--)
		len += ft_putchar(str[nbr_list[i]]);
	return (len);
}

int	ft_nbr(unsigned long long nbr, int base, char *str, int mod)
{
	int	nbr_list[100];
	int	len;

	len = 0;
	if (mod == 1 && (int)nbr < 0)
	{
		nbr *= -1;
		len += ft_putchar('-');
	}
	if (mod == 2)
	{
		if (!nbr)
			return (ft_putstr("(nil)"));
		len += ft_putstr("0x");
	}
	if (nbr == 0)
		len += ft_putchar('0');
	len += ft_putnbr(nbr, base, str, nbr_list);
	return (len);
}

int	ft_format(va_list args, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'u')
		len += ft_nbr(va_arg(args, unsigned int), 10, "0123456789", 0);
	else if (format == 'd' || format == 'i' || format == 'u')
		len += ft_nbr(va_arg(args, int), 10, "0123456789", 1);
	else if (format == 'p')
		len += ft_nbr(va_arg(args, unsigned long long), 16, "0123456789abcdef",
				2);
	else if (format == 'x')
		len += ft_nbr(va_arg(args, unsigned int), 16, "0123456789abcdef", 0);
	else if (format == 'X')
		len += ft_nbr(va_arg(args, unsigned int), 16, "0123456789ABCDEF", 0);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}
