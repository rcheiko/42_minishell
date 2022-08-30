#include "minishell.h"

void	handle_sigquit(int sig)
{
	if (sig == SIGQUIT && g_global.g_status == 2)
	{
		printf("Quit: 3\n");
		g_global.g_build_error_exec = 131;
	}
	else if (sig == SIGQUIT)
	{
		printf("\e[0K");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handler(int sig)
{
	(void)sig;
	exit (130);
}

void	init_lch(t_list *lst, char *str)
{
	t_elem	*new;

	new = malloc(sizeof (t_elem));
	if (!new)
		exit(0);
	new->data = ft_strdup(str);
	new->prec = NULL;
	new->next = NULL;
	lst->first = new;
	lst->last = new;
}

void	signall(void)
{
	if (g_global.g_kill_pid != 0)
	{
		kill(g_global.g_kill_pid, SIGTERM);
		printf("\e[2D\e[0K\e[50D>\n");
	}
	else
		exit (0);
	rl_on_new_line();
	rl_replace_line("", 0);
}

void	handle_sigint(int sig)
{
	(void)sig;
	if (g_global.g_status == 0)
	{
		g_global.g_build_error_exec = 1;
		printf("\e[0K\e[1K");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		write(1, "\nMinishell% ", 12);
	}
	else if (g_global.g_status == 1)
		signall();
	else if (g_global.g_status == 2)
	{
		g_global.g_status = 100;
		write(1, "\n", 1);
	}
}
