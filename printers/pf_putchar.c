/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:45:47 by tsharma           #+#    #+#             */
/*   Updated: 2022/05/18 18:19:05 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

void	pf_putchar(char c, int fd, type_snc *item)
{
	char		str[2];

	str[0] = c;
	str[1] = '\0';
	item->count = 1;
	item->str = str;
	ft_putchar_fd(c, fd);
}
