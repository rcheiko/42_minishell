#include "minishell.h"

void	exec_m_chev_buf(t_struct *d, char *str)
{
	if (d->l.buf && d->l.buf[3] == 'q')
	{
		if (fork() == 0)
			execve(str, d->l.arg_chev, d->my_envp);
		waitpid(0, &g_global.g_build_error_exec, 0);
	}
}

int	exec_chev_last(t_struct *d, int last, int fd, int fd2)
{
	if (ft_strcmp(d->l.chev_tab[last - 1], "<<") == 0)
	{
		fd = d_chevron_left(d, last);
		fd2 = exec_chev_last_in(fd, fd2);
	}
	else if (ft_strcmp(d->l.chev_tab[last - 1], "<") == 0)
	{
		fd = s_chevron_left(d, last);
		if (fd == -1)
			exit (1);
		fd2 = exec_chev_last_in(fd, fd2);
	}
	else if (ft_strcmp(d->l.chev_tab[last - 1], ">") == 0)
	{
		fd = s_chevron_right(d, last);
		fd2 = exec_chev_last_out(d, fd, fd2);
	}
	else if (ft_strcmp(d->l.chev_tab[last - 1], ">>") == 0)
	{
		fd = d_chevron_right(d, last);
		fd2 = exec_chev_last_out(d, fd, fd2);
	}
	return (fd2);
}

void	exec_chev_nolast(t_struct *d, int i)
{
	if (ft_strncmp(d->l.chev_tab[i - 1], "<<", 2) == 0)
		d->l.fd3 = d_chevron_left(d, i);
	else if (ft_strcmp(d->l.chev_tab[i - 1], ">>") == 0)
		d_chevron_right(d, i);
	else if (ft_strcmp(d->l.chev_tab[i - 1], ">") == 0)
		s_chevron_right(d, i);
	else if (ft_strcmp(d->l.chev_tab[i - 1], "<") == 0)
	{
		d->l.fd3 = s_chevron_left(d, i);
		if (d->l.fd3 == -1)
			exit (1);
	}
}

int	exec_chev_last_in(int fd, int fd2)
{
	fd2 = dup2(fd, STDIN_FILENO);
	close(fd);
	return (fd2);
}

int	exec_chev_last_out(t_struct *d, int fd, int fd2)
{
	dup2(fd, STDOUT_FILENO);
	close(fd);
	fd2 = dup2(d->l.fd3, STDOUT_FILENO);
	close(d->l.fd3);
	return (fd2);
}
