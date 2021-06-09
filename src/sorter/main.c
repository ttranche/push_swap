/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:35:43 by ttranche          #+#    #+#             */
/*   Updated: 2021/06/08 18:27:21 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sorter/sorter.h>

int	main(int argc, char **argv)
{
	t_mem	mem;
	t_list	*start_tag;

	mem.a = NULL;
	mem.b = NULL;
	mem.print = 1;
	if (argc <= 1)
		return (0);
	read_args(argc, argv, &mem);
	if (!is_ordered(&mem))
	{
		start_tag = (mem.a);
		ft_list_sort(&start_tag);
		tag_list(start_tag, &mem);
		if (mem.max == 5)
			prepare_five(&mem);
		resolve(&mem, 1);
	}
	clear_all(&mem);
	start_tag = NULL;
	return (0);
}
