/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:27:21 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/09/13 20:56:44 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_mutex_t	block;
	pthread_t		philo;
	struct s_philo	*next;
	struct timeval	time;
	int				num;
	int				nbphilo;
	int				timetoeat;
	int				timetodie;
	int				timetosleep;
	int				rotation;
	struct s_utils	*utils;
}					t_philo;

typedef struct s_utils
{
	pthread_mutex_t	*fourchette;
	pthread_mutex_t	death;
	pthread_mutex_t	mutexrotation;
	pthread_mutex_t	mutexprint;

	struct timeval	start;
	int				gameover;
	int				rotationdone;
	int				np;
	int				rm;
}					t_utils;

int					checkargs(char **argv, int argc);
int					ft_atoi(const char *str);
int					freephilo(t_philo *philo, int size);
void				print(t_utils *utils, int philo, int etat,
						struct timeval time);
long int			timeupdate(struct timeval start);
long int			timeconvert(struct timeval tmp);
int					startthread(t_philo *philo);
void				*routine(void *param);
int					freephilo(t_philo *philo, int size);
t_philo				*initialisation(t_utils **utils, char **argv, int argc);
t_philo				*initialisationphilo(t_utils *utils, int arg5,
						t_philo *philo, char **argv);
int					getgameover(t_utils *utils);
t_philo				*lstlast(t_philo *lst);
int					getrotation(t_utils *utils, int nbphilo);
int					waitdeath(t_philo *philo);
int					checkdeath(t_philo *philo);
void				philoeat(t_utils *utils, t_philo *philo);
int					solo_philo(t_philo *philo, int argc, char **argv);
void				philoeatlast(t_utils *utils, t_philo *philo);
void				philosleep(t_utils *utils, int time);

#endif
