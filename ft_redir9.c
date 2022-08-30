#include "minishell.h"

int	exec_exit_chev(t_struct *d)
{
	int		i;
	int		last;

	i = 1;
	last = chev_right_pos(d);
	exec_exit_chev_2(d, last, i);
	if (d->l.arg_chev[1] != NULL)
		g_global.g_build_error_exec = ft_atoi(d->l.arg_chev[1]);
	else
		g_global.g_build_error_exec = 0;
	printf("exit\n");
	return (0);
}

void	exec_exit_chev_2(t_struct *d, int last, int i)
{
	int	pid;

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
