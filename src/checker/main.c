/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:03:40 by ttranche          #+#    #+#             */
/*   Updated: 2021/06/08 17:47:33 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker/checker.h>

int	main(int argc, char **argv)
{
	t_mem	mem;

	mem.a = NULL;
	mem.b = NULL;
	mem.print = 0;
	if (argc <= 1)
		return (0);
	read_args(argc, argv, &mem);
	read_instructions(&mem);
	if (is_ordered(&mem))
		ft_putstr("OK");
	else
		ft_putstr("KO");
	clear_all(&mem);
	return (0);
}
