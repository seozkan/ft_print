/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:42:35 by seozkan           #+#    #+#             */
/*   Updated: 2022/12/19 14:59:20 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_length += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_printpercent();
	return (print_length);
} */


#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_char(int c)
{
    write(1,&c,1);
    return (1);
}

int ft_str(char *str)
{
	int i;

	i = 0;
	if (!*str)
		ft_str("(null)");
    while (*str)
		i += ft_char(*str++);
    return (i);
}

int ft_pointer(unsigned long long ptr)
{
	static int len;
	
	if (ptr >= 16)
	{
		ft_pointer(ptr / 16);
		ft_pointer(ptr % 16);
	}
	else
		len += ft_char("0123456789abcdef"[ptr]);
	return (len);
}

int ft_format(va_list args,char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_char(va_arg(args,int));
	else if (format == 'd' || format == 'i')
		//integer yaz
		printf("integer yaz");
	else if (format == 's')
		len += ft_str(va_arg(args,char *));
	else if (format == 'p')
	{
		len += ft_char('0');
		len += ft_char('x');
		len += ft_pointer(va_arg(args,unsigned long long));
	}
	else if (format == 'u')
		//unsigned int
		printf("unsigned yaz");
	else if (format == 'x')
		//küçük harf hexadecimal
		printf("hex yaz");
	else if (format == 'X')
		//büyük harf hexadecimal
		printf("HEX yaz");
	else if (format == '%')
		//% işareti yazdır
		printf("yüzde yaz");
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += ft_format(args,*str);
		}
		else
			len += ft_char(*str);
		str++;
	}
	va_end(args);
	return (len);
}

int main(void)
{
	unsigned long long a;

	a = 5;

	printf("%d\n",printf("%p\n",&a));
	printf("%d\n",ft_printf("%p\n",&a));
}
