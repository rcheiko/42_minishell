#include "minishell.h"

int	exec_pwd_chev(t_struct *d)
{
	char	*str;
	int		last;
	int		i;

	i = 1;
	last = chev_right_pos(d);
	str = malloc(1000);
	exec_pwd_chev_2(d, str, last, i);
	if (d->l.buf && d->l.buf[3] == 'q')
	{
		getcwd(str, 1000);
		ft_putstr_fd(str, 1);
		ft_putstr_fd("\n", 1);
	}
	free_str(str);
	return (0);
}

void	exec_pwd_chev_2(t_struct *d, char *str, int last, int i)
{
	d->l.fd = 0;
	d->l.fd2 = 0;
	g_global.g_kill_pid = fork();
	if (g_global.g_kill_pid == 0)
	{
		signal(SIGTERM, handler);
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
		getcwd(str, 1000);
		ft_putstr_fd(str, 1);
		ft_putstr_fd("\n", 1);
		close(d->l.fd2);
		exit (0);
	}
	waitpid(g_global.g_kill_pid, &g_global.g_build_error_exec, 0);
}
