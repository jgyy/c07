/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 20:33:33 by jegoh             #+#    #+#             */
/*   Updated: 2023/08/02 09:43:24 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	total_length(int size, char **strs, char *sep)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	if (size > 0)
		total += (size - 1) * ft_strlen(sep);
	return (total);
}

char	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*cdest;
	const char	*csrc;
	size_t		i;

	cdest = (char *)dest;
	csrc = (const char *)src;
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}

char	*ft_return_empty(void)
{
	char	*empty_str;

	empty_str = (char *)malloc(1);
	*empty_str = '\0';
	return (empty_str);
}

// NULL IS A MACRO THAT DEFINES (void *)0
// sizeof() IS A UNARY OPERATOR THAT TELLS TYPE SIZE, NOT A FUNCTION
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		index;
	int		i;

	if (size == 0)
		return (ft_return_empty());
	result = (char *)malloc(total_length(size, strs, sep) + 1);
	index = 0;
	i = 0;
	while (i < size)
	{
		ft_memcpy(result + index, strs[i], ft_strlen(strs[i]));
		index += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_memcpy(result + index, sep, ft_strlen(sep));
			index += ft_strlen(sep);
		}
		i++;
	}
	result[index] = '\0';
	return (result);
}
/*
int main() {
    char *strs[] = {"Hello", "world", "from", "ft_strjoin!"};
    char *sep = " ";
    char *result = ft_strjoin(4, strs, sep);

    if (result != NULL)
	{
        printf("Concatenated string: %s\n", result);
        free(result);
    }
	else
        printf("Failed to concatenate the strings.\n");
    return (0);
}
*/
