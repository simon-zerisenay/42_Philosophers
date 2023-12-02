/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:10:40 by szerisen          #+#    #+#             */
/*   Updated: 2023/05/06 19:10:40 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av) 
{
	t_store	*store;

	if (validate_args(ac, av) != 0)
		return (FAILURE);
	store = (t_store *)ft_calloc(1, sizeof(t_store));
	if (!store)
		return (FAILURE);
	if (init_start(av, store))
		return (FAILURE);
	philo_start(store);
	philo_destroy(store);
	return (SUCCESS);
}
