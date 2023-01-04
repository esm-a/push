/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:52:54 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/04 12:15:59 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*top;

	top = *b;
	ft_lstadd_front(a, ft_lstnew(top->n));
	*b = top->next;
	free(top);
	ft_fprintf(1, "pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack	*top;

	top = *a;
	ft_lstadd_front(b, ft_lstnew(top->n));
	*a = top->next;
	free(top);
	ft_fprintf(1, "pb\n");
}
