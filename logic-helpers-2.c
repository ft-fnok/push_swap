/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic-helpers-2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:58:53 by nlalleik          #+#    #+#             */
/*   Updated: 2022/09/19 19:33:06 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_rev_logic(t_stack **stack_a, t_stack **stack_b)
{
	int	index;
	int	prox;
	int	lrgst_no_pos;

	while (*stack_a != NULL)
	{
		index = stack_size(*stack_a);
		prox = index / 2 + 1;
		lrgst_no_pos = fnd_lrgst_no(*stack_a);
		if ((lrgst_no_pos == 1) && (index < 2))
			push(stack_a, stack_b, 'a');
		else
		{
			lrgst_no_top(stack_a, 'b', index, prox);
			push(stack_a, stack_b, 'a');
		}
	}
}

void	smlst_no_top_sort(t_stack **a, t_stack **b, \
		char id, int breaker)
{
	int	smlst_no_pos;

	smlst_no_pos = fnd_smlst_no(*a);
	if (smlst_no_pos <= ((stack_size(*a) / 2) + 1))
		sort_fwd(a, b, id, breaker);
	else
		sort_bwd(a, b, id, breaker);
}

void	sort_fwd(t_stack **a, t_stack **b, char id, int breaker)
{
	int	smlst_no_pos;

	smlst_no_pos = fnd_smlst_no(*a);
	while (smlst_no_pos >= 1)
	{
		if ((*a)->content <= breaker)
			push(a, b, 'b');
		else
			rotate(a, id);
		smlst_no_pos--;
	}
}

void	sort_bwd(t_stack **a, t_stack **b, char id, int breaker)
{	
	int	smlst_no_pos;

	smlst_no_pos = fnd_smlst_no(*a);
	while (smlst_no_pos <= stack_size(*a))
	{
		if ((*a)->content <= breaker)
		{
			push(a, b, 'b');
			smlst_no_pos--;
		}
		else
		{
			rev_rotate(a, id);
			smlst_no_pos++;
		}
	}
	push(a, b, 'b');
}
