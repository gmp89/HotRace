/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:55:18 by wbeets            #+#    #+#             */
/*   Updated: 2013/12/14 09:56:22 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;

	if ((mem = (char*)malloc(size * sizeof(mem))))
	{
		ft_memset(mem, 0 , size);
		return (mem);
	}
	return (NULL);
}
