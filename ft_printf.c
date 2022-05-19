/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:12:16 by tsharma           #+#    #+#             */
/*   Updated: 2022/05/19 16:37:29 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

void	handle_print(const char *s, va_list args, t_snc *item)
{
	if (s[0] == 'c')
		pf_putchar(va_arg(args, int), 1, item);
	else if (s[0] == 's')
		pf_putstr(va_arg(args, char *), 1, item);
	else if (s[0] == 'p')
		pf_putpointer(va_arg(args, unsigned long), item);
	else if (s[0] == 'd' || s[0] == 'i')
		pf_putnbr(va_arg(args, int), 10, "0123456789", item);
	else if (s[0] == 'u')
		pf_putunbr(va_arg(args, unsigned int), 10, "0123456789", item);
	else if (s[0] == 'x')
		pf_putunbr(va_arg(args, unsigned int), 16, "0123456789abcdef", item);
	else if (s[0] == 'X')
		pf_putunbr(va_arg(args, unsigned int), 16, "0123456789ABCDEF", item);
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
	t_snc		item;

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

// int	main(void)
// {
// 	char	*s1;
// 	int		a;
// 	int		b;
// 	int		c;

// 	a = 0;
// 	b = ft_printf("My o/p: %p\n", a);
// 	c = printf("OG o/p: %p\n", a);
// 	printf("My count: %d\nOG count:%d", b, c);
// }
