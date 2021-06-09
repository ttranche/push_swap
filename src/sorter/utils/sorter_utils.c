/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:05:14 by ttranche          #+#    #+#             */
/*   Updated: 2021/06/08 18:05:48 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sorter/sorter.h>

void	init_resolve(t_mem *mem)
{
	mem->big = find_biggest_loop(mem->a, 1);
	mem->size = list_size(mem->a);
	mem->group_cnt = ft_max(1, (int)(mem->max / 150.0));
	mem->group_sz = mem->max / mem->group_cnt;
}

int	distance_to_top(t_list *a, int tag)
{
	int	i;
	int	size;

	i = 0;
	size = list_size(a);
	while (a)
	{
		if (a->index == tag)
			break ;
		a = a->next;
		i++;
	}
	if (i > size / 2)
		i -= size;
	return (i);
}

int	distance_to_tag(int tag, int size)
{
	if (tag >= size / 2)
		tag -= size;
	return (tag);
}

t_list	*closest_in_group(t_list *list, int cur_group, int group_sz)
{
	t_list	*closest;
	t_list	*cur;
	int		distance;
	int		cur_dist;

	distance = 0xFFFFFFF;
	closest = NULL;
	cur = list;
	while (cur)
	{
		if (cur->index <= group_sz * cur_group && !cur->keep)
		{
			cur_dist = distance_to_top(list, cur->index);
			if (ft_abs(cur_dist) < ft_abs(distance))
			{
				distance = cur_dist;
				closest = cur;
				if (distance == 0)
					break ;
			}
		}
		cur = cur->next;
	}
	return (closest);
}
