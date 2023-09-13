/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:47:29 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/09/13 21:21:53 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	solo_philo(t_philo *philo, int argc, char **argv)
{
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		return (freephilo(philo, philo->nbphilo), 1);
	printf("0 1 has taken a fork\n");
	usleep(philo->timetodie * 1000);
	printf("%i 1 died\n", philo->timetodie);
	return (freephilo(philo, philo->nbphilo), 1);
}

void	philoeat(t_utils *utils, t_philo *philo)
{
	pthread_mutex_lock(&(utils->fourchette[philo->num - 1]));
	print(utils, philo->num, 2, philo->utils->start);
	pthread_mutex_lock(&(utils->fourchette[philo->num]));
	print(utils, philo->num, 2, philo->utils->start);
	print(utils, philo->num, 3, philo->utils->start);
	pthread_mutex_lock(&(philo->block));
	gettimeofday(&(philo->time), NULL);
	pthread_mutex_unlock(&(philo->block));
	philosleep(utils, philo->timetoeat);
	philo->rotation = philo->rotation - 1;
	pthread_mutex_unlock(&(utils->fourchette[philo->num - 1]));
	pthread_mutex_unlock(&(utils->fourchette[philo->num]));
	if (philo->rotation != 0)
	{
		print(utils, philo->num, 4, philo->utils->start);
		philosleep(utils, philo->timetosleep);
	}
}

void	philoeatlast(t_utils *utils, t_philo *philo)
{
	pthread_mutex_lock(&(utils->fourchette[0]));
	print(utils, philo->num, 2, philo->utils->start);
	pthread_mutex_lock(&(utils->fourchette[philo->num - 1]));
	print(utils, philo->num, 2, philo->utils->start);
	print(utils, philo->num, 3, philo->utils->start);
	pthread_mutex_lock(&(philo->block));
	gettimeofday(&(philo->time), NULL);
	pthread_mutex_unlock(&(philo->block));
	philosleep(utils, philo->timetoeat);
	philo->rotation--;
	pthread_mutex_unlock(&(utils->fourchette[0]));
	pthread_mutex_unlock(&(utils->fourchette[philo->num - 1]));
	if (philo->rotation != 0)
	{
		print(utils, philo->num, 4, philo->utils->start);
		philosleep(utils, philo->timetosleep);
	}
}

void	philosleep(t_utils *utils, int time)
{
	struct timeval	start;
	struct timeval	current;
	int				i;

	i = 0;
	gettimeofday(&(current), NULL);
	gettimeofday(&(start), NULL);
	while (++i && timeconvert(start) + time > timeconvert(current))
	{
		usleep(200);
		gettimeofday(&(current), NULL);
		if (i % 20 == 0 && getgameover(utils) == 1)
			break ;
	}
}
