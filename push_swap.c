/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:41:46 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/04 15:21:15 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "push_swap.h"

static void	check_args(char **av);
static void	overflow(t_stack *stk);
static void	duplicate(t_stack *stk);
static void	error(void);

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	return (1);
}

void  p1(t_stack **a, t_stack **b)
{
  pb(b, a);
  while (*a)
  {
	  pb(b, a);
	  if ((*b)->n > (*b)->next->n)
		  sb(*b);
  }
}

void	p2(t_stack **a, t_stack **b)
{
	pa(a, b);
	while (*b)
	{
		pa(a, b);
		if ((*a)->n > (*a)->next->n)
			sa(*a);
	}
}

void  sort(t_stack **a, t_stack **b)
{
	if (is_sorted(*a) == 1)
		return ;
	p1(a, b);
	p2(a, b);
	sort(&(*a)->next, b);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	//t_stack	*s;
	int		i;
	int		j;

	if (argc == 1)
		exit(1);
	check_args(argv);
	a = b = NULL;
	i = argc - 1;
	j = i;
	while (*++argv)
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(*argv)));
	overflow(a);
	duplicate(a);
	//s = a;
	//while (s)
	//{
	//	ft_fprintf(1, "|%d|\t", s->n);
	//	s = s->next;
	//}
	//ft_fprintf(1, "\n");
	sort(&a, &b);
	//s = a;
	//while (s)
	//{
	//	ft_fprintf(1, "|%d|\t", s->n);
	//	s = s->next;
	//}
	// system("leaks push_swap");
}

void	error(void)
{
	ft_fprintf(2, "ERROR\n");
	exit(1);
}

static void	check_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
				error();
			j++;
		}
		i++;
	}
}

static void	overflow(t_stack *stk)
{
	while (stk)
	{
		if (stk->n > INT_MAX)
			error();
		stk = stk->next;
	}
}

static void	duplicate(t_stack *stk)
{
	t_stack	*nxt;

	while (stk)
	{
		nxt = stk->next;
		while (nxt)
		{
			if (nxt->n == stk->n)
				error();
			nxt = nxt->next;
		}
		stk = stk->next;
	}
}
