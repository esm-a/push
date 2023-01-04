/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:02:37 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/04 10:28:09 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*temp;
	int		size;

	last = ft_lstlast(*a);
	size = ft_lstsize(*a) - 1;
	temp = *a;
	while (--size > 0)
		temp = temp->next;
	last->next = *a;
	*a = last;
	temp->next = NULL;
	ft_fprintf(1, "rra\n");
}

void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*temp;
	int		size;

	last = ft_lstlast(*b);
	size = ft_lstsize(*b) - 1;
	temp = *b;
	while (--size > 0)
		temp = temp->next;
	last->next = *b;
	*b = last;
	temp->next = NULL;
	ft_fprintf(1, "rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_fprintf(1, "rrr\n");
}
