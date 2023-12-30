/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:51:04 by epaksoy           #+#    #+#             */
/*   Updated: 2023/12/29 11:23:24 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *stack, int print)
{
	int	tmp;

	if (stack->size_b < 2)
	{
		// erro
		return ;
	}

	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (print)
		ft_write("sb\n");
}

void	rb(t_stack *stack, int print)
{
	int	tmp;
	int	i;
	int	max;

	i = 0;
	tmp = stack->b[i];
	max = stack->size_b;
	i++;
	while (i < max)
	{
		stack->b[i - 1] = stack->b[i];
		i++;
	}
	stack->b[i - 1] = tmp;
	if (print)
		ft_write("rb\n");
}

void	rrb(t_stack *stack, int print)
{
	int tmp;
	int	max;

	max = stack->size_b - 1;
	tmp = stack->b[max];
	while (max > 0)
	{
		stack->b[max] = stack->b[max - 1];
		max--;
	}
	stack->b[0] = tmp;
	if (print)
		ft_write("rrb\n");
}

void	pb(t_stack *stack, int print)
{
	int	i;

	if (stack->size_a)
	{
		stack->size_b++;
		i = stack->size_b - 1;
		if (i)
		{
			while (i > 0)
			{
				stack->b[i] = stack->b[i - 1];
				i--;
			}
		}
		stack->b[0] = stack->a[0];
		i = 0;
		stack->size_a--;
		while (i < stack->size_a)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		if (print)
			ft_write("pb\n");
	}
	else
	{
		// error
		return ;
	}
}