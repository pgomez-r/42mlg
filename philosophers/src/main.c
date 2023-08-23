/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:59:47 by pgruz             #+#    #+#             */
/*   Updated: 2023/08/23 17:20:20 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"
/*
void	print_values(t_env *d)
{
	printf("Number of philos: %d\n", d->num_ph);
	printf("Number of forks: %d\n", d->num_fks);
	printf("Time to die: %d\n", d->time_die);
	printf("Time to eat: %d\n", d->time_eat);
	printf("Time to sleep: %d\n", d->time_sleep);
	printf("Number of times to eat: %d\n", d->rounds);
}
*/

void	routine(t_ph *ph)
{
	if (ph->ph_id % 2 != 0)
		usleep(1000);
}

void	gen_philos(t_env *d)
{
	int	i;

	i = -1;
	while (++i < d->num_ph)
	{
		d->philos[i].ph_id = i + 1;
		pthread_create(&d->philos[i].tid, NULL, (void *)routine, &d->philos[i]);
	}
}

int	main(int ac, char **av)
{
	t_env	d;

	if (ac < 5 || ac > 6)
		return (ft_putstr_fd("Wrong number of arguments\n", 2), 1);
	if (!ft_args_digit(av))
		return (ft_putstr_fd("Some/all arguments are not digits\n", 2), 1);
	d = parse_params(av);
	if (d.num_fks < 1 || d.time_die < 1 || d.time_eat < 1 || d.time_sleep < 1)
		return (1);
	gen_philos(&d);
	printf("Valor final:%d\n", d.rounds);
	return (0);
}
