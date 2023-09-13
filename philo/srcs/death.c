/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:51:11 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/09/13 21:08:41 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	waitdeath(t_philo *philo)
{
	int	i;

	i = -1;
	usleep((philo->timetodie - 1) * 1000);
	while (getgameover(philo->utils) == 0 && getrotation(philo->utils,
			philo->nbphilo) == 0)
	{
		checkdeath(philo);
		usleep(8000);
	}
	while (++i < philo->nbphilo)
	{
		pthread_join((philo->philo), NULL);
		philo = philo->next;
	}
	return (freephilo(philo, philo->nbphilo));
}

int	checkdeath(t_philo *philo)
{
	int				i;
	int				ret;
	struct timeval	current;

	i = -1;
	ret = -1;
	while (++i < philo->nbphilo && ret == -1)
	{
		gettimeofday(&(current), NULL);
		pthread_mutex_lock(&(philo->block));
		if (timeconvert(philo->time) + philo->timetodie < timeconvert(current))
		{
			pthread_mutex_lock(&(philo->utils->death));
			ret = (philo->num);
			philo->utils->gameover = 1;
			pthread_mutex_unlock(&(philo->utils->death));
		}
		pthread_mutex_unlock(&(philo->block));
		philo = philo->next;
	}
	if (ret != -1)
		print(philo->utils, ret, 0, philo->utils->start);
	return (ret);
}
