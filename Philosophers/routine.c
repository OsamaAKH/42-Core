/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:22:44 by okhan             #+#    #+#             */
/*   Updated: 2026/02/07 13:23:13 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	if (philo->data->num_philos == 1)
	{
		ft_usleep(philo->data->time_to_die, philo->data);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->meal_lock);
	ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1500);
	while (1)
	{
		pthread_mutex_lock(&philo->data->dead_lock);
		if (philo->data->dead_flag)
		{
			pthread_mutex_unlock(&philo->data->dead_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->data->dead_lock);
		eat_routine(philo);
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep, philo->data);
		print_status(philo, "is thinking");
	}
	return (NULL);
}

static int	is_dead(t_data *data, int i)
{
	pthread_mutex_lock(&data->meal_lock);
	if (get_time() - data->philos[i].last_meal_time >= data->time_to_die)
	{
		pthread_mutex_unlock(&data->meal_lock);
		print_status(&data->philos[i], "died");
		set_dead_flag(data);
		return (1);
	}
	pthread_mutex_unlock(&data->meal_lock);
	return (0);
}

static int	check_all_fed(t_data *data)
{
	int	i;
	int	finished;

	i = 0;
	finished = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->meal_lock);
		if (data->must_eat_count != -1
			&& data->philos[i].meals_eaten >= data->must_eat_count)
			finished++;
		pthread_mutex_unlock(&data->meal_lock);
		i++;
	}
	if (data->must_eat_count != -1 && finished == data->num_philos)
	{
		set_dead_flag(data);
		return (1);
	}
	return (0);
}

void	monitor_philos(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->num_philos)
		{
			if (is_dead(data, i))
				return ;
			i++;
		}
		if (check_all_fed(data))
			return ;
		usleep(1000);
	}
}
