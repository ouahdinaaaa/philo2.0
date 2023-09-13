/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:45:15 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/09/13 19:49:24 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	timeupdate(struct timeval start)
{
	struct timeval	tmp;

	gettimeofday(&(tmp), NULL);
	return (timeconvert(tmp) - timeconvert(start));
}

long int	timeconvert(struct timeval tmp)
{
	return ((tmp.tv_sec * 1000) + (tmp.tv_usec / 1000));
}
