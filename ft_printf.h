/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:43:19 by tsharma           #+#    #+#             */
/*   Updated: 2022/05/19 16:36:45 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_string_and_count
{
	int		count;
	char	*str;
}	t_snc;

int		ft_printf(const char *s, ...);
void	pf_putchar(char c, int fd, t_snc *item);
void	pf_putstr(char *s, int fd, t_snc *item);
void	pf_putnbr(int n, int base, char *input, t_snc *item);
void	pf_putunbr(unsigned int n, int base, char *input, t_snc *item);
void	pf_putpointer(unsigned long l, t_snc *item);

#endif
