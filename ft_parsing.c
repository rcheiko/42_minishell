#include "minishell.h"

int	is_builtin(t_struct *d)
{
	int	i;

	i = 0;
	if (ft_strcmp(d->l.cmd, "export") == 0)
		return (1);
	else if (ft_strcmp(d->l.cmd, "unset") == 0)
		return (1);
	else if (ft_strcmp(d->l.cmd, "cd") == 0)
		return (1);
	else if (ft_strcmp(d->l.cmd, "env") == 0)
		return (1);
	else if (ft_strcmp(d->l.cmd, "echo") == 0)
		return (1);
	else if (ft_strcmp(d->l.cmd, "exit") == 0)
		return (1);
	else if (ft_strcmp(d->l.cmd, "pwd") == 0)
		return (1);
	return (0);
}

void	ft_pars(t_struct *d, t_list *l)
{
	int		pid;
	char	*str;
	char	*tmp;

	str = NULL;
	pid = -1;
	str = malloc(1);
	str[0] = '\0';
	if (get_pos_env(l, "PATH") != -1)
	{
		free_str(str);
		str = get_binaire(d);
		if (str[0] != '\0')
		{
			tmp = ft_strdup(str);
			free_str(str);
			str = ft_strjoin(tmp, d->l.cmd);
			free_str(tmp);
		}
	}
	ft_pars_2(d, l, str, pid);
	free_str(str);
}

void	ft_pars_3(t_struct *d)
{
	if (ft_strcmp(d->l.line, "<") == 0 || ft_strcmp(d->l.line, ">") == 0
		|| ft_strcmp(d->l.line, "<<") == 0 || ft_strcmp(d->l.line, "<<") == 0)
	{
		g_global.g_build_error_exec = 258;
		printf("bash: syntax error near unexpected token `newline'\n");
	}
	else if (ft_strcmp(d->l.line, ";") == 0)
	{
		g_global.g_build_error_exec = 258;
		printf("bash: syntax error near unexpected token ';'\n");
	}
	else
	{
		g_global.g_build_error_exec = 127;
		printf("bash: %s: command not found\n", d->l.line);
	}
	return ;
}

void	ft_pars_2(t_struct *d, t_list *l, char *str, int pid)
{
	if (get_pos_env(l, "PATH") != -1 && str && str[0] == '\0')
	{
		ft_pars_3(d);
		return ;
	}
	if ((ft_strcmp(d->l.cmd, "cat") == 0
			|| ft_strcmp(d->l.cmd, "wc") == 0) && d->l.arg[1] == NULL)
	{
		g_global.g_build_error_exec = 130;
		g_global.g_status = 2;
	}
	pid = fork();
	if (pid == 0)
	{
		execve(str, d->l.arg, d->my_envp);
		exit (0);
	}
	waitpid(pid, &g_global.g_build_error_exec, 0);
	if (get_pos_env(l, "PATH") == -1)
	{
		g_global.g_build_error_exec = 127;
		printf("bash: %s: No such file or directory\n", d->l.cmd);
	}
}

void	ft_exec_bin(t_struct *d)
{
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(d->l.cmd, d->l.arg, d->my_envp) == -1)
		{
			printf("bash: %s: No such file or directory\n", d->l.line);
			exit (0);
		}
	}
	waitpid(pid, &g_global.g_build_error_exec, 0);
}
