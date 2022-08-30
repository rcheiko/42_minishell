#include "minishell.h"

extern t_global	g_global;

int	exec_env_chev(t_struct *d, t_list *l)
{
	int		i;
	int		last;
	t_elem	*count;

	last = chev_right_pos(d);
	i = 1;
	count = l->first;
	exec_env_chev_2(d, l, i, last);
	if (d->l.buf && d->l.buf[3] == 'q')
	{
		count = l->first;
		while (count != NULL)
		{
			ft_putstr_fd(count->data, 1);
			ft_putstr_fd("\n", 1);
			count = count->next;
		}
	}
	return (0);
}

void	exec_env_chev_2(t_struct *d, t_list *l, int i, int last)
{
	d->l.fd = 0;
	d->l.fd2 = 0;
	d->l.i = chev_right_pos(d);
	g_global.g_kill_pid = fork();
	if (g_global.g_kill_pid == 0)
	{
		signal(SIGTERM, handler);
		while (i <= d->l.ch_nb || d->l.i != d->l.ch_nb)
		{
			if ((d->l.ch_nb == i && d->l.ch_nb == d->l.i)
				|| (i == d->l.ch_nb + 1))
			{
				exec_chev_last_binaire(d, last);
				break ;
			}
			exec_chev_nolast(d, i);
			i++;
		}
		exec_env_chev_3(l);
	}
	waitpid(g_global.g_kill_pid, &g_global.g_build_error_exec, 0);
}

void	exec_env_chev_3(t_list *l)
{
	t_elem	*count;

	count = l->first;
	while (count != NULL)
	{
		ft_putstr_fd(count->data, 1);
		ft_putstr_fd("\n", 1);
		count = count->next;
	}
	exit (0);
}
