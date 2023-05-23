/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:56:01 by syakovle          #+#    #+#             */
/*   Updated: 2022/11/09 14:49:23 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		res;
	int		n;

	str = (char *)nptr;
	res = 0;
	n = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		res *= 10;
		res += *str - 48;
		str++;
	}
	return (res * n);
}
