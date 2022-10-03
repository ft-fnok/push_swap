/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:16:02 by nlalleik          #+#    #+#             */
/*   Updated: 2022/09/19 19:36:02 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **list, char id)
{
	t_stack	*tmp;

	tmp = *list;
	*list = (*list)->next;
	tmp->next = (*list)->next;
	(*list)->next = tmp;
	if (id == 65 || id == 66)
		id = id + 32;
	if (id != 48)
		ft_printf("s%c\n", id);
}

void	rotate(t_stack **list, char id)
{
	t_stack	*last;
	t_stack	*tmp;

	last = stack_last(*list);
	tmp = *list;
	*list = (*list)->next;
	tmp->next = NULL;
	last->next = tmp;
	if (id == 65 || id == 66)
		id = id + 32;
	if (id != 48)
		ft_printf("r%c\n", id);
}

void	rev_rotate(t_stack **list, char id)
{
	t_stack	*last;
	t_stack	*tmp;

	last = stack_last(*list);
	tmp = *list;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *list;
	*list = last;
	if (id == 65 || id == 66)
		id = id + 32;
	if (id != 48)
		ft_printf("rr%c\n", id);
}

void	micro_rev_r(t_stack **list, char id)
{
	t_stack		**tmp;

	tmp = &(*list)->next;
	(*list)->next->next->next = *list;
	*list = (*tmp)->next;
	(*tmp)->next = NULL;
	if (id == 65 || id == 66)
		id = id + 32;
	if (id != 48)
		ft_printf("rr%c\n", id);
}

int	main(int argc, char *argv[])
{
	t_stack	**a;
	t_stack	**b;

	if (argc < 2)
		return (0);
	else if (!checks(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else if (is_ordered(argc, argv) == 1)
		return (0);
	else
	{
		a = ft_calloc(1, sizeof(t_stack *));
		b = ft_calloc(1, sizeof(t_stack *));
		build_stack(argc, argv, a);
		logic(a, b);
		free_lst(*a);
		free(a);
		free(b);
		return (0);
	}
}
