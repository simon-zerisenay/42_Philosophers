/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:23:11 by szerisen          #+#    #+#             */
/*   Updated: 2023/05/05 15:23:11 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*single_philo(void *p)
{ 
	t_philo	*plo;   
 
	plo = (t_philo *)p; 
	pthread_mutex_lock(&plo->args->fork[plo->left_f]);
	printer(plo, GFORK);
	ft_sleeper(plo, plo->args->t_die); 
	pthread_mutex_unlock(&plo->args->fork[plo->left_f]);
	printer(plo, DIED);
	pthread_mutex_lock(&plo->args->checks);
	plo->args->fnsh_game = true;
	pthread_mutex_unlock(&plo->args->checks);
	return (NULL);
}

void	grab_fork(t_philo *plo)
{
	if (plo->id_num % 2)
	{
		usleep(1500);
		pthread_mutex_lock(&plo->args->fork[plo->left_f]);
		pthread_mutex_lock(&plo->args->fork[plo->right_f]);
		printeright_f(plo);
	}
	else
	{
		pthread_mutex_lock(&plo->args->fork[plo->right_f]);
		pthread_mutex_lock(&plo->args->fork[plo->left_f]);
		printeright_f(plo);
	}
}

void	p_eats(t_philo *plo)
{
	bool	lock;

	lock = true;
	pthread_mutex_lock(&plo->args->checks);
	if (plo->args->fnsh_game == false)
	{
		lock = false;
		pthread_mutex_unlock(&plo->args->checks);
		grab_fork(plo);
		printer(plo, EATING);
		pthread_mutex_lock(&plo->args->checks);
		plo->last_meal = timestamp(plo->args);
		plo->meal_eaten++;
		pthread_mutex_unlock(&plo->args->checks);
		ft_sleeper(plo, plo->args->t_eat);
		pthread_mutex_unlock(&plo->args->fork[plo->left_f]);
		pthread_mutex_unlock(&plo->args->fork[plo->right_f]);
	}
	if (lock)
		pthread_mutex_unlock(&plo->args->checks);
}

void	p_thinks(t_philo *plo)
{
	if (plo->args->fnsh_game == false)
		printer(plo, THINKING);
}

void	p_sleeps(t_philo *plo)
{
	if (plo->args->fnsh_game == false)
	{
		printer(plo, SLEEPING);
		ft_sleeper(plo, plo->args->t_sleep);
	}
}
