/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:46:14 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/09/13 21:10:52 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	int		i;
	t_utils	*utils;
	t_philo	*philo;
	t_philo	*tmp_philo;

	if ((argc != 5 || argc != 6) && !checkargs(argv, argc))
		return (printf("invalid args\n"), 1);
	i = -1;
	philo = initialisation(&utils, argv, argc);
	if (!philo)
		return (printf("error of allocation\n"), 1);
	if (philo->nbphilo == 1)
		return (solo_philo(philo, argc, argv), 1);
	tmp_philo = philo;
	pthread_mutex_lock(&(utils->mutexprint));
	while (++i < philo->nbphilo)
	{
		if (startthread(philo) == -1)
			return (freephilo(philo, philo->nbphilo), 1);
		philo = philo->next;
	}
	return (gettimeofday(&(philo)->utils->start, NULL),
		pthread_mutex_unlock(&(utils->mutexprint)),
		waitdeath(tmp_philo), 1);
}
