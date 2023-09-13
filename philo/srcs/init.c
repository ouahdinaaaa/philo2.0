/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:22:18 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/09/13 21:05:03 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*initialisationphilo(t_utils *utils, int arg5, t_philo *philo,
		char **argv)
{
	t_philo	*tmp;
	int		i;

	i = 0;
	while (++i <= ft_atoi(argv[1]))
	{
		tmp = malloc(sizeof(t_philo));
		if (!tmp)
			return (NULL);
		tmp->nbphilo = ft_atoi(argv[1]);
		tmp->timetodie = ft_atoi(argv[2]);
		tmp->timetoeat = ft_atoi(argv[3]);
		tmp->timetosleep = ft_atoi(argv[4]);
		tmp->num = i;
		tmp->rotation = arg5;
		tmp->next = NULL;
		tmp->utils = utils;
		if (philo != NULL)
			lstlast(philo)->next = tmp;
		else
			philo = tmp;
		if (i != 1 && i == tmp->nbphilo)
			lstlast(philo)->next = philo;
	}
	return (philo);
}

t_philo	*initialisation(t_utils **utils, char **argv, int argc)
{
	int		rot;
	t_philo	*philo;

	rot = -1;
	philo = NULL;
	if (argc == 6)
		rot = ft_atoi(argv[5]);
	(*utils) = calloc(sizeof(t_utils), 1);
	if (!utils)
		return (NULL);
	(*utils)->rotationdone = 0;
	pthread_mutex_init(&(*utils)->death, NULL);
	pthread_mutex_init(&(*utils)->mutexprint, NULL);
	pthread_mutex_init(&(*utils)->mutexrotation, NULL);
	(*utils)->gameover = 0;
	(*utils)->np = ft_atoi(argv[1]);
	if (argc == 6)
		(*utils)->rm = ft_atoi(argv[5]);
	(*utils)->fourchette = malloc(sizeof(pthread_mutex_t) * (ft_atoi(argv[1])));
	if (!(*utils)->fourchette)
		return (NULL);
	philo = initialisationphilo(*utils, rot, philo, argv);
	return (philo);
}

int	freephilo(t_philo *philo, int size)
{
	t_philo	*tmp;
	int		i;

	tmp = NULL;
	i = -1;
	if (philo && philo->utils && philo->utils->fourchette)
		free(philo->utils->fourchette);
	if (philo && philo->utils)
		free(philo->utils);
	while (++i < size)
	{
		tmp = philo->next;
		if (philo)
		{
			free(philo);
			philo = NULL;
		}
		philo = tmp;
	}
	return (0);
}
