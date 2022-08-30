#include "minishell.h"

void	built_in_export(t_struct *d, t_list *l, t_list *exp)
{
	int		i;
	int		j;
	t_elem	*count;

	count = l->first;
	d->l.str1 = NULL;
	i = 1;
	j = -1;
	while (d->l.arg[i])
	{
		if (isin('=', d->l.arg[i]) == 1)
			built_in_export_10(d, l, count, i);
		i++;
	}
	built_in_export_2(d, exp);
}

void	built_in_export_4(t_struct *d, int i)
{
	printf("bash: export: `%s': not a valid identifier\n", d->l.arg[i]);
	g_global.g_build_error_exec = 1;
}

void	built_in_export_3(t_struct *d, t_list *l, t_elem *count, int i)
{
	built_in_export_6(d, l, count, i);
	if (isin('\"', d->l.arg[i]) == 1)
	{
		d->l.str1 = ft_strtrim(d->l.arg[i], "\"");
		pushfront_one(l, d->l.str1);
	}
	else if (isin('\'', d->l.arg[i]) == 1)
	{
		d->l.str1 = ft_strtrim(d->l.arg[i], "\'");
		pushfront_one(l, d->l.str1);
	}
	else if (is_char_c(d->l.arg[i][0]) == 0)
		built_in_export_4(d, i);
	else if (get_pos_env(l, d->l.arg[i]) == -1)
		pushfront_one(l, ft_strdup(d->l.arg[i]));
}

void	built_in_export_1(t_struct *d, t_list *l, t_elem *count, int i)
{
	int	j;
	int	k;

	j = -1;
	d->l.str1 = del_plus_egal(d->l.arg[i]);
	if (is_in_env(l, d->l.str1) == 1)
	{
		k = get_pos_env(l, d->l.str1);
		while (++j < k)
			count = count->next;
		free_str(d->l.str1);
		d->l.str1 = ft_substr(d->l.arg[i], d->l.pos + 1,
				ft_strlen(d->l.arg[i]));
		d->l.tmp = ft_strdup(count->data);
		free_str(count->data);
		count->data = cat_export(d->l.tmp, d->l.str1);
		free_str(d->l.str1);
		free_str(d->l.tmp);
	}
	else if (is_char_c(d->l.arg[i][0]) == 0)
		built_in_export_4(d, i);
	else
		pushfront_one(l, d->l.str1);
}

void	built_in_export_2(t_struct *d, t_list *exp)
{
	int		i;

	i = 1;
	d->l.str1 = NULL;
	while (d->l.arg[i])
	{
		if (isin('=', d->l.arg[i]) == 0)
			built_in_export_11(d, exp, i);
		i++;
	}
}
