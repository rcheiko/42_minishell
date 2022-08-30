#include "minishell.h"

extern t_global	g_global;

int	exec_cd_chev(t_struct *d, t_list *l)
{
	int		i;
	int		last;

	i = 1;
	last = chev_right_pos(d);
	exec_cd_chev_3(d, i, last);
	exec_cd_chev_2(d, l);
	return (0);
}

void	exec_cd_chev_2(t_struct *d, t_list *l)
{
	char	*tmp;

	tmp = search_env(l, "HOME");
	modify_old_pwd(d, l);
	if (ft_strncmp(d->l.chetab_cd[0], "cd ~", 4) == 0)
		chdir(tmp);
	else if (ft_strcmp(d->l.chetab_cd[0], "cd") == 0)
		chdir(tmp);
	else if (ft_strncmp(d->l.chetab_cd[0], "cd ", 3) == 0
		&& search_space_cd(d) == 0)
		chdir(tmp);
	else
	{
		if (chdir(d->l.arg_chev[1]) == -1)
		{
			printf("bash: cd: %s: No such file or directory\n", d->l.arg[1]);
			g_global.g_build_error_exec = 1;
		}
	}
	modify_pwd(d, l);
	free_str(tmp);
}

void	exec_cd_chev_3(t_struct *d, int i, int last)
{
	d->l.fd = 0;
	d->l.fd2 = 0;
	g_global.g_kill_pid = fork();
	if (g_global.g_kill_pid == 0)
	{
		while (i <= d->l.ch_nb || last != d->l.ch_nb)
		{
			if ((d->l.ch_nb == i && d->l.ch_nb == last)
				|| (i == d->l.ch_nb + 1))
			{
				exec_chev_last_nodup(d, last);
				break ;
			}
			exec_chev_nolast(d, i);
			i++;
		}
		exit(0);
	}
	waitpid(g_global.g_kill_pid, &g_global.g_build_error_exec, 0);
}

void	exec_chev_last_nodup(t_struct *d, int last)
{
	int	fd;

	fd = 0;
	if (ft_strcmp(d->l.chev_tab[last - 1], "<<") == 0)
	{
		fd = d_chevron_left(d, last);
		close(fd);
	}
	else if (ft_strcmp(d->l.chev_tab[last - 1], "<") == 0)
	{
		fd = s_chevron_left(d, last);
		if (fd == -1)
			exit (1);
		close(fd);
	}
	else if (ft_strcmp(d->l.chev_tab[last - 1], ">") == 0)
	{
		fd = s_chevron_right(d, last);
		close(fd);
	}
	else if (ft_strcmp(d->l.chev_tab[last - 1], ">>") == 0)
	{
		fd = d_chevron_right(d, last);
		close(fd);
	}
}
