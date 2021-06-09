/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttranche <ttranche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:24:14 by ttranche          #+#    #+#             */
/*   Updated: 2021/06/08 17:48:23 by ttranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <common/common.h>

int		execute_action(char *name, t_mem *mem);
void	read_instructions(t_mem *mem);

#endif
