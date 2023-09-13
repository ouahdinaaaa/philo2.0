/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:40:24 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/09/13 19:44:48 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	getgameover(t_utils *utils)
{
	int	nb;

	nb = 0;
	pthread_mutex_lock(&(utils->death));
	if (utils->gameover == 1)
		nb = 1;
	pthread_mutex_unlock(&(utils->death));
	return (nb);
}

int	getrotation(t_utils *utils, int nbphilo)
{
	int	nb;

	nb = 0;
	pthread_mutex_lock(&(utils->mutexrotation));
	if (utils->rotationdone == nbphilo)
		nb = 1;
	pthread_mutex_unlock(&(utils->mutexrotation));
	return (nb);
}
