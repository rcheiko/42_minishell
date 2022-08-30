#include "minishell.h"

extern t_global	g_global;

int	exec_echo_chev(t_struct *d, t_list *l)
{
	int		i;
	int		last;

	i = 1;
	last = chev_right_pos(d);
	exec_echo_chev_3(d, l, i, last);
	return (0);
}

void	exec_echo_chev_2(t_struct *d, t_list *l)
{
	(void) l;
	echo_parse_chev(d);
}

void	exec_echo_chev_3(t_struct *d, t_list *l, int i, int last)
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
				exec_chev_last_binaire(d, last);
				break ;
			}
			exec_chev_nolast(d, i);
			i++;
		}
		exec_echo_chev_2(d, l);
		exit (0);
	}
	waitpid(g_global.g_kill_pid, &g_global.g_build_error_exec, 0);
}
