/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:58:23 by nlalleik          #+#    #+#             */
/*   Updated: 2022/10/03 10:01:11 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	logic(t_stack **stack_a, t_stack **stack_b)
{
	int		index;

	index = stack_size(*stack_a);
	if (index == 3)
		micro_stack(stack_a);
	else if (index <= 10)
		small_stack_logic(stack_a, stack_b, index);
	else if (index <= 100)
		medium_stack_logic(stack_a, stack_b, index);
	else
		large_stack_logic(stack_a, stack_b, index);
}

void	small_stack_logic(t_stack **stack_a, t_stack **stack_b, int index)
{
	int	i;
	int	smlst_no_pos;

	i = index;
	while (index > 1)
	{
		smlst_no_pos = fnd_smlst_no(*stack_a);
		if (smlst_no_pos == 1 && index > 2)
			push(stack_a, stack_b, 'b');
		else if (smlst_no_pos == 1 && index == 2)
			break ;
		else
		{
			smlst_no_top(stack_a, 'a', index, (index / 2) + 1);
			if (index > 2)
				push(stack_a, stack_b, 'b');
		}
		index = stack_size(*stack_a);
	}
	while (stack_size(*stack_b) && (i-- > 2))
		push(stack_b, stack_a, 'a');
}

void	medium_stack_logic(t_stack **stack_a, t_stack **stack_b, const int len)
{
	int	index;
	int	*percentiles;
	int	i;

	i = 1;
	index = stack_size(*stack_a);
	percentiles = fnd_percentiles(stack_a, 4, (const int)(index / 4));
	while (i < 4)
	{
		while (get_nbr_value(stack_a, fnd_smlst_no(*stack_a)) < \
		percentiles[i - 1] && stack_size(*stack_b) <= ((len / 4) * i))
			smlst_no_top_sort(stack_a, stack_b, 'a', percentiles[(i - 1)]);
		index = stack_size(*stack_a);
		i++;
	}
	small_stack_logic(stack_a, stack_b, index);
	sort_rev_logic(stack_b, stack_a);
	free(percentiles);
}

void	large_stack_logic(t_stack **stack_a, t_stack **stack_b, const int len)
{
	int	index;
	int	*percentiles;
	int	i;

	i = 1;
	index = stack_size(*stack_a);
	percentiles = fnd_percentiles(stack_a, 8, (const int)(index / 8));
	while (i < 8)
	{
		while (get_nbr_value(stack_a, fnd_smlst_no(*stack_a)) < \
		percentiles[i - 1] && stack_size(*stack_b) <= ((len / 8) * i))
			smlst_no_top_sort(stack_a, stack_b, 'a', percentiles[(i - 1)]);
		index = stack_size(*stack_a);
		i++;
	}
	small_stack_logic(stack_a, stack_b, index);
	sort_rev_logic(stack_b, stack_a);
	free(percentiles);
}

void	micro_stack(t_stack **a)
{
	if ((*a)->content > (*a)->next->content)
	{
		if ((*a)->next->content < (*a)->next->next->content)
		{
			if ((*a)->next->next->content > (*a)->content)
				swap(a, 'a');
			else
				rotate(a, 'a');
		}
		else
		{
			swap(a, 'a');
			micro_rev_r(a, 'a');
		}
	}
	else if ((*a)->content < (*a)->next->content)
	{
		if ((*a)->content > (*a)->next->next->content)
			micro_rev_r(a, 'a');
		else
		{
			micro_rev_r(a, 'a');
			swap(a, 'a');
		}
	}
}