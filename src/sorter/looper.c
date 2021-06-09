/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:11:06 by ttranche          #+#    #+#             */
/*   Updated: 2021/06/08 17:44:27 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sorter/sorter.h>

int	loop_list(t_list *list, t_list *start, int set)
{
	t_list	*loop;
	int		max_tag;
	int		count;

	max_tag = -1;
	count = 0;
	loop = start;
	while (loop)
	{
		if (set)
			loop->keep = 0;
		if (loop->index > max_tag)
		{
			max_tag = loop->index;
			count++;
			if (set)
				loop->keep = 1;
		}
		loop = loop->next;
		if (loop == NULL)
			loop = list;
		if (loop == start)
			break ;
	}
	return (count);
}

int	find_biggest_loop(t_list *start, int set)
{
	t_list		*t;
	int			max;
	int			count;
	t_list		*max_keep;

	max = 0;
	t = start;
	while (t)
	{
		count = loop_list(start, t, 0);
		if (count > max)
		{
			max = count;
			max_keep = t;
		}
		t = t->next;
	}
	if (set)
		loop_list(start, max_keep, 1);
	return (max);
}
