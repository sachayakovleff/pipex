/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:31:29 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/19 07:11:58 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_initpipex(t_pipex *pipex, int ac, char **av)
{
	if (ac != 5)
		ft_err(ERR_INPUT);
	pipex->fd1 = open(av[1], O_RDONLY);
	if (pipex->fd1 < 0)
		ft_msgerr(ERR_OPEN);
	pipex->fd2 = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex->fd2 < 0)
	{
		close(pipex->fd1);
		ft_msgerr(ERR_OPEN);
	}
	if (pipe(pipex->pipeid) < 0)
	{
		close(pipex->fd1);
		close(pipex->fd2);
		ft_msgerr(ERR_PIPE);
	}
	pipex->args1 = malloc(sizeof(char));
	pipex->args2 = malloc(sizeof(char));
	pipex->args1[0] = 0;
	pipex->args2[0] = 0;
}

void	getcmd1(t_pipex *pipex, char *str)
{
	char	**cmd;
	char	*tmp;
	int		i;

	i = 0;
	cmd = ft_split(str, ' ');
	if (cmd == NULL)
		return ;
	tmp = ft_strdup(cmd[0]);
	pipex->cmd1 = tmp;
	while (cmd[i])
	{
		tmp = ft_strdup(cmd[i]);
		pipex->args1 = ft_strjoin(pipex->args1, tmp);
		pipex->args1 = ft_strjoin(pipex->args1, " ");
		free(tmp);
		i++;
	}
	ft_freestr_array(cmd);
}

void	getcmd2(t_pipex *pipex, char *str)
{
	char	**cmd;
	char	*tmp;
	int		i;

	i = 0;
	cmd = ft_split(str, ' ');
	if (cmd == NULL)
		return ;
	tmp = ft_strdup(cmd[0]);
	pipex->cmd2 = tmp;
	while (cmd[i])
	{
		tmp = ft_strdup(cmd[i]);
		pipex->args2 = ft_strjoin(pipex->args2, tmp);
		pipex->args2 = ft_strjoin(pipex->args2, " ");
		free(tmp);
		i++;
	}
	ft_freestr_array(cmd);
}

void	ft_setargs(t_pipex *pipex, int ac, char **av)
{
	if (ac != 5)
		ft_err(ERR_INPUT);
	getcmd1(pipex, av[2]);
	getcmd2(pipex, av[3]);
}

int	main(int ac, char **av, char **envr)
{
	t_pipex	pipex;

	ft_initpipex(&pipex, ac, av);
	ft_setargs(&pipex, ac, av);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		ft_exec1(&pipex, envr);
	waitpid(pipex.pid1, NULL, 0);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		ft_exec2(&pipex, envr);
	close(pipex.pipeid[0]);
	close(pipex.pipeid[1]);
	waitpid(pipex.pid2, NULL, 0);
	ft_freepipex(pipex);
	return (0);
}
