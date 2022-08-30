#include "minishell.h"

void	built_in_unset(t_struct *d, t_list *l, t_list *exp)
{
	int		k;
	int		j;
	int		i;

	i = 1;
	while (d->l.arg[i])
	{
		k = get_pos_env(l, d->l.arg[i]);
		j = get_pos_env_exp(exp, d->l.arg[i]);
		if (is_char_c(d->l.arg[i][0]) == 0)
		{
			printf("bash: unset: `%s': not a valid identifier\n", d->l.arg[i]);
			g_global.g_build_error_exec = 1;
		}
		else if (check_char(d->l.arg[i]) == 1)
		{
			printf("bash: unset: `%s': not a valid identifier\n", d->l.arg[i]);
			g_global.g_build_error_exec = 1;
		}
		if (j >= 0)
			del_cell(exp, j);
		if (k >= 0)
			del_cell(l, k);
		i++;
	}
}

void	built_in_unset_chev(t_struct *d, t_list *l)
{
	int		k;
	int		i;
	char	**str;

	i = 1;
	str = ft_split(d->l.chetab[0], ' ');
	while (str[i])
	{
		k = get_pos_env(l, str[i]);
		if (is_char_c(d->l.arg[i][0]) == 0)
		{
			printf("bash: unset: `%s': not a valid identifier\n", d->l.arg[i]);
			g_global.g_build_error_exec = 1;
		}
		else if (check_char(d->l.arg[i]) == 1)
		{
			printf("bash: unset: `%s': not a valid identifier\n", d->l.arg[i]);
			g_global.g_build_error_exec = 1;
		}
		else if (k != 0)
			del_cell_nofree(l, k);
		i++;
	}
	free_char_tab(str);
}

void	built_in_export_5(t_struct *d, t_list *exp, int i)
{
	if (get_pos_env_exp(exp, d->l.arg[i]) == -1)
	{
		d->l.str1 = cat_export("declare -x ", d->l.arg[i]);
		pushfront_one(exp, d->l.str1);
	}
}

void	built_in_export_6(t_struct *d, t_list *l, t_elem *count, int i)
{
	int	j;
	int	k;

	j = -1;
	if (is_in_env(l, d->l.arg[i]) == 1)
	{
		k = get_pos_env(l, d->l.arg[i]);
		while (++j < k)
			count = count->next;
		free_str(count->data);
		count->data = ft_strdup(d->l.arg[i]);
	}
}
