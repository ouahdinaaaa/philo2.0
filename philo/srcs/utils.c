/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:18:28 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/09/13 21:02:28 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	checkargs(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	if (argc == 6 && (ft_atoi(argv[5]) <= 0 || ft_atoi(argv[4]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[1]) <= 0))
		return (0);
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
		}
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (*(str + i) == '\n' || *(str + i) == '\t' || *(str + i) == '\r'
		|| *(str + i) == '\v' || *(str + i) == '\f' || *(str + i) == ' ')
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
		num = num * 10 + (*(str + i++) - '0');
	return (num * sign);
}

void	print(t_utils *utils, int philo, int etat, struct timeval time)
{
	long int	now;

	pthread_mutex_lock(&(utils->mutexprint));
	now = timeupdate(time);
	if (etat == 0 && getrotation(utils, utils->np) == utils->rm)
	{
		printf("%li %i died", now, philo);
	}
	else if (getgameover(utils) == 0)
	{
		if (etat == 1)
			printf("%ld %i is thinking\n", now, philo);
		else if (etat == 2)
			printf("%ld %i has taken a fork\n", now, philo);
		else if (etat == 3)
			printf("%ld %i is eating\n", now, philo);
		else if (etat == 4)
			printf("%ld %i is sleeping\n", now, philo);
	}
	pthread_mutex_unlock(&(utils->mutexprint));
}

t_philo	*lstlast(t_philo *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
