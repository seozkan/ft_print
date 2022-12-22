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

#include "ft_printf.h"

int ft_char(int c)
{
    return (write(1,&c,1));
}

int ft_str(char *str)
{
	int i;

	i = 0;
	if (!str)
			return (ft_str("(null)"));
    while (*str)
		i += ft_char(*str++);
    return (i);
}

int ft_len_nbr(unsigned long long int nbr,unsigned long long int base,int mod)
{
	int len;

	len = 0;
	if (mod == 0 && nbr == 0)
		len += 1;
	if (mod == 1 && (int)nbr <= 0)
	{
		nbr = -nbr;
		len += 1;
	}
	while (nbr)
	{
		nbr = nbr / base,
		len++;
	}
	return (len);
}

void ft_nbr(unsigned long long int nbr,unsigned long long int base,char *str,int mod)
{
	if (mod == 1 && (int)nbr < 0)
	{
		nbr *= -1;
		ft_char('-');
	}
	if (nbr >= base)
	{
		ft_nbr(nbr / base,base,str, mod);
		ft_nbr(nbr % base,base,str, mod);
	}
	else
		ft_char(str[nbr]);
}

int ft_hex(unsigned long long int nbr,char format,int base,int mod)
{
	int len;

	len = 0;
	if (format == 'x')
		ft_nbr(nbr,base,"0123456789abcdef" ,0 );
	else if(format == 'X')
		ft_nbr(nbr,base,"0123456789ABCDEF", 0);
	else if(format == 'u')
		ft_nbr(nbr,base,"0123456789", 0);
	else if(format == 'd' || format == 'i')
		ft_nbr(nbr,base,"0123456789",1);
	else if(format == 'p')
	{
		if (!nbr)
			return ft_str("(nil)");
		len += ft_str("0x");
		ft_nbr(nbr,base,"0123456789abcdef",2);
	}
	len += ft_len_nbr(nbr,base,mod);
	return (len);
}

int ft_format(va_list args,char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_char(va_arg(args,int));
	else if (format == 'd' || format == 'i')
		len += ft_hex(va_arg(args,int),format,10,1);
	else if (format == 's')
		len += ft_str(va_arg(args,char *));
	else if (format == 'p')
		len += ft_hex(va_arg(args,unsigned long long int),format,16, 2);
	else if (format == 'u')
		len += ft_hex(va_arg(args,unsigned int),format,10, 0);
	else if (format == 'x' || format == 'X')
		len += ft_hex(va_arg(args,unsigned int),format,16, 0);
	else if (format == '%')
		len += ft_char('%');
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
