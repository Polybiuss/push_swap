/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:33:52 by jbergos           #+#    #+#             */
/*   Updated: 2024/10/24 22:18:38 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXA "0123456789abcdef"

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_printf(int c);
int	ft_putstr_printf(char *s);
int	ft_putptr_printf(void *ptr);
int	ft_putint_printf(int n);
int	ft_putuint_printf(int n);
int	ft_putx_printf(int n);
int	ft_putxupper_printf(int n);
int	ft_select(const char format, va_list args);
#endif