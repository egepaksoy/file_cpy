/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:18:33 by epaksoy           #+#    #+#             */
/*   Updated: 2023/12/30 17:47:32 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
// REMOVE BEFORE FLIGHT
#include <stdio.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}				t_stack;

int		sorted(int *a, int len);
// func
int		pick_pivot(int *a, int len);
int		get_lil(int *a, int len);
int		*sorted_a(int *a, int len);
// sort
void	sort_stack(t_stack *stack);
void	sort_three(t_stack *stack);
void	lil_sort(t_stack *stack);
void	sort_all(t_stack *stack);
void	merge_all(t_stack *stack);
// utils
void	err(t_stack *stack, char *err_msg);
void	ft_write(char *str);
char	**ft_split(char *str);
int		*ft_atoi(char *str);
int		ft_strlen_arr(char **str);
// rules_a
void	sa(t_stack *stack, int print);
void	ra(t_stack *stack, int print);
void	rra(t_stack *stack, int print);
void	pa(t_stack *stack, int print);
// rules_b
void	sb(t_stack *stack, int print);
void	rb(t_stack *stack, int print);
void	rrb(t_stack *stack, int print);
void	pb(t_stack *stack, int print);
// rules_2
void	ss(t_stack *stack, int print);
void	rr(t_stack *stack, int print);
void	rrr(t_stack *stack, int print);

#endif