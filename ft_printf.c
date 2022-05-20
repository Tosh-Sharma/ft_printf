/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:12:16 by tsharma           #+#    #+#             */
/*   Updated: 2022/05/20 18:24:34 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	handle_print(const char *s, va_list args, size_t *i)
{
	*i = *i + 1;
	if (s[0] == 'c')
		return (pf_putchar(va_arg(args, int), 1));
	else if (s[0] == 's')
		return (pf_putstr(va_arg(args, char *), 1));
	else if (s[0] == 'p')
		return (pf_putpointer(va_arg(args, unsigned long)));
	else if (s[0] == 'd' || s[0] == 'i')
		return (pf_putnbr(va_arg(args, int), "0123456789"));
	else if (s[0] == 'u')
		return (pf_putunbr(va_arg(args, unsigned int), "0123456789"));
	else if (s[0] == 'x')
		return (pf_putunbr(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (s[0] == 'X')
		return (pf_putunbr(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (s[0] == '%')
		return (pf_putchar('%', 1));
	else
		return (pf_putchar(s[0], 1));
}

int	handle_spaces(const char *s, va_list args, size_t *i)
{
	int	n;
	int	count;

	count = 0;
	if (s[0] == 'd' || s[0] == 'i')
	{
		n = va_arg(args, int);
		if (n >= 0)
		{
			ft_putchar_fd(' ', 1);
			++count;
		}
		count += pf_putnbr(n, "0123456789");
	}
	i = i + 2;
	return (count);
}

int	analyse_flags(const char *s, va_list args, size_t *i)
{
	if (s[0] == ' ')
		return (handle_spaces(&s[1], args, i));
	else if (s[0] == '+')
		return (handle_spaces(&s[1], args, i));
	else if (s[0] == '#')
		return (handle_spaces(&s[1], args, i));
	else if (s[0] == '-')
		return (handle_spaces(&s[1], args, i));
	else if (s[0] == '0')
		return (handle_spaces(&s[1], args, i));
	else if (s[0] == '.')
		return (handle_spaces(&s[1], args, i));
	else
		return (handle_print(s, args, i));
}

int	ft_printf(const char *s, ...)
{
	size_t		i;
	va_list		args;
	int			count;

	i = 0;
	count = 0;
	va_start(args, s);
	while (i < ft_strlen(s))
	{
		if (s[i] == '%')
			count += analyse_flags(&s[i + 1], args, &i);
		else
			count += pf_putchar(s[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	char	*s1;
// 	int		a;
// 	int		b;
// 	int		c;
// 	int		*d;

// 	a = 25;
// 	s1 = "Hello";
// 	b = ft_printf("My o/p: %s \n", s1);
// 	c = printf("OG o/p: %s\n", s1);
// 	printf("My count: %d\nOG count:%d", b, c);
// }
