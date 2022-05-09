/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:12:16 by tsharma           #+#    #+#             */
/*   Updated: 2022/05/09 19:44:01 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

int	ft_printf(const char *s, ...)
{
	size_t	i;
	size_t	len;
	va_list	args;

	i = 0;
	len = ft_strlen(s);
	va_start(args, s);
	while (i < len)
	{
		handle_print(s, i, len, args);
		i++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
}
