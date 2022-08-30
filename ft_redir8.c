#include "minishell.h"

extern t_global	g_global;

int	exec_export_chev_2(t_struct *d, t_list *exp, t_list *l)
{
	int		i;
	int		last;

	i = 1;
	last = chev_right_pos(d);
	exec_export_chev(d, exp, last, i);
	if (ft_strcmp(d->l.chetab[0], "export") != 0
		&& ft_strncmp(d->l.chetab[0], "export", 6) == 0)
	{
		built_in_export_chev(d, l, exp);
		update_my_envp(d, l);
	}
	return (0);
}

void	exec_export_chev(t_struct *d, t_list *exp, int last, int i)
{
	g_global.g_kill_pid = fork();
	if (g_global.g_kill_pid == 0)
	{
		while (i <= d->l.ch_nb || last != d->l.ch_nb)
		{
			if ((d->l.ch_nb == i && d->l.ch_nb == last)
				|| (i == d->l.ch_nb + 1))
			{
				d->l.fd2 = exec_chev_last(d, last, d->l.fd, d->l.fd2);
				break ;
			}
			exec_chev_nolast(d, i);
			i++;
		}
		if ((ft_strcmp(d->l.chetab[0], "export") == 0))
			afflst(exp);
		exit (0);
	}
	waitpid(g_global.g_kill_pid, &g_global.g_build_error_exec, 0);
}
