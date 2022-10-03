/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:56:44 by nlalleik          #+#    #+#             */
/*   Updated: 2022/09/19 19:29:54 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int content)
{
	t_stack	*list;

	list = malloc(1 * sizeof(t_stack));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

t_stack	*stack_last(t_stack *lst)
{
	t_stack	*last;

	if (!lst)
		return (lst);
	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = stack_last(*lst);
		last->next = new;
	}
}

int	stack_size(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	free_lst(t_stack *lst)
{
	t_stack	*tmp;

	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}
