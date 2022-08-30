#include "minishell.h"

int	aff_env_memb(t_struct *d, t_list *l)
{
	t_elem	*count;
	int		i;

	count = l->first;
	i = get_pos_env(l, d->l.arg[1]);
	if (i == 0)
		return (0);
	while (i > 0)
	{
		count = count->next;
		i--;
	}
	if (ft_strlen(count->data) != 0)
	{
		printf("%s\n", count->data);
		return (1);
	}
	return (0);
}

void	exec_builtin(t_struct *d, t_list *l)
{
	char	*tmp;

	tmp = search_env(l, "HOME");
	if (ft_strlen(d->l.cmd) == 2
		&& ft_strcmp(d->l.cmd, "cd") == 0)
	{
		modify_old_pwd(d, l);
		if (ft_strncmp(d->l.line2, "cd ~ ", 5) == 0
			|| ft_strcmp(d->l.line2, "cd ~") == 0)
			chdir(tmp);
		else if (ft_strcmp(d->l.line2, "cd") == 0)
			chdir(tmp);
		else if (ft_strncmp(d->l.line2, "cd ", 3) == 0 && search_space(d) == 0)
			chdir(tmp);
		else
		{
			if (chdir(d->l.arg[1]) == -1)
			{
				printf("bash: cd: %s: No such file or directory\n", d->l.arg[1]);
				g_global.g_build_error_exec = 1;
			}
		}
		modify_pwd(d, l);
	}
	free_str(tmp);
}

void	exec_builtin_4(t_struct *d, t_list *l)
{
	if (ft_strlen(d->l.cmd) == 3 && ft_strcmp(d->l.cmd, "env") == 0
		&& get_pos_env(l, "PATH") != -1)
	{
		if (ft_strlen(d->l.line) == 3 && d->l.arg[1] == NULL)
			afflst(l);
		else if (d->l.arg[1])
		{
			if (aff_env_memb(d, l) != 1)
			{
				printf("env: %s: No such file or directory\n", d->l.arg[1]);
				g_global.g_build_error_exec = 1;
			}
		}
	}
	else if (ft_strlen(d->l.cmd) == 3 && ft_strcmp(d->l.cmd, "env") == 0
		&& get_pos_env(l, "PATH") == -1)
		printf("bash: %s: No such file or directory\n", d->l.cmd);
}
