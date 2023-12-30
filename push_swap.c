/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:19:41 by epaksoy           #+#    #+#             */
/*   Updated: 2023/12/31 01:17:35 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	repeat_check(int *a, int len)
{
	int	i;
	int	j;
	
	i = 0;
	while (len > i + 1)
	{
		j = i + 1;
		while (len > j)
		{
			if (a[i] == a[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	sorted(int *a, int len)
{
	int	i;
	
	i = 0;
	while (len > i + 1)
	{
		if (a[i] < a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	push_swap(char **argv)
{
	t_stack	stack;
	int		len;
	int		i;

	len = ft_strlen_arr(argv);
	
	stack.a = malloc(sizeof(int) * len);
	if (!stack.a)
		return ;
	stack.b = malloc(sizeof(int) * len);
	if (!stack.b)
	{
		free(stack.a);
		return ;
	}
	stack.size_a = len;
	stack.size_b = 0;

	i = 0;
	while (len > i)
	{
		// TODO: max int error'unu koy
		if (!ft_atoi(argv[i])[1])
			stack.a[i] = ft_atoi(argv[i])[0];
		else
			return (err(&stack, "Invalid Argument"));
		i++;
	}
	if (!repeat_check(stack.a, stack.size_a))
		return (err(&stack, "Tekrar eden sayi var"));
	if (sorted(stack.a, stack.size_a))
		return (err(&stack, "Dizi zaten sirali"));
	sort_stack(&stack);

	free (stack.a);
	free (stack.b);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = ft_split(*argv);
		push_swap(argv);
	}
	return (0);
}