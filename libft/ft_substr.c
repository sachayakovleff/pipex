/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:17:29 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/11 15:58:40 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_setmalloc(const char *s, unsigned int start, size_t len)
{
	if (start > ft_strlen(s) || !s || len == 0)
		return (malloc(sizeof(char)));
	if (len + start > ft_strlen(s))
		return (malloc(sizeof(char) * (ft_strlen(s) - start + 1)));
	return (malloc(sizeof(char) * (len + 1)));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	const size_t	k = ft_strlen(s);

	str = ft_setmalloc(s, start, len);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && i + start < k)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
