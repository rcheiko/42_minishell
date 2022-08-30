#include "minishell.h"

void	ft_final_free(t_struct *d)
{
	if (is_chevron(d))
	{
		free_char_tab(d->l.chev_tab);
		free_char_tab(d->l.chetab);
		free_char_tab(d->l.chetab_cd);
		free_char_tab(d->l.arg_chev);
	}
	free_str(d->l.line);
	free_str(d->l.line2);
	free_char_tab(d->l.arg);
	free_str(d->l.cmd);
	free_str(d->l.echo);
}

void	exit_no_line(t_struct *d)
{
	printf("\e[F");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	printf("exit\n");
	close(STDIN_FILENO);
	free_str(d->l.line);
	exit(0);
}

int	main(int ac, char **av, char **envp)
{
	t_struct	d;
	t_list		l;
	t_list		exp;

	(void)av;
	(void)ac;
	minishell(envp, &d, &l, &exp);
	return (0);
}
