/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrn <mrn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:22:08 by marida-c          #+#    #+#             */
/*   Updated: 2024/09/25 00:40:45 by mrn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

int	ft_print_hexa(unsigned long nb, char deci);
int	ft_print_usgnint(unsigned int nb);
int	ft_printf(const char *format, ...);
int	ft_print_ptr(long int ptr);
int	ft_print_str(char *str);
int	ft_print_char(char c);
int	ft_print_int(int nb);

#endif
