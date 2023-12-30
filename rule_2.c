/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:50:52 by epaksoy           #+#    #+#             */
/*   Updated: 2023/12/29 03:59:01 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack, int print)
{
	rra(stack, 0);
	rrb(stack, 0);
	if (print)
		ft_write("rrr\n");
}

void	ss(t_stack *stack, int print)
{
	sa(stack, 0);
	sb(stack, 0);
	if (print)
		ft_write("ss\n");
}

void	rr(t_stack *stack, int print)
{
	ra(stack, 0);
	rb(stack, 0);
	if (print)
		ft_write("rr\n");
}