/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:54:54 by nlalleik          #+#    #+#             */
/*   Updated: 2022/09/19 19:28:39 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack	*lst, char id)
{
	t_stack	*tmp;
	int		c;

	c = 0;
	tmp = lst;
	while (tmp->next != NULL)
	{
		ft_printf("%c[%i]:	%i\n", id, c, tmp->content);
		tmp = tmp->next;
		c++;
	}
	ft_printf("%c[%i]:	%i\n", id, c, tmp->content);
}

void	build_stack(int count, char **args, t_stack **a)
{
	int		c;

	c = 1;
	while (c < count)
	{
		stack_add_back(a, stack_new((int)ft_atol(args[c])));
		c++;
	}
}

void	push(t_stack	**list_a, t_stack **list_b, char id)
{
	t_stack	*tmp;

	tmp = *list_b;
	*list_b = *list_a;
	if ((*list_a)->next == NULL)
		*list_a = NULL;
	else
		*list_a = (*list_a)->next;
	(*list_b)->next = tmp;
	if (id == 65 || id == 66)
		id = id + 32;
	if (id != 48)
		ft_printf("p%c\n", id);
}

int	checks(int count, char **args)
{
	int			c;

	c = 1;
	if (is_dupe(count, args) == 0)
		return (0);
	while (c < count)
	{
		if (!is_allowed(args[c]))
			return (0);
		if (!is_int(args[c]))
			return (0);
		c++;
	}
	return (1);
}

int	is_ordered(int count, char **args)
{
	int	i;

	i = 1;
	while (i < count - 1)
	{
		if (ft_atol(args[i]) > ft_atol(args[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
