/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_db.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:02:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/23 12:50:04 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_index *index)
{
	swap_a(index);
	swap_b(index);
	write(1, "ss\n", 3);
}

void	rotate_ab(t_index *index)
{
	rotate_a(index);
	rotate_b(index);
	write(1, "rr\n", 3);
}

void	revrot_ab(t_index *index)
{
	revrot_a(index);
	revrot_b(index);
	write(1, "rrr\n", 4);
}
