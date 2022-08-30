#include "minishell.h"

void	ft_init(char **envp, t_list *exp, t_list *l, t_struct *d)
{
	init(l);
	init_struct(d);
	fill_env(d, envp);
	fill_env_struct(envp, l);
	update_my_envp(d, l);
	env_export(envp, exp);
	export_env_declare(exp);
	alphabetic_order(exp);
	del_cell(exp, 22);
}
