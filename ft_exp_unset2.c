#include "minishell.h"

void	built_in_export_chev(t_struct *d, t_list *l, t_list *exp)
{
	int		i;
	int		j;
	t_elem	*count;

	count = l->first;
	i = 1;
	j = 0;
	d->l.res = ft_split(d->l.chetab[0], ' ');
	while (d->l.res[i] && isin('=', d->l.res[i]) == 1)
	{
		d->l.pos = ft_strlen_egal(d->l.res[i]);
		if (ft_strlen_egal(d->l.res[i]) >= 2
			&& d->l.res[i][d->l.pos - 1] == '+')
			built_in_export_chev_1(d, l, count, i);
		else if (ft_strlen_egal(d->l.res[i]) >= 1 && d->l.res[i][0] != '+')
			built_in_export_chev_2(d, l, count, i);
		else
		{
			printf("bash: export: `%s': not a valid identifier\n", d->l.res[i]);
			g_global.g_build_error_exec = 1;
		}
		i++;
	}
	built_in_export_chev_4(d, exp);
	free_char_tab(d->l.res);
}

void	built_in_export_chev_3(t_struct *d, int i)
{
	printf("bash: export: `%s': not a valid identifier\n", d->l.res[i]);
	g_global.g_build_error_exec = 1;
}

void	built_in_export_chev_4(t_struct *d, t_list *exp)
{
	int		i;

	i = 1;
	while (d->l.res[i] && isin('=', d->l.res[i]) == 0)
	{
		if (is_char_c(d->l.res[i][0]) == 0)
		{
			g_global.g_build_error_exec = 1;
			printf("bash: export: `%s': not a valid identifier\n", d->l.res[i]);
		}
		else if (check_char(d->l.res[i]) == 1)
		{
			g_global.g_build_error_exec = 1;
			printf("bash: export: `%s': not a valid identifier\n", d->l.res[i]);
		}
		else
		{
			if (get_pos_env_exp(exp, d->l.res[i]) == -1)
			{
				d->l.str1 = cat_export("declare -x ", d->l.res[i]);
				pushfront(exp, d->l.str1);
			}
		}
		i++;
	}
}

void	built_in_export_chev_1(t_struct *d, t_list *l, t_elem *count, int i)
{
	int	j;
	int	k;

	j = -1;
	d->l.str1 = del_plus_egal(d->l.res[i]);
	if (is_in_env(l, d->l.str1) == 1)
	{
		k = get_pos_env(l, d->l.str1);
		while (++j < k)
			count = count->next;
		free_str(d->l.str1);
		d->l.str1 = ft_substr(d->l.res[i], d->l.pos + 1,
				ft_strlen(d->l.res[i]));
		d->l.tmp = ft_strdup(count->data);
		free_str(count->data);
		count->data = cat_export(d->l.tmp, d->l.str1);
		free_str(d->l.str1);
		free_str(d->l.tmp);
	}
	else if (is_char_c(d->l.res[i][0]) == 0)
		built_in_export_chev_3(d, i);
	else
		pushfront_one(l, d->l.str1);
}

void	built_in_export_chev_2(t_struct *d, t_list *l, t_elem *count, int i)
{
	int	j;
	int	k;

	j = -1;
	if (is_in_env(l, d->l.res[i]) == 1)
	{
		k = get_pos_env(l, d->l.res[i]);
		while (++j < k)
			count = count->next;
		count->data = d->l.res[i];
	}
	else if (isin('\"', d->l.res[i]) == 1)
	{
		d->l.str1 = ft_strtrim(d->l.res[i], "\"");
		pushfront_one(l, d->l.str1);
	}
	else if (isin('\'', d->l.res[i]) == 1)
	{
		d->l.str1 = ft_strtrim(d->l.res[i], "\'");
		pushfront_one(l, d->l.str1);
	}
	else if (is_char_c(d->l.res[i][0]) == 0)
		built_in_export_chev_3(d, i);
	else
		pushfront_one(l, ft_strdup(d->l.res[i]));
}
