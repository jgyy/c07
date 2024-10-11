/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:35:30 by jegoh             #+#    #+#             */
/*   Updated: 2023/08/16 12:49:06 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	arr = (int *)malloc(size * sizeof(int));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = min++;
		i++;
	}
	return (arr);
}
/*
#include <stdio.h>
int main(void)
{
	int min = 0;
	int max = 10;
	int	*arr = ft_range(min, max);
	for (int i = 0; i < (max - min); i++)
		printf("%d\n", arr[i]);
	return (0);
}
*/
