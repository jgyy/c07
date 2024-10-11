/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:02:34 by jegoh             #+#    #+#             */
/*   Updated: 2023/08/16 13:31:13 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			count++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	return (count);
}

char	*extract_word(char *str, char *charset)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !is_sep(str[i], charset))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (*str && !is_sep(*str, charset))
	{
		word[i] = *str;
		i++;
		str++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		word;
	char	**result;
	int		i;

	word = count_words(str, charset);
	result = (char **)malloc(sizeof(char *) * (word + 1));
	i = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			result[i] = extract_word(str, charset);
			i++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	result[i] = 0;
	return (result);
}
/*
#include <stdio.h>

int main(void)
{
    char *str = "Hello,world!How,are,you,today?";
    char *charset = ",?!";
    char **result = ft_split(str, charset);

    int i = 0;
    while (result[i])
    {
        printf("Word %d: %s\n", i + 1, result[i]);
        free(result[i]);
        i++;
    }
    free(result);

    return (0);
}
*/
