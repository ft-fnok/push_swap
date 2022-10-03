/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statistic-helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:15:16 by nlalleik          #+#    #+#             */
/*   Updated: 2022/09/19 19:33:57 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fnd_percentile(t_stack **stack, int percentile)
{
	int		median;
	int		pos;
	int		update_count;
	t_stack	**tmp;

	pos = 0;
	tmp = stack;
	median = get_nbr_value(stack, fnd_smlst_no(*stack));
	update_count = stack_size(*tmp) / ((100 / percentile));
	while (update_count > 1)
	{
		pos = fnd_nxt_smlst_no(*stack, median);
		median = get_nbr_value(stack, pos);
		update_count--;
	}
	return (pos);
}

int	*fnd_percentiles(t_stack **stack, int num, const int update_count)
{
	int		*percentiles;
	int		i;
	int		j;
	int		perc;

	percentiles = ft_calloc((num - 1), sizeof(int *));
	perc = get_nbr_value(stack, fnd_smlst_no(*stack));
	i = 0;
	j = 1;
	while (i < (num - 1))
	{
		while (update_count > j)
		{
			perc = get_nbr_value(stack, fnd_nxt_smlst_no(*stack, perc));
			j++;
		}
		percentiles[i] = perc;
		j = 0;
		i++;
	}
	return (percentiles);
}

int	fnd_lrgst_no_value(t_stack *stack)
{
	t_stack		*tmp;
	int			max;
	int			pos;
	int			cnt;

	tmp = stack;
	pos = 1;
	cnt = 0;
	max = tmp->content;
	while (tmp->next != NULL)
	{
		cnt++;
		tmp = tmp->next;
		if (tmp->content > max)
		{
			max = tmp->content;
			pos += cnt;
			cnt = 0;
		}
	}
	return (max);
}

void	smlst_no_top(t_stack **stack, char id, int index, int prox)
{
	int	smlst_no_pos;

	smlst_no_pos = fnd_smlst_no(*stack);
	if (smlst_no_pos <= prox)
	{
		while (smlst_no_pos > 1)
		{
			rotate(stack, id);
				smlst_no_pos--;
		}
	}
	else if (smlst_no_pos > prox)
	{
		while (smlst_no_pos < index)
		{
			rev_rotate(stack, id);
			smlst_no_pos++;
		}
		rev_rotate(stack, id);
	}
}

void	lrgst_no_top(t_stack **stack, char id, int index, int prox)
{
	int	lrgst_no_pos;

	lrgst_no_pos = fnd_lrgst_no(*stack);
	if (lrgst_no_pos <= prox)
	{
		while (lrgst_no_pos > 1)
		{
			rotate(stack, id);
			lrgst_no_pos--;
		}
	}
	else if (lrgst_no_pos > prox)
	{
		while (lrgst_no_pos < index)
		{
			rev_rotate(stack, id);
			lrgst_no_pos++;
		}
		rev_rotate(stack, id);
	}
}
