/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:51:12 by epaksoy           #+#    #+#             */
/*   Updated: 2023/12/29 11:23:23 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack, int print)
{
	int	tmp;

	if (stack->size_a < 2)
	{
		// error
		return ;
	}

	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	if (print)
		ft_write("sa\n");
}

void	ra(t_stack *stack, int print)
{
	int	tmp;
	int	i;
	int	max;

	i = 0;
	tmp = stack->a[i];
	max = stack->size_a;
	i++;
	while (i < max)
	{
		stack->a[i - 1] = stack->a[i];
		i++;
	}
	stack->a[i - 1] = tmp;
	if (print)
		ft_write("ra\n");
}

void	rra(t_stack *stack, int print)
{
	int tmp;
	int	max;

	max = stack->size_a - 1;
	tmp = stack->a[max];
	while (max > 0)
	{
		stack->a[max] = stack->a[max - 1];
		max--;
	}
	stack->a[0] = tmp;
	if (print)
		ft_write("rra\n");
}

void	pa(t_stack *stack, int print)
{
	int	i;

	if (stack->size_b)
	{
		stack->size_a++;
		i = stack->size_a - 1;
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = stack->b[0];
		i = 0;
		stack->size_b--;
		while (i < stack->size_b)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		if (print)
			ft_write("pa\n");
	}
	else
	{
		// error
		return ;
	}
}