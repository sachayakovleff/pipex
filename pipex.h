/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:44:52 by syakovle          #+#    #+#             */
/*   Updated: 2023/05/24 17:37:38 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "unistd.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>

# define ERR_RFILE "\033[0;31mCannot read file, does it exist ? \n"
# define ERR_WFILE "\033[0;31mCannot write in file, does it exist ? \n"
# define ERR_CMD1   "\033[0;31mCannot find first command\n"
# define ERR_CMD2   "\033[0;31mCannot find second command\n"
# define ERR_OPEN  "\033[0;31mCannot open file \n"
# define ERR_EXEC  "Cannot execute command, do you have the right access ? \n"
# define ERR_INPUT "Invalid input\nsyntax:./pipex <file1> <cmd1> <cmd2> <file2>\n"
# define ERR_PIPE  "\033[0;31mPipe\n"

typedef struct s_pipex
{
	int				pid1;
	int				pid2;
	int				fd1;
	int				fd2;
	char			*cmd1;
	char			*cmd2;
	char			*args1;
	char			*args2;
	char			**splitargs1;
	char			**splitargs2;
	char			*path;
	char			**pathcmd;
	int				pipeid[2];
}				t_pipex;

void	ft_freestr_array(char **str);
void	ft_freechild(t_pipex pipex);
void	ft_freepipex(t_pipex pipex);
void	ft_msgerr(char *err);
void	ft_err(char *err);
void	ft_exec1(t_pipex *pipex, char **envr);
void	ft_exec2(t_pipex *pipex, char **envr);
void	ft_setenvr1(t_pipex *pipex, char **envr);
void	ft_setenvr2(t_pipex *pipex, char **envr);

#endif