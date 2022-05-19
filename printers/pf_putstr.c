/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:05:52 by tsharma           #+#    #+#             */
/*   Updated: 2022/05/19 16:36:45 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

void	pf_putstr(char *s, int fd, t_snc *item)
{
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		item->count = 6;
		return ;
	}
	item->count = ft_strlen(s);
	item->str = s;
	ft_putstr_fd(s, fd);
}
