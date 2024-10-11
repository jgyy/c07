/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:24:37 by jegoh             #+#    #+#             */
/*   Updated: 2023/08/16 12:27:10 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] == ' ' || (base[i] >= '\t' && base[i] <= '\r')))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	base_to_int(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	nbr_to_int(char *nbr, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	base_len;

	i = 0;
	sign = 1;
	result = 0;
	base_len = ft_strlen(base);
	while (nbr[i] == ' ' || (nbr[i] >= '\t' && nbr[i] <= '\r'))
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nbr[i] && base_to_int(nbr[i], base) != -1)
	{
		result = result * base_len + base_to_int(nbr[i], base);
		i++;
	}
	return (result * sign);
}

char	*int_to_str(int nbr, char *base, char *res, int index)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		res[0] = '-';
		return (int_to_str(-nbr, base, res, index));
	}
	else if (nbr >= base_len)
	{
		res = int_to_str(nbr / base_len, base, res, index - 1);
		res[index] = base[nbr % base_len];
	}
	else
	{
		res[index] = base[nbr % base_len];
	}
	return (res);
}
