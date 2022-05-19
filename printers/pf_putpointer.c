/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:37:57 by tsharma           #+#    #+#             */
/*   Updated: 2022/05/19 16:36:45 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

void	pf_putpointer(unsigned long l, t_snc *item)
{
	char			res[20];
	unsigned long	i;
	char			*str;

	i = 0;
	if (l == 0)
		res[i++] = '0';
	while (l > 0)
	{
		res[i] = "0123456789abcdef"[l % 16];
		i++;
		l = l / 16;
	}
	res[i] = '\0';
	str = ft_revstr(res);
	item->str = ft_strjoin("0x", str);
	ft_putstr_fd(item->str, 1);
	free(str);
	free(item->str);
	item->count = i + 2;
}
