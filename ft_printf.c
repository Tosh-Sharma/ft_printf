/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:12:16 by tsharma           #+#    #+#             */
/*   Updated: 2022/05/18 19:20:12 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

void	ft_print_p_fd(unsigned long l, int fd)
{
	char	res[20];
	size_t	i;

	i = 0;
	while (l > 0)
	{
		res[i] = "0123456789abcdef"[l % 16];
		i++;
		l = l / 16;
	}
	res[i] = '\0';
	ft_putstr_fd(ft_strjoin("0x", ft_revstr(res)), fd);
}

void	handle_print(const char *s, va_list args, type_snc *item)
{
	if (s[0] == 'c')
		pf_putchar(va_arg(args, int), 1, item);
	else if (s[0] == 's')
		pf_putstr(va_arg(args, char *), 1, item);
	// else if (s[0] == 'p')
	// 	item = ft_print_p_fd(va_arg(args, unsigned long), 1);
	else if (s[0] == 'd' || s[0] == 'i')
		pf_putnbr(va_arg(args, int), 10, "0123456789", item);
	// else if (s[0] == 'u')
	// 	item = ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (s[0] == 'x')
		pf_putnbr(va_arg(args, int), 16, "0123456789abcdef", item);
	else if (s[0] == 'X')
		pf_putnbr(va_arg(args, int), 16, "0123456789ABCDEF", item);
	else if (s[0] == '%')
		pf_putchar('%', 1, item);
	else
		pf_putchar(s[0], 1, item);
}

int	ft_printf(const char *s, ...)
{
	size_t		i;
	va_list		args;
	int			count;
	type_snc	item;

	i = 0;
	count = 0;
	va_start(args, s);
	while (i < ft_strlen(s))
	{
		if (s[i] == '%')
		{
			handle_print(&s[i + 1], args, &item);
			i++;
			count += item.count;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	char	c;
	char	*s1;
	// int		*a;
	int		b;

	c = 'f';
	b = 235;
	// a = &b;
	s1 = ft_strdup("World");
	// b = printf("%cHello", c);
	// printf("Printf returns %d", b);
	// ft_printf("Hello %s %u %p %d %i %x %X %%", s1, c, b, 123, 123, 123, 123);
	// ft_printf("Hello %s %d %i %x %X %%", s1, -123, 0, 125, 126);
	b = ft_printf("%x %x", -9, 99);
	printf("%x %x", -9, 99);
	ft_printf("\n%d", b);
}
