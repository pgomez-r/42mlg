/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:14:47 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/10/12 18:19:41 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	close_threads(t_env *d)
{
	int	i;

	i = -1;
	while (++i < d->num_ph)
		pthread_join(&d->philos->tid[i], NULL);
}

void	ft_destroy_mutex(t_env *d)
{
	int	i;

	i = -1;
	while (++i < d->num_ph)
		pthread_mutex_destroy(&d->fork_mutex[i]);
}

void	ft_free_env(t_env *d)
{
	if (d->philos)
		free (d->philos);
	if (d->forks)
		free (d->forks);
	if (d->fork_mutex)
		free (d->fork_mutex);
}

/*SIN TERMINAR -> Idea: cuando hay error, llamar a esta función, 
pasarle el mensaje a imprimir, la struct general y un código de ejecución
Cod 0 = nada que liberar
Cod 1 = liberar los parámetros de la struct general
Cod 2 = llamar a función para destruir/liberar mutex + struct general*/
void	ft_error(char *msg, int code, t_env *d)
{
	ft_putstr_fd(msg, 2);
	if (code == 0)
		return ;
	if (code == 1)
		ft_free_env(d);
}
