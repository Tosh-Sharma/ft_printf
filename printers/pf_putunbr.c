/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:16:01 by tsharma           #+#    #+#             */
/*   Updated: 2022/05/19 16:36:45 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

void	putunbr(unsigned int n, unsigned int base, char *input, t_snc *item)
{
	int			iterator;
	char		c[20];

	iterator = 0;
	while (n > 0)
	{
		c[iterator] = input[n % base];
		n = n / base;
		iterator++;
	}
	c[iterator] = 0;
	item->str = ft_revstr(c);
	ft_putstr_fd(item->str, 1);
	free(item->str);
	item->count = iterator;
}

void	pf_putunbr(unsigned int n, int base, char *input, t_snc *item)
{
	if (n == 0)
	{
		ft_putchar_fd(input[0], 1);
		item->str = ft_straddchar("", '0');
		free(item->str);
		item->count = 1;
	}
	else
		putunbr(n, base, input, item);
}
