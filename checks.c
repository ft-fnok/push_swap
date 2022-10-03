/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:33:07 by nlalleik          #+#    #+#             */
/*   Updated: 2022/09/19 09:25:20 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_dupe(int count, char **args)
{
	int	c;
	int	d;

	c = 1;
	d = 1;
	while (c < count)
	{
		while (d < c)
		{
			if (ft_strlen(args[d]) == ft_strlen(args[c]))
			{
				if (ft_strncmp(args[d], args[c], ft_strlen(args[c])) == 0)
					return (0);
			}
			d++;
		}
		d = 1;
		c++;
	}
	return (1);
}

int	is_allowed(const char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '+' && s[1] != '\0') || (s[i] == '-' && s[1] != '\0'))
		i++;
	if (ft_isdigit(s[i]))
		i++;
	else
		return (0);
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_int(const char *s)
{
	long long	i;

	i = ft_atol(s);
	if (i < 2147483648 && i > -2147483649)
		return (1);
	return (0);
}

static int	isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r'
		|| c == '\f')
		return (1);
	return (0);
}

long	ft_atol(const char *nptr)
{
	size_t		i;
	int			sign;
	long long	result;

	sign = 1;
	i = 0;
	result = 0;
	while (isspace(nptr[i]) == 1)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) == 1)
	{
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}
