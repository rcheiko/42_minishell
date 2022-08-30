#include "minishell.h"

int	exec_unset_chev(t_struct *d, t_list *l)
{
	int		pid;
	int		last;

	pid = 0;
	last = chev_right_pos(d);
	exec_unset_chev_2(d, last, pid);
	built_in_unset_chev(d, l);
	update_my_envp(d, l);
	return (0);
}

void	exec_unset_chev_2(t_struct *d, int last, int pid)
{
	int	i;

	i = 1;
	pid = fork();
	if (pid == 0)
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
		exit (0);
	}
	waitpid(pid, &g_global.g_build_error_exec, 0);
}
