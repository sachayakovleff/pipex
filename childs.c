/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:05:58 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/24 01:15:07 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_setenvr1(t_pipex *pipex, char **envr);
void	ft_setenvr2(t_pipex *pipex, char **envr);

void	ft_exec1(t_pipex *pipex, char **envr)
{
	char	*cmd;

	ft_setenvr1(pipex, envr);
	dup2(pipex->pipeid[1], 1);
	close(pipex->pipeid[0]);
	dup2(pipex->fd1, 0);
	cmd = ft_strjoin(pipex->path, pipex->cmd1);
	pipex->splitargs1 = ft_split(pipex->args1, ' ');
	execve(cmd, pipex->splitargs1, envr);
	ft_printf("Command '%s' not found\n", pipex->cmd1);
	ft_freestr_array(pipex->splitargs1);
	ft_freechild(*pipex);
	free(cmd);
	exit(1);
}

void	ft_exec2(t_pipex *pipex, char **envr)
{
	char	*cmd;

	ft_setenvr2(pipex, envr);
	dup2(pipex->pipeid[0], 0);
	close(pipex->pipeid[1]);
	dup2(pipex->fd2, 1);
	cmd = ft_strjoin(pipex->path, pipex->cmd2);
	pipex->splitargs2 = ft_split(pipex->args2, ' ');
	execve(cmd, pipex->splitargs2, envr);
	ft_printf("Command '%s' not found\n", pipex->cmd2);
	ft_freechild(*pipex);
	ft_freestr_array(pipex->splitargs2);
	free(cmd);
	exit(1);
}
