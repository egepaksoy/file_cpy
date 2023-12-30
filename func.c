/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:49:18 by epaksoy           #+#    #+#             */
/*   Updated: 2023/12/31 01:14:30 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sorted_a(int *a, int len)
{
	int	tmp;
	int	*list;
	int	i;
	int	j;

	list = malloc(sizeof(int) * len);
	if (!list)
	{
		exit(1);
	}
	i = 0;
	while (i < len)
	{
		list[i] = a[i];
		i++;
	}
	i = 0;
	while (len > i)
	{
		j = 0;
		while (j + 1 < len)
		{
			if (list[j] > list[j + 1])
			{
				tmp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (list);
}

int	pick_pivot(int *a, int len)
{
	int	pvt;
	int	*list;
	int	i;

	list = malloc(sizeof(int) * len);
	if (!list)
	{
		// error
		exit(1);
	}
	i = 0;
	while (i < len)
	{
		list[i] = a[i];
		i++;
	}
	list = sorted_a(list, len);
	pvt = len / 2 + len % 2;
	pvt = list[pvt - 1];
	
	free (list);
	return (pvt);
}

int	get_lil(int *a, int len)
{
	int	lil;
	int	*list;
	int	i;

	list = malloc(sizeof(int) * len);
	if (!list)
	{
		// error
		return (0);
	}
	while (i < len)
	{
		list[i] = a[i];
		i++;
	}
	list = sorted_a(list, len);
	lil = list[0];
	
	free (list);
	return (lil);

}