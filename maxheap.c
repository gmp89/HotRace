/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxheap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 13:14:17 by wbeets            #+#    #+#             */
/*   Updated: 2013/12/14 17:25:57 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	buildheap(t_heap *A)
{
	int		i;

	i = A->size / 2;
	while (i >= 0)
	{
		makeHeap(A, i);
		i--;
	}
}

void	makeHeap(t_heap *A, int i)
{
	char	*largest;
	int		position;
	int		l;
	int		r;

	r = right(i);
	l = left(i);
	largest = A->tab[i].key;
	position = i;
	if(l <= A->size && A->tab[l].key > largest)
	{
		largest = A->tab[l].key;
		position = l;
	}
	if(r <= A->size && A->tab[r].key > largest)
	{
		largest = A->tab[r].key;
		position = r;
	}
	if(i != position)
	{
		swap(&A->tab[i], &A->tab[position]);
		makeHeap(A, position);
	}
}

void	swap(t_key_and_val *a, t_key_and_val *b)
{
	t_key_and_val temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	*extractMax(t_heap *A)
{
	char	*max;

	max = A->tab[0].val;
	if (!A->size)
		return (0);
	swap(&A->tab[0], &A->tab[A->size]);
	--A->size;
	makeHeap(A, 0);
	return (max);
}
