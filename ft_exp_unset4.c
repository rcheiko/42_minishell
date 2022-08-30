#include "minishell.h"

void	built_in_export_10(t_struct *d, t_list *l, t_elem *count, int i)
{
	d->l.pos = ft_strlen_egal(d->l.arg[i]);
	if (ft_strlen_egal(d->l.arg[i]) >= 2
		&& d->l.arg[i][d->l.pos - 1] == '+')
		built_in_export_1(d, l, count, i);
	else if (ft_strlen_egal(d->l.arg[i]) >= 1 && d->l.arg[i][0] != '+')
		built_in_export_3(d, l, count, i);
	else
	{
		printf("bash: export: `%s': not a valid identifier\n", d->l.arg[i]);
		g_global.g_build_error_exec = 1;
	}
}

void	built_in_export_11(t_struct *d, t_list *exp, int i)
{
	if (is_char_c(d->l.arg[i][0]) == 0)
	{
		g_global.g_build_error_exec = 1;
		printf("bash: export: `%s': not a valid identifier\n", d->l.arg[i]);
	}
	else if (check_char(d->l.arg[i]) == 1)
	{
		g_global.g_build_error_exec = 1;
		printf("bash: export: `%s': not a valid identifier\n", d->l.arg[i]);
	}
	else
		built_in_export_5(d, exp, i);
}
