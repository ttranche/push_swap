/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:46:33 by ttranche          #+#    #+#             */
/*   Updated: 2021/06/08 17:47:55 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker/checker.h>

int	execute_action(char *name, t_mem *mem)
{
	if (!ft_strcmp(name, "sa"))
		swap_a(mem);
	else if (!ft_strcmp(name, "sb"))
		swap_b(mem);
	else if (!ft_strcmp(name, "ss"))
		swap_b_a(mem);
	else if (!ft_strcmp(name, "pa"))
		push_a(mem);
	else if (!ft_strcmp(name, "pb"))
		push_b(mem);
	else if (!ft_strcmp(name, "ra"))
		rotate_a(mem);
	else if (!ft_strcmp(name, "rb"))
		rotate_b(mem);
	else if (!ft_strcmp(name, "rr"))
		rotate_b_a(mem);
	else if (!ft_strcmp(name, "rra"))
		rev_rotate_a(mem);
	else if (!ft_strcmp(name, "rrb"))
		rev_rotate_b(mem);
	else if (!ft_strcmp(name, "rrr"))
		rev_rotate_b_a(mem);
	else
		return (0);
	return (1);
}

void	read_instructions(t_mem *mem)
{
	char	instruction[4];
	int		index;
	int		prev_index;

	index = 0;
	while (index < 4)
	{
		prev_index = index;
		index += read(0, instruction + index, 1);
		if (prev_index == index)
			break ;
		if (instruction[prev_index] == '\n')
		{
			instruction[prev_index] = 0;
			if (!execute_action(instruction, mem))
				exit_error(mem);
			index = 0;
		}
	}
	if (index == 4)
		exit_error(mem);
}
