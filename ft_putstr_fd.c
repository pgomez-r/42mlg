/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:34:16 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/10 09:53:51 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write (fd, s, ft_strlen(s));
}

/*hacemos igual que con putchar_fd, usando write con fd para el input 
(primer parametro de write), s para la cadena a imprimir (segundo parametro),
y ft_strlen nos dará el número de bytes que debe mostrar en pantalla write,
que serán igual a la longitud de la cadena*/