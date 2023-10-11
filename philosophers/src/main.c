/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:59:47 by pgruz             #+#    #+#             */
/*   Updated: 2023/10/11 22:28:51 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	ft_monitor(t_env *d)
{
	int	i;
	int	finished;

	i = -1;
	finished = 0;
	while (++i < d->num_ph)
	{
		if (d->philos[i].ko == 1)
		{	
			d->finish = 1;
			return ;
		}
		if (d->philos[i].round == d->rounds)
			finished++;
	}
	if (finished == d->rounds)
		d->finish = 2;
}

void	*routine(void *param)
{
	t_ph	*ph;

	ph = (t_ph *)param;
	ph->fed_time = ft_get_time();
	if (ph->num % 2 != 0)
		ft_usleep(10);
	while (ph->d->finish == 0)
	{		
		pick_forks(ph);
		philo_eat(ph);
		drop_forks(ph);
		philo_sleep(ph);
		ft_log(ph, "is thinking.");
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_env	d;

	if (ac < 5 || ac > 6)
		return (ft_error("Wrong number of arguments\n", 0, &d), 1);
	if (!ft_args_digit(av))
		return (ft_error("Some/all arguments are not digits\n", 0, &d), 1);
	d = parse_params(av);
	if (d.num_ph < 1 || d.time_die < 1 || d.time_eat < 1 || d.time_sleep < 1)
		return (ft_error("Negative or zero values\n", 0, &d), 1);
	gen_philos(&d);
	while (d.finish == 0)
		ft_monitor(&d);
	close_threads(&d);
	ft_destroy_mutex(&d);
	ft_free_env(&d);
	return (0);
}

/*Añadir, después de lanzar los hilos, una función monitoring*/