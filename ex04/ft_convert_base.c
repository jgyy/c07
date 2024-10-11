/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:12:34 by jegoh             #+#    #+#             */
/*   Updated: 2023/08/16 12:56:18 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		is_valid_base(char *base);
int		nbr_to_int(char *nbr, char *base);
char	*int_to_str(int nbr, char *base, char *res, int index);
int		ft_strlen(char *str);

int	are_base_valid(char *base_from, char *base_to)
{
	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (0);
	return (1);
}

int	calculate_result_length(int number, char *base_to)
{
	int	size;
	int	tmp;

	if (number < 0)
	{
		size = 2;
		tmp = -number;
	}
	else
	{
		size = 1;
		tmp = number;
	}
	while (tmp)
	{
		tmp /= ft_strlen(base_to);
		size++;
	}
	return (size);
}

char	*convert_int_to_base_str(int number, char *base_to)
{
	char	*result;
	int		size;

	size = calculate_result_length(number, base_to);
	result = malloc(size);
	if (!result)
		return (NULL);
	result[size - 1] = '\0';
	int_to_str(number, base_to, result, size - 2);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		number;
	char	*result;

	if (!are_base_valid(base_from, base_to))
		return (NULL);
	number = nbr_to_int(nbr, base_from);
	if (number == 0)
	{
		result = malloc(2);
		if (!result)
			return (NULL);
		result[0] = base_to[0];
		result[1] = '\0';
		return (result);
	}
	return (convert_int_to_base_str(number, base_to));
}
