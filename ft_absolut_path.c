#include "minishell.h"

int	ft_path(t_struct *d)
{
	if (d->l.cmd[0] == '/' && (check_charset(d->l.cmd, "bin") == 1
			|| check_charset(d->l.cmd, "User") == 1))
	{
		ft_exec_bin(d);
		return (1);
	}
	return (0);
}
