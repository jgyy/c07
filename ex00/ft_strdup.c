/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:09:14 by jegoh             #+#    #+#             */
/*   Updated: 2023/07/31 23:33:38 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

// NULL IS A MACRO THAT DEFINES (void *)0
// sizeof() IS A UNARY OPERATOR THAT TELLS TYPE SIZE, NOT A FUNCTION
char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*dup;

	if (!src)
		return (NULL);
	len = 0;
	while (src[len])
		len++;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}
