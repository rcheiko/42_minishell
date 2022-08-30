#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

typedef struct g_global
{
	int	g_status;
	int	g_kill_pid;
	int	g_build_error_exec;
}				t_global;

t_global	g_global;

typedef struct s_lexer
{
	char	*line;
	char	*line2;
	char	*cmd;
	char	**arg;
	char	**expr;
	char	**arg_chev;
	int		ch_nb;
	char	*chevrons;
	char	**chev_tab;
	char	**res;
	char	**chetab;
	char	**chetab_cd;
	char	*echo;
	char	*teub;
	int		i;
	int		j;
	int		k;
	char	*bin;
	char	*tmp;
	char	*buf;
	char	*str1;
	int		pos;
	int		fd;
	int		fd2;
	int		fd3;
	char	*env;
	char	*tmp2;
	char	*sub;
	int		i_e;
	int		c;
	char	**ec;
	int		echo_n;
	int		len;
	int		chev_echo;
}				t_lexer;

typedef struct s_struct
{
	char	**env;
	char	**str;
	char	**cd;
	char	**path;
	char	**my_envp;
	char	*line;
	int		cpt_string;
	t_lexer	l;
}				t_struct;

typedef struct s_elem
{
	char			*data;
	struct s_elem	*next;
	struct s_elem	*prec;
}				t_elem;

typedef struct s_list
{
	t_elem		*last;
	t_elem		*first;
}				t_list;

char	*ft_itoa(t_struct *d, int num);
int		len(long nb);
void	rl_replace_line(const char *text, int clear_undo);
void	ft_swap(char **a, char **b);
void	alphabetic_order(t_list *l);
char	*ft_init_exec_chev(t_struct *d, t_list *l);
int		is_builtin(t_struct *d);
int		is_set(char c, char *set);
void	del_cell(t_list *l, int index);
void	del_cell_nofree(t_list *l, int index);
void	pushfront(t_list *l, char *val);
int		ft_strlcpy(char *dst, char *src, int size);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, int len);
void	modify_pwd(t_struct *d, t_list *l);
void	modify_old_pwd(t_struct *d, t_list *l);
void	modify_pwd_2(t_struct *d, t_list *l, char *pp, char *res);
void	update_my_envp(t_struct *d, t_list *l);
int		is_in_env(t_list *l, char *str);
void	init(t_list *l);
void	pushfront_one(t_list *l, char *val);
char	*ft_strtrim(char *s1, char *set);
int		isin(char c, char *str);
int		check_charset(char *str, char *charset);
char	ft_isdigit(int c);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strcat(char *dest, char *src);
int		count_word(const char *str, char c);
char	*tab_malloc(const char *str, char c);
char	**ft_split(char const *s, char c);
char	**ft_split1(char *str, char *charset);
int		ft_len_wspa(char *str);
void	ft_strcpy_wspa(char *src, char *dest);
void	del_space_start(t_struct *d);
int		ft_len_wspa_end(char *str);
void	ft_strcpy_wspa_end(char *src, char *dest);
void	del_space_end(t_struct *d);
char	*cpy_until_space(char *str);
void	cpy_cmd(t_struct *d);
int		count_arg(char *str);
int		index_tiret(t_struct *d, int k);
int		index_tiret_chev(t_struct *d, int k);
void	mal_cpy_echo(t_struct *d);
void	mal_cpy_echo_chev(t_struct *d);
int		find_str_echo(t_struct *d);
int		find_str_echo_chev(t_struct *d);
int		find_str_echo_1(t_struct *d, int j, int tiret);
int		find_str_echo_1_chev(t_struct *d, int j, int tiret);
void	parsing_echo_chev(t_struct *d, t_list *l);
void	ft_putchar(char c);
void	del_space_start_echo(t_struct *d);
void	handle_sigint(int sig);
void	handle_sigquit(int sig);
int		ft_strlen_int(char *str);
void	init_lch(t_list *lst, char *str);
void	push_frontlst(t_list *lst, char *str);
void	afflst(t_list *lst);
void	afflst_n(t_list *lst);
int		ft_putchar_int(int c);
int		ft_strlen_egal(char *str);
int		ft_lstsize(t_list *l);
void	afflst_back(t_list *exp);
void	search_dolenv(t_list *l, char *str);
void	expand_dol_l(t_struct *d, t_list *l);
char	*search_env(t_list *l, char *str);
char	*search_env_2(t_elem *courant, char *str, int tmp, int mal);
void	real_line_dol(t_struct *d, char *res);
void	real_line_dol_2(t_struct *d, int i, int cpt);
int		len_line_dol(t_struct *d);
int		len_line_fdol(t_struct *d);
int		mal_del_quote(t_struct *d, char *str);
char	*del_quote(t_struct *d, char *str);
void	quote_arg(t_struct *d);
char	*ft_strjoin(char *s1, char *s2);
int		get_pos_env(t_list *l, char *str);
void	ft_init(char **envp, t_list *exp, t_list *l, t_struct *d);
int		ft_path(t_struct *d);
void	del_space_start_che(t_struct *d);
void	del_space_end_che(t_struct *d);
char	*ft_strcat_malloc(char *dest, char *src);
int		aff_env_memb(t_struct *d, t_list *l);
void	handler_exit(int sig);
void	handler(int sig);
char	*get_binaire_3(void);
char	*cat_export(char *dest, char *src);
int		ft_strlen_minus(char *str);
int		is_char_c(char c);
int		search_space(t_struct *d);
int		search_space_cd(t_struct *d);
void	ft_pars(t_struct *d, t_list *l);
void	ft_pars_2(t_struct *d, t_list *l, char *str, int pid);
void	ft_pars_3(t_struct *d);
void	ft_exec_bin(t_struct *d);
char	*add_bin(t_struct *d);
void	parsing_all(t_struct *d, t_list *l);
void	parsing_all_2(t_struct *d, char *line);
int		is_chevron(t_struct *d);
int		is_chevron2(t_struct *d, int i);
void	che_to_tab(t_struct *d);
void	chev_count(t_struct *d);
void	fill_chevron(t_struct *d);
int		fill_chevron_2(t_struct *d, int i, int j, char *tmp);
void	fill_chevron_3(t_struct *d, int i, int j, char *tmp);
void	env_export(char **envp, t_list *l);
void	export_env_declare(t_list *l);
void	exec_builtin(t_struct *d, t_list *l);
int		exec_builtin_2(t_struct *d, t_list *l, t_list *exp);
void	exec_builtin_3(t_struct *d, t_list *exp);
void	exec_builtin_4(t_struct *d, t_list *l);
void	exec_builtin_5(t_struct *d, t_list *l, t_list *exp, char *bufcwd);
int		chev_right_pos(t_struct *d);
void	free_str(char *str);
void	free_char_tab(char **str);
int		is_char(char *str);
int		exit_arg(t_struct *d);
int		ft_strlen_twochar(char **str);
char	*del_plus_egal(char *str);
int		find_str_echo_2_chev(t_struct *d, int j);
int		check_char(char *str);
void	check_echo_quote(t_struct *d, t_list *l);
int		ft_strlen_dol(char *str);
int		ft_strlen_dquote(char *str);
int		get_pwd_pos(t_list *l);
int		get_oldpwd_pos(t_list *l);
void	fill_env(t_struct *d, char **envp);
void	fill_env_struct(char **envp, t_list *l);
void	built_in_export(t_struct *d, t_list *l, t_list *exp);
void	built_in_export_2(t_struct *d, t_list *exp);
void	built_in_export_1(t_struct *d, t_list *l, t_elem *counit, int i);
void	built_in_export_3(t_struct *d, t_list *l, t_elem *counit, int i);
void	built_in_export_6(t_struct *d, t_list *l, t_elem *counit, int i);
void	built_in_export_4(t_struct *d, int i);
void	built_in_export_5(t_struct *d, t_list *exp, int i);
void	built_in_export_10(t_struct *d, t_list *l, t_elem *count, int i);
void	built_in_export_11(t_struct *d, t_list *exp, int i);
void	built_in_export_chev(t_struct *d, t_list *l, t_list *exp);
void	built_in_export_chev_1(t_struct *d, t_list *l, t_elem *count, int i);
void	built_in_export_chev_2(t_struct *d, t_list *l, t_elem *count, int i);
void	built_in_export_chev_3(t_struct *d, int i);
void	built_in_export_chev_4(t_struct *d, t_list *exp);
void	built_in_unset_chev(t_struct *d, t_list *l);
void	built_in_unset(t_struct *d, t_list *l, t_list *exp);
void	fill_path(t_struct *d);
void	init_struct(t_struct *d);
void	view(t_list l);
void	minishell(char **envp, t_struct *d, t_list *l, t_list *exp);
void	minishell_2(t_struct *d, t_list *l, t_list *exp);
int		s_chevron_right(t_struct *d, int i);
int		d_chevron_right(t_struct *d, int i);
int		s_chevron_left(t_struct *d, int i);
int		d_chevron_left(t_struct *d, int i);
char	**ft_cmd_chev_left(t_struct *d, int i);
char	*get_binaire(t_struct *d);
char	*get_binaire_2(t_struct *d, int i);
int		exec_mult_chev(t_struct *d, t_list *l);
void	exec_mult_chev_2(t_struct *d, char *str, int last);
int		exec_chev_last(t_struct *d, int last, int fd, int fd2);
int		exec_chev_last_in(int fd, int fd2);
int		exec_chev_last_out(t_struct *d, int fd, int fd2);
void	exec_chev_nolast(t_struct *d, int i);
void	exec_chev_last_nodup(t_struct *d, int last);
void	exec_m_chev_buf(t_struct *d, char *str);
int		exec_pwd_chev(t_struct *d);
void	exec_pwd_chev_2(t_struct *d, char *str, int last, int i);
int		exec_cd_chev(t_struct *d, t_list *l);
void	exec_chev_last_in_bin(int fd);
void	exec_cd_chev_2(t_struct *d, t_list *l);
void	exec_cd_chev_3(t_struct *d, int i, int last);
void	exec_chev_last_binaire(t_struct *d, int last);
void	exec_chev_last_out_bin(t_struct *d, int fd);
int		exec_env_chev(t_struct *d, t_list *l);
void	exec_env_chev_2(t_struct *d, t_list *l, int i, int last);
void	exec_env_chev_3(t_list *l);
void	exec_export_chev(t_struct *d, t_list *exp, int last, int i);
int		exec_export_chev_2(t_struct *d, t_list *exp, t_list *l);
int		exec_unset_chev(t_struct *d, t_list *l);
void	exec_unset_chev_2(t_struct *d, int last, int pid);
int		exec_echo_chev(t_struct *d, t_list *l);
void	exec_echo_chev_2(t_struct *d, t_list *l);
void	exec_echo_chev_3(t_struct *d, t_list *l, int i, int last);
int		exec_exit_chev(t_struct *d);
void	exec_exit_chev_2(t_struct *d, int last, int i);
void	ft_final_free(t_struct *d);
void	exit_no_line(t_struct *d);
void	is_chev_builtin(t_struct *d, t_list *l, t_list *exp);
void	no_chev_builtin(t_struct *d, t_list *l, t_list *exp);
int		get_pos_env_exp(t_list *exp, char *str);
void	parsing_dol(t_struct *d, t_list *l);
void	parsing_dol_2(t_struct *d, t_list *l);
void	parsing_dol_3(t_struct *d);
void	parsing_dol_4(t_struct *d, t_list *l);
void	parsing_dol_5(t_struct *d, t_list *l);
void	parsing_dol_6(t_struct *d, t_list *l, int count);
void	parsing_dol_7(t_struct *d, t_list *l);
char	*cat_char_malloc(char *res, char c);
void	echo_parse_chev(t_struct *d);
void	echo_parse_n_chev(t_struct *d);
void	echo_parse(t_struct *d);
void	echo_parse_n(t_struct *d);
void	check_q(t_struct *d);
char	*check_q2(t_struct *d, int i, char *str);
void	check_q3(t_struct *d, int i, char *str);
#endif