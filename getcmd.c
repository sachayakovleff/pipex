/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 03:28:29 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/24 01:17:07 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_find_path(char **envr)
{
	while (ft_strncmp("PATH", *envr, 4))
		envr++;
	return (*envr + 5);
}

int	ft_getcmd1(t_pipex *pipex)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char));
	while (pipex->pathcmd[i])
	{
		free(res);
		res = ft_strdup(pipex->pathcmd[i]);
		res = ft_strjoin(res, "/");
		res = ft_strjoin(res, pipex->cmd1);
		if (access(res, X_OK) == 0)
		{
			free(res);
			return (i);
		}
		i++;
	}
	free(res);
	return (i);
}

int	ft_getcmd2(t_pipex *pipex)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char));
	while (pipex->pathcmd[i])
	{
		free(res);
		res = ft_strdup(pipex->pathcmd[i]);
		res = ft_strjoin(res, "/");
		res = ft_strjoin(res, pipex->cmd2);
		if (access(res, X_OK) == 0)
		{
			free(res);
			return (i);
		}
		i++;
	}
	free(res);
	return (i);
}

void	ft_setenvr1(t_pipex *pipex, char **envr)
{
	char	*temp;

	pipex->path = ft_find_path(envr);
	pipex->pathcmd = ft_split(pipex->path, ':');
	temp = ft_strdup(pipex->pathcmd[ft_getcmd1(pipex)]);
	pipex->path = ft_strjoin(temp, "/");
}

void	ft_setenvr2(t_pipex *pipex, char **envr)
{
	char	*temp;

	pipex->path = ft_find_path(envr);
	pipex->pathcmd = ft_split(pipex->path, ':');
	temp = ft_strdup(pipex->pathcmd[ft_getcmd2(pipex)]);
	pipex->path = ft_strjoin(temp, "/");
}
