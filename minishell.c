#include "minishell.h"

void	minishell(char **envp, t_struct *d, t_list *l, t_list *exp)
{
	ft_init(envp, exp, l, d);
	while (1)
	{
		g_global.g_status = 0;
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		d->l.line = readline("Minishell% ");
		d->l.chev_echo = 0;
		check_q(d);
		signal(SIGQUIT, handle_sigquit);
		if (d->l.line == NULL)
			exit_no_line(d);
		else
			minishell_2(d, l, exp);
		if (g_global.g_status == 2)
			g_global.g_build_error_exec = 131;
		if (g_global.g_status == 100)
			g_global.g_build_error_exec = 130;
		if (g_global.g_build_error_exec == 33280
			|| g_global.g_build_error_exec == 256)
			g_global.g_build_error_exec = g_global.g_build_error_exec % 255;
		ft_final_free(d);
	}
}

void	minishell_2(t_struct *d, t_list *l, t_list *exp)
{
	d->l.line2 = ft_strdup(d->l.line);
	if (d->l.line[0] != '\0')
		add_history(d->l.line);
	parsing_all(d, l);
	if (is_chevron(d))
	{
		if (d->l.chetab[0] && d->l.chetab[1])
		{
			if (is_builtin(d) == 1)
				is_chev_builtin(d, l, exp);
			else
				exec_mult_chev(d, l);
		}
		else
		{
			g_global.g_build_error_exec = 258;
			printf("bash: syntax error near unexpected token `newline'\n");
		}
	}
	else if (ft_path(d) == 1)
		;
	else if (is_builtin(d) == 1)
		no_chev_builtin(d, l, exp);
	else
		ft_pars(d, l);
}

void	no_chev_builtin(t_struct *d, t_list *l, t_list *exp)
{
	exec_builtin(d, l);
	exec_builtin_4(d, l);
	if (exec_builtin_2(d, l, exp) > 1)
		exit(g_global.g_build_error_exec);
	exec_builtin_3(d, exp);
}

void	is_chev_builtin(t_struct *d, t_list *l, t_list *exp)
{
	if (ft_strncmp(d->l.cmd, "export", 6) == 0)
		exec_export_chev_2(d, exp, l);
	else if (ft_strncmp(d->l.cmd, "unset", 5) == 0)
		exec_unset_chev(d, l);
	else if (ft_strncmp(d->l.cmd, "cd", 2) == 0)
		exec_cd_chev(d, l);
	else if (ft_strncmp(d->l.cmd, "env", 3) == 0)
		exec_env_chev(d, l);
	else if (ft_strncmp(d->l.cmd, "echo", 4) == 0)
		exec_echo_chev(d, l);
	else if (ft_strncmp(d->l.cmd, "exit", 4) == 0)
	{
		exec_exit_chev(d);
		exit(g_global.g_build_error_exec);
	}
	else if (ft_strncmp(d->l.cmd, "pwd", 3) == 0)
		exec_pwd_chev(d);
}
