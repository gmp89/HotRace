/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 09:27:58 by wbeets            #+#    #+#             */
/*   Updated: 2013/12/14 17:59:46 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main()
{
	t_key_and_val	*tab;
	int				ret;
	int				j;
	int				k;

	k = -1;
	ret = 1;
	j = -1;
	tab = (t_key_and_val*)malloc(100 * (sizeof(t_key_and_val)));
	while (ret > 0 && ++j >= 0 && ++k >= 0)
		ret = hotwhile(&j, &k, &tab);
	return (0);
}

int		hotwhile(int *j, int *k, t_key_and_val **tab)
{
	char			*line;
	int				ret;

	if ((ret = get_next_line(0, &line)) != 0)
	{
		if (ft_strcmp(line, "") == 0)
			ret = hotcut(j, k, &line, tab);
		(*tab + *j)->key = ft_strdup(line);
		free(line);
		ft_putstr((const char *)(*tab + *j)->key);
	}
	if (ret && (ret = get_next_line(0, &line)) != 0)
	{
		(*tab + *j)->val = ft_strdup(line);
		free(line);
		ft_putstr((const char *)(*tab + *j)->val);
	}
	return (ret);
}

int		hotcut(int *j, int *k, char **line, t_key_and_val **tab)
{
	t_heap			sheap;
	t_heap			*heap;
	char			*str;
	int				ret;

	str = "boo";
	ret = 0;
	sheap.tab = *tab;
	sheap.size = *k;
	heap = &sheap;
	buildheap(heap);
	while ((str = extractMax(heap)) != 0)
		ft_putstr(str);
	if ((ret = get_next_line(0, line)) != 0)
	{
		*j = 1;
		while (*j <= *k)
		{
			if (ft_strcmp(*line, (const char *)(*tab + *j)->key) == 0)
				ft_putstr((const char *)(*tab + *j)->val);
			*j += 1;
		}
	}
	return (ret);
}