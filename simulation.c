/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:03:35 by szerisen          #+#    #+#             */
/*   Updated: 2023/05/05 19:03:35 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_start(t_store *store)
{
	int	i;

	if (store->n_philo == 1)
		single_philo(store->philo);
	else
	{
		i = -1;
		while (++i < store->n_philo) 
			pthread_create(&store->philo[i].thd, NULL,
				&routine, (void *)&store->philo[i]); 
		while (store->fnsh_game == false)
			monitor(store);
	}
} 
 
void	*routine(void *val)
{
	t_philo	*plo;
	t_store	*store;

	plo = (t_philo *)val;
	store = plo->args;
	while (store->fnsh_game == false)
	{
		pthread_mutex_lock(&plo->args->checks);
		if (store->meal_limit > 0 && plo->meal_eaten == store->meal_limit)
		{
			pthread_mutex_unlock(&plo->args->checks);
			break ;
		}
		pthread_mutex_unlock(&plo->args->checks);
		p_eats(plo);
		p_sleeps(plo);
		p_thinks(plo);
	}
	return (NULL);
}

void	monitor(t_store *store)
{
	int	death_id;

	death_id = 0;
	while (store->fnsh_game == false) 
	{
		check_life(&store->philo[death_id]);
		meal_limit_check(store);
		usleep(1000);
		if (death_id == store->n_philo - 1)
			death_id = -1;
		death_id++;
	}
}

void	check_life(t_philo *plo)
{
	bool	lock;

	lock = true;
	pthread_mutex_lock(&plo->args->checks);
	if ((timestamp(plo->args) - plo->last_meal) >= plo->args->t_die)
	{
		lock = false;
		pthread_mutex_unlock(&plo->args->checks);
		printer(plo, DIED);
		pthread_mutex_lock(&plo->args->checks);
		plo->args->fnsh_game = true; 
		pthread_mutex_unlock(&plo->args->checks);
	}
	if (lock)
		pthread_mutex_unlock(&plo->args->checks);
}

void	meal_limit_check(t_store *store)
{
	int	meal_nbr;

	meal_nbr = 0;
	if (store->meal_limit > 0)
	{
		while (meal_nbr < store->n_philo)
		{
			pthread_mutex_lock(&store->checks); 
			if (store->philo[meal_nbr].meal_eaten < store->meal_limit)
			{
				pthread_mutex_unlock(&store->checks);
				break ;
			}
			pthread_mutex_unlock(&store->checks);
			meal_nbr++;
		}
		if (meal_nbr == store->n_philo)
		{
			pthread_mutex_lock(&store->checks);
			store->fnsh_game = true;
			pthread_mutex_unlock(&store->checks);
		}
	}
}
