#include "minishell.h"

int	exec_builtin_2(t_struct *d, t_list *l, t_list *exp)
{
	char	*bufcwd;
	int		i;

	i = 0;
	bufcwd = malloc(100);
	exec_builtin_5(d, l, exp, bufcwd);
	if (ft_strlen(d->l.cmd) == 4
		&& ft_strcmp(d->l.cmd, "exit") == 0)
	{
		if (ft_strlen_twochar(d->l.arg) >= 2)
			i = exit_arg(d);
		else
		{
			printf("exit\n");
			g_global.g_build_error_exec = 0;
			exit(g_global.g_build_error_exec);
		}
		free_str(bufcwd);
		return (i);
	}
	free_str(bufcwd);
	return (0);
}

void	exec_builtin_5(t_struct *d, t_list *l, t_list *exp, char *bufcwd)
{
	if (ft_strlen(d->l.cmd) == 6
		&& ft_strcmp(d->l.cmd, "export") == 0)
	{
		built_in_export(d, l, exp);
		update_my_envp(d, l);
		alphabetic_order(exp);
	}
	else if (ft_strlen(d->l.cmd) == 3
		&& ft_strcmp(d->l.cmd, "pwd") == 0)
	{
		printf("%s\n", getcwd(bufcwd, 100));
		g_global.g_build_error_exec = 0;
	}
	else if (ft_strlen(d->l.cmd) == 5
		&& ft_strcmp(d->l.cmd, "unset") == 0)
	{
		built_in_unset(d, l, exp);
		update_my_envp(d, l);
	}
}

void	exec_builtin_3(t_struct *d, t_list *exp)
{
	if ((ft_strlen(d->l.line) == 6)
		&& (ft_strcmp(d->l.line, "export") == 0)
		&& d->l.arg[1] == NULL)
	{
		alphabetic_order(exp);
		afflst_back(exp);
	}
	if ((ft_strlen(d->l.line) == 2)
		&& (ft_strcmp(d->l.line, "$?") == 0)
		&& d->l.arg[1] == NULL)
		printf("bash: %d: command not found\n", g_global.g_build_error_exec);
	else if (ft_strcmp(d->l.line, "echo") == 0)
		printf("\n");
	else if (ft_strlen(d->l.cmd) == 4
		&& ft_strcmp(d->l.cmd, "echo") == 0)
	{
		echo_parse(d);
		g_global.g_build_error_exec = 0;
	}
}
