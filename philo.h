/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 01:03:45 by szerisen          #+#    #+#             */
/*   Updated: 2023/05/07 01:03:45 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H 

/*------------------------------ LIBRARIES ------------------------------*/

# include <pthread.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h> 

/*------------------------------ RETURN VALUES ------------------------------*/

# define SUCCESS		0
# define FAILURE		-42

/*------------------------ PRINT TO STDOUT -------------------------*/

# define ERROR1			"\033[1;31m Invalid Argument Detected \033[0m"
# define ERROR2			"\033[1;31m The program expects 4-5 Numeric Args: \033[0m"
# define ERROR3			"Ex: ./philo [num of philo] [time 2 die] [time 2 eat]"
# define GFORK			"🍽️ \e[0;32m grabbed a fork \033[0m"
# define DIED			"💀 \033[1;31m died \033[0m"
# define EATING			"🍝 \e[0;34m is eating \033[0m"
# define THINKING		"🤔 \e[0;33m is thinking \033[0m"
# define SLEEPING		"🛌 \e[0;36m is sleeping \033[0m" 

/*---------------------------- STRUCTURES ----------------------------*/

typedef struct s_philo	t_philo;
typedef struct s_store	t_store;

typedef struct s_philo
{
	int				meal_eaten;
	int				id_num;
	pthread_t		thd;
	long long		last_meal;
	int				right_f;
	int				left_f;
	t_store			*args;
}	t_philo;

typedef struct s_store
{
	int				error;
	bool			fnsh_game;
	int				end_meal;
	long long		t_start;
	long long		t_eat;
	long long		t_die;
	long long		t_sleep;
	int				n_philo;
	int				meal_limit;
	t_philo			*philo;
	pthread_mutex_t	checks;
	pthread_mutex_t	*fork;
}	t_store;

/*--------------------------- FUNCTIONS ---------------------------*/

int			check_digit(char **str);
int			ft_atoi(const char *str);
int			validate_args(int ac, char **av);
int			ft_atoi(const char *str);
int			check_overflow(t_store *store, char **av);
long long	timestart(void);
long long	timestamp(t_store *store);
int			init_start(char **av, t_store *store);
void		*ft_calloc(size_t count, size_t size);
void		init_philos(t_store *store);
void		philo_start(t_store *store);
void		*routine(void *val);
void		*single_philo(void *p);
void		printer(t_philo *plo, char *str);
void		ft_sleeper(t_philo *plo, int t_2_wait);
void		philo_destroy(t_store *store);
void		monitor(t_store *store);
void		p_eats(t_philo *plo);
void		p_thinks(t_philo *plo);
void		p_sleeps(t_philo *plo);
void		check_life(t_philo *plo);
void		grab_fork(t_philo *plo);
void		meal_limit_check(t_store *store);
void		printeright_f(t_philo *plo);

#endif
