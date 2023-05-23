/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:10:39 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/24 01:15:04 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_freestr_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
}

void	ft_freechild(t_pipex pipex)
{
	ft_freestr_array(pipex.pathcmd);
	free(pipex.cmd1);
	free(pipex.cmd2);
	free(pipex.args1);
	free(pipex.args2);
	close(pipex.fd1);
	close(pipex.fd2);
	close(pipex.pipeid[0]);
	close(pipex.pipeid[1]);
}

void	ft_freepipex(t_pipex pipex)
{
	free(pipex.cmd1);
	free(pipex.cmd2);
	free(pipex.args1);
	free(pipex.args2);
	close(pipex.fd1);
	close(pipex.fd2);
	close(pipex.pipeid[0]);
	close(pipex.pipeid[1]);
}
