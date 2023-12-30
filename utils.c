/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 03:32:23 by epaksoy           #+#    #+#             */
/*   Updated: 2023/12/30 17:03:47 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(t_stack *stack, char *err_msg)
{
	ft_write(err_msg);
	free(stack->a);
	free(stack->b);
}

int	ft_strlen_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	*ft_atoi(char *str)
{
	int result = 0;
	int sign = 1;
	int	fail = 0;
	int	*ret;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
        	str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if (*str)
		fail = 1;
	ret = malloc(sizeof(int) * 2);
	ret[0] = result * sign;
	ret[1] = fail;
	return (ret);
}

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int i = -1;

	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

char	**ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!out)
		exit(1);
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			if (!out[k])
				exit(1);
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}
	out[k] = NULL;
	return (out);
}

void	ft_write(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}