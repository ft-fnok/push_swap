/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:29:46 by nlalleik          #+#    #+#             */
/*   Updated: 2022/10/03 09:59:10 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/libftprintf.h"
# include <stdio.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

// stack functions
void	build_stack(int count, char	**args, t_stack **a);
void	swap(t_stack **list, char id);
void	swap_both(t_stack **list_a, t_stack **list_b);
void	push(t_stack	**list_a, t_stack	**list_b, char id);
void	print_stack(t_stack	*lst, char id);
void	rotate(t_stack **list, char id);
void	rev_rotate(t_stack **list, char id);
void	rotate_both(t_stack **list_a, t_stack **list_b);
void	rev_rotate_both(t_stack **list_a, t_stack **list_b);

// check functions
int		checks(int count, char **args);
int		is_allowed(const char *s);
int		is_int(const char *s);
int		is_ordered(int count, char **args);
long	ft_atol(const char *nptr);
int		is_dupe(int count, char **args);
void	micro_rev_r(t_stack **list, char id);

// modified lst-functions
t_stack	*stack_new(int content);
t_stack	*stack_last(t_stack *lst);
void	stack_add_back(t_stack **lst, t_stack *new);
int		stack_size(t_stack *lst);
void	free_lst(t_stack *lst);

// algorithm functions
void	logic(t_stack **stack_a, t_stack **stack_b);
void	micro_stack(t_stack **a);
void	small_stack_logic(t_stack **stack_a, t_stack **stack_b, int index);
void	medium_stack_logic(t_stack **stack_a, t_stack **stack_b, int index);
void	large_stack_logic(t_stack **stack_a, t_stack **stack_b, int index);
int		fnd_smlst_no(t_stack *stack);
int		fnd_lrgst_no(t_stack *stack);
int		fnd_lrgst_no_value(t_stack *stack);
void	smlst_no_top(t_stack **stack, char id, int index, int prox);
void	lrgst_no_top(t_stack **stack, char id, int index, int prox);
void	sort_rev_logic(t_stack **stack_a, t_stack **stack_b);
void	smlst_no_top_sort(t_stack **stack_a, t_stack **stack_b, \
		char id, int percentile);
void	sort_fwd(t_stack **a, t_stack **b, char id, int breaker);
void	sort_bwd(t_stack **a, t_stack **b, char id, int breaker);
int		fnd_percentile(t_stack **stack, int percentile);
int		get_nbr_value(t_stack **stack, int pos);
int		fnd_nxt_smlst_no(t_stack *stack, int current);
int		get_nbr_pos(t_stack **stack, int nbr);
int		*fnd_percentiles(t_stack **stack, int num, const int update_count);

#endif