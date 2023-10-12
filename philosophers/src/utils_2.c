/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:09:05 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/10/12 19:55:39 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

/*Recoge el tiempo actual en milisegundos*/
time_t	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (time_t)1000) + (tv.tv_usec / 1000));
}

/*Mejora de usleep para que sea más fiable*/
int	ft_usleep(useconds_t time)
{
	time_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

void	ft_log(t_ph *ph, char *msg, char *color)
{
	time_t	time;

	pthread_mutex_lock(&ph->d->print);
	time = ft_get_time() - ph->d->start_time;
	printf("%s[%ld]--philo[%d]--%s\n\033[0m", color, time, ph->num, msg);
	pthread_mutex_unlock(&ph->d->print);
}

int	check_ko(t_env *d, t_ph *ph)
{
	useconds_t	time;

	time = ft_get_time();
	if ((time - ph->fed_time) >= d->time_die)
	{
		ph->ko = 1;
		ft_log(ph, "had died.", RED);
		return (1);
	}
	return (0);
}
