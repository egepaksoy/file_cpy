/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:37:15 by epaksoy           #+#    #+#             */
/*   Updated: 2023/12/31 01:16:37 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_biggest_to_top(t_stack *stack)
{
	int	big;
	int	i;

	big = sorted_a(stack->b, stack->size_b)[stack->size_b - 1];
	if (big != stack->b[0])
	{
		i = 0;
		while (big != stack->b[i])
			i++;
		if (i < stack->size_b / 2)
		{
			while (stack->b[0] != big)
			{
				rb(stack, 1);
				i++;
			}
		}
		else
		{
			while (stack->b[0] != big)
			{
				rrb(stack, 1);
				i++;
			}
		}
	}
	pa(stack, 1);
}

void	sort_b(t_stack *stack)
{
	int	lil;
	int	first_nbr;

	lil = sorted_a(stack->b, stack->size_b)[stack->size_b - 1];
	if (lil == stack->b[0])
	{
		pa(stack, 1);
		return ;
	}
	first_nbr = stack->b[0];
	while (stack->b[0] != lil)
		pa(stack, 1);
	pa(stack, 1);
	ra(stack, 1);
	while (stack->a[0] != first_nbr)
		pb(stack, 1);
	pb(stack, 1);
	rra(stack, 1);
}

void	sort_all(t_stack *stack)
{
	int	pivot;
	int	*first_ra;

	first_ra = malloc(sizeof(int) * 2);
	if (!first_ra)
		err(stack, "Variable error");
	first_ra[1] = 1;
	pivot = pick_pivot(stack->a, stack->size_a);
	while (1)
	{
		if (stack->size_a <= 3)
		{
			lil_sort(stack);
			return ;
		}
		if (stack->a[0] <= pivot)
			pb(stack, 1);
		else if (stack->a[0] > pivot)
		{
			ra(stack, 1);
			if (first_ra[1])
			{
				first_ra[0] = stack->a[0];
				first_ra[1] = 0;
			}
		}
		if (first_ra[0] == stack->a[0])
			break;
	}
	sort_all(stack);
}

void	lil_sort(t_stack *stack)
{
	if (stack->size_a == 2 && (stack->a[0] > stack->a[1]))
	{
		sa(stack, 1);
	}
	else if (stack->size_a == 3)
		sort_three(stack);
}

void	sort_three(t_stack *stack)
{
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] && stack->a[2] > stack->a[0])
	{
		rra(stack, 1);
		sa(stack, 1);
	}
	else if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2] && stack->a[1] < stack->a[2])
		ra(stack, 1);
	else if (stack->a[0] > stack->a[1] && stack->a[0] < stack->a[2] && stack->a[1] < stack->a[2])
		sa(stack, 1);
	else if (stack->a[0] < stack->a[1] && stack->a[0] > stack->a[2] && stack->a[1] > stack->a[2])
		rra(stack, 1);
	else if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2] && stack->a[1] > stack->a[2])
	{
		ra(stack, 1);
		sa(stack, 1);
	}
}

void	sort_stack(t_stack *stack)
{
	if (stack->size_a == 2)
		sa(stack, 1);
	else if (stack->size_a == 3)
		sort_three(stack);
	else if (stack->size_a > 3)
	{
		sort_all(stack);
		while (stack->size_b)
			get_biggest_to_top(stack);
	}
}