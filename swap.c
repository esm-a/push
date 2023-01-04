/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:05:17 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/04 10:28:41 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (ft_lstsize(a) <= 1)
		return ;
	temp = a->n;
	a->n = a->next->n;
	a->next->n = temp;
	ft_fprintf(1, "sa\n");
}

void	sb(t_stack *b)
{
	int	temp;

	if (ft_lstsize(b) <= 1)
		return ;
	temp = b->n;
	b->n = b->next->n;
	b->next->n = temp;
	ft_fprintf(1, "sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	ft_fprintf(1, "ss\n");
}
