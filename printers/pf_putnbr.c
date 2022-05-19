/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:08:09 by tsharma           #+#    #+#             */
/*   Updated: 2022/05/19 16:36:45 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

void	handle_neg(t_snc *item, int is_neg, int iterator)
{
	if (is_neg == 1)
	{
		ft_putstr_fd("-", 1);
		iterator++;
	}
	ft_putstr_fd(item->str, 1);
	free(item->str);
	item->count = iterator;
}

void	putnbr_fd(int n, int base, char *input, t_snc *item)
{
	int			iterator;
	char		c[20];
	int			is_neg;

	iterator = 0;
	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		n *= -1;
	}
	while (n > 0)
	{
		c[iterator] = input[n % base];
		n = n / base;
		iterator++;
	}
	c[iterator] = 0;
	item->str = ft_revstr(c);
	handle_neg(item, is_neg, iterator);
}

void	pf_putnbr(int n, int base, char *input, t_snc *item)
{
	if (base == 10 && n == -2147483648)
	{
		item->str = "-2147483648";
		ft_putstr_fd(item->str, 1);
		item->count = 11;
	}
	else if (n == 0)
	{
		ft_putchar_fd(input[0], 1);
		item->str = ft_straddchar("", '0');
		free(item->str);
		item->count = 1;
	}
	else
		putnbr_fd(n, base, input, item);
}
