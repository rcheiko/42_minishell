#include "minishell.h"

int	chev_right_pos(t_struct *d)
{
	int	i;

	i = d->l.ch_nb - 1;
	if (i == 0)
		return (d->l.ch_nb);
	while (d->l.chev_tab[i] != NULL && i >= 0)
	{
		if (ft_strcmp(d->l.chev_tab[i], ">>") == 0)
			return (i + 1);
		if (ft_strcmp(d->l.chev_tab[i], ">") == 0)
			return (i + 1);
		i--;
	}
	return (d->l.ch_nb);
}

int	exec_mult_chev(t_struct *d, t_list *l)
{
	char	*str;
	int		last;

	last = chev_right_pos(d);
	str = ft_init_exec_chev(d, l);
	exec_mult_chev_2(d, str, last);
	exec_m_chev_buf(d, str);
	free_str(str);
	return (0);
}

void	exec_chev_last_binaire(t_struct *d, int last)
{
	if (ft_strcmp(d->l.chev_tab[last - 1], "<<") == 0)
	{
		d->l.fd = d_chevron_left(d, last);
		exec_chev_last_in_bin(d->l.fd);
	}
	else if (ft_strcmp(d->l.chev_tab[last - 1], "<") == 0)
	{
		d->l.fd = s_chevron_left(d, last);
		if (d->l.fd == -1)
			exit (1);
		exec_chev_last_in_bin(d->l.fd);
	}
	else if (ft_strcmp(d->l.chev_tab[last - 1], ">") == 0)
	{
		d->l.fd = s_chevron_right(d, last);
		exec_chev_last_out_bin(d, d->l.fd);
	}
	else if (ft_strcmp(d->l.chev_tab[last - 1], ">>") == 0)
	{
		d->l.fd = d_chevron_right(d, last);
		exec_chev_last_out_bin(d, d->l.fd);
	}
}

void	exec_mult_chev_2(t_struct *d, char *str, int last)
{
	int	i;

	i = 1;
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
		execve(str, d->l.arg_chev, d->my_envp);
	}
	waitpid(g_global.g_kill_pid, &g_global.g_build_error_exec, 0);
}

char	*ft_init_exec_chev(t_struct *d, t_list *l)
{
	char	*str;
	char	*tmp;

	if (get_pos_env(l, "PATH") != -1)
	{
		str = get_binaire(d);
		tmp = ft_strdup(str);
		free_str(str);
		str = ft_strjoin(tmp, d->l.cmd);
		free_str(tmp);
		return (str);
	}
	return (ft_strdup("ERROR"));
}
