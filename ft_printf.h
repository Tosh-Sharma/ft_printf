/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:43:19 by tsharma           #+#    #+#             */
/*   Updated: 2022/05/23 14:42:32 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
int	pf_putchar(char c, int fd);
int	pf_putstr(char *s, int fd);
int	pf_putnbr(int n, char *input);
int	pf_putunbr(unsigned int n, char *input);
int	pf_putpointer(unsigned long l);

int	handle_spaces(const char *s, va_list args, size_t *i);

#endif
