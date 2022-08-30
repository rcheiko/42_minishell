#include "minishell.h"

int	s_chevron_right(t_struct *d, int i)
{
	int		fd0;

	fd0 = open(d->l.chetab[i], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	return (fd0);
}

int	d_chevron_right(t_struct *d, int i)
{
	int		fd0;

	fd0 = open(d->l.chetab[i], O_APPEND | O_CREAT | O_RDWR, 0777);
	return (fd0);
}

int	s_chevron_left(t_struct *d, int i)
{
	int		fd0;

	fd0 = open(d->l.chetab[i], O_RDWR, 0777);
	if (fd0 == -1)
	{
		printf("bash: %s: No such file or directory\n", d->l.chetab[i]);
		return (-1);
	}
	return (fd0);
}

int	d_chevron_left(t_struct *d, int i)
{
	char	*str2;
	int		fd;

	str2 = NULL;
	d->l.buf = NULL;
	fd = open(d->l.chetab[i], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	while (1)
	{
		d->l.buf = NULL;
		d->l.buf = readline("> ");
		if (d->l.buf == NULL || ft_strcmp(d->l.buf, d->l.chetab[i]) == 0)
		{
			d->l.buf = NULL;
			break ;
		}
		write(fd, d->l.buf, ft_strlen(d->l.buf));
		write(fd, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
	close(fd);
	fd = open(d->l.chetab[i], O_CREAT | O_RDWR, 0777);
	unlink(d->l.chetab[i]);
	return (fd);
}
