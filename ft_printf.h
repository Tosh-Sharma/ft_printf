/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:43:19 by tsharma           #+#    #+#             */
/*   Updated: 2022/05/20 18:24:40 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
int	pf_putchar(char c, int fd);
int	pf_putstr(char *s, int fd);
int	pf_putnbr(int n, char *input);
int	pf_putunbr(unsigned int n, char *input);
int	pf_putpointer(unsigned long l);

#endif
