/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:51:14 by syakovle          #+#    #+#             */
/*   Updated: 2023/04/11 15:51:52 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_err(char *err)
{
	ft_printf(err);
	ft_printf("\n");
	exit(0);
}

void	ft_msgerr(char *err)
{
	perror(err);
	exit(0);
}
