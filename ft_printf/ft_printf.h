/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:57:58 by yseddouk          #+#    #+#             */
/*   Updated: 2025/01/10 14:04:31 by yseddouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putchar_pf(int c, size_t *counter);
void	ft_putstr_pf(char *str, size_t *counter);
void	ft_putptr_pf(void *ptr, size_t *counter);
void	ft_putnbr_pf(int num, size_t *counter);
void	ft_puthex_pf(unsigned long num, size_t *counter, char *base);
void	ft_putuint_pf(unsigned int num, size_t *counter);

#endif
