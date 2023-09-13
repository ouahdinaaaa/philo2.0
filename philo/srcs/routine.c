/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:51:45 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/09/13 21:00:43 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	startthread(t_philo *philo)
{
	int	ret;

	pthread_mutex_init(&(philo)->block, NULL);
	pthread_mutex_init(&(philo)->utils->fourchette[philo->num - 1], NULL);
	gettimeofday(&(philo->time), NULL);
	ret = pthread_create(&(philo->philo), NULL, routine, (void *)philo);
	return (ret);
}

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	pthread_mutex_lock(&(philo->utils->mutexprint));
	pthread_mutex_unlock(&(philo->utils->mutexprint));
	if (philo->num % 2 == 0)
		usleep((philo->timetoeat / 2) * 1000);
	while (philo->rotation != 0 && getgameover(philo->utils) == 0)
	{
		if (philo->num == philo->nbphilo)
			philoeatlast(philo->utils, philo);
		else
			philoeat(philo->utils, philo);
		if (philo->rotation == 0)
		{
			pthread_mutex_lock(&(philo->utils->mutexrotation));
			philo->utils->rotationdone++;
			pthread_mutex_unlock(&(philo->utils->mutexrotation));
		}
		if (philo->rotation != 0)
			print(philo->utils, philo->num, 1, philo->utils->start);
	}
	return (NULL);
}
