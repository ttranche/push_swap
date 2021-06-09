/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:37:08 by ttranche          #+#    #+#             */
/*   Updated: 2021/06/08 17:39:11 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

void	push_init(t_list **stack, int value, int tag, t_mem *mem)
{
	t_list	*elem;
	t_list	*last;

	last = *stack;
	if (list_contains_value(*stack, value))
		exit_error(mem);
	elem = malloc(sizeof(t_list));
	if (!elem)
		exit_error(mem);
	elem->next = NULL;
	elem->next_sort = NULL;
	elem->value = value;
	elem->index = tag;
	if (last == NULL)
	{
		*stack = elem;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = elem;
	last->next_sort = elem;
}

void	swap_private(t_list **stack)
{
	t_list	*temp;
	t_list	*third;

	if (!*stack || !(*stack)->next)
		return ;
	third = (*stack)->next->next;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->next = temp;
	temp->next = third;
}

void	push_top_x1_on_x2(t_list **x1, t_list **x2)
{
	t_list	*top;

	if (!*x1)
		return ;
	top = *x1;
	*x1 = top->next;
	if (*x2)
		top->next = (*x2);
	else
		top->next = NULL;
	*x2 = top;
}

void	put_top_to_bottom(t_list **x)
{
	t_list	*top;
	t_list	*temp;

	if (!*x || !(*x)->next)
		return ;
	top = *x;
	*x = (*x)->next;
	temp = *x;
	while (temp->next)
		temp = temp->next;
	temp->next = top;
	top->next = NULL;
}

void	put_bottom_to_top(t_list **x)
{
	t_list	*last;
	t_list	*prev;

	if (!*x || !(*x)->next)
		return ;
	last = *x;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = (*x);
	*x = last;
	prev->next = NULL;
}
