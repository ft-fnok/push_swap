/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic-helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:04:34 by nlalleik          #+#    #+#             */
/*   Updated: 2022/09/18 22:18:36 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fnd_smlst_no(t_stack *stack)
{
	t_stack		*tmp;
	int			min;
	int			pos;
	int			cnt;

	tmp = stack;
	pos = 1;
	cnt = 0;
	min = tmp->content;
	while (tmp->next != NULL)
	{
		cnt++;
		tmp = tmp->next;
		if (tmp->content < min)
		{
			min = tmp->content;
			pos += cnt;
			cnt = 0;
		}
	}
	return (pos);
}

int	fnd_lrgst_no(t_stack *stack)
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
	return (pos);
}

int	fnd_nxt_smlst_no(t_stack *stack, int current)
{
	t_stack		*tmp;
	int			pos;
	int			cnt;
	int			nxt;

	tmp = stack;
	pos = 0;
	cnt = 0;
	nxt = fnd_lrgst_no_value(stack);
	while (tmp->next != NULL)
	{
		cnt++;
		if (tmp->content < nxt && (tmp->content > current))
		{
			nxt = tmp->content;
			pos += cnt;
			cnt = 0;
		}
	tmp = tmp->next;
	}
	return (pos);
}

int	get_nbr_value(t_stack **stack, int pos)
{
	t_stack	*tmp;
	int		c;

	tmp = *stack;
	c = 0;
	while (c < (pos - 1))
	{
		tmp = tmp->next;
		c++;
	}
	return (tmp->content);
}

int	get_nbr_pos(t_stack **stack, int nbr)
{
	t_stack	**tmp;
	int		pos;

	pos = 1;
	tmp = stack;
	if ((*tmp)->content == nbr)
		return (pos);
	while ((*tmp)->content != nbr)
	{
		tmp = &(*tmp)->next;
		pos++;
	}
	return (pos);
}
