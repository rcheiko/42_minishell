NAME		=	minishell

SRCS		=	minishell.c \
				minishell_2.c \
				ft_utils.c \
				ft_utils2.c \
				ft_utils3.c \
				ft_utils4.c \
				ft_utils5.c \
				ft_utils6.c \
				ft_utils7.c \
				ft_utils8.c \
				ft_utils9.c \
				ft_utils10.c \
				ft_utils11.c \
				ft_utils12.c \
				ft_utils13.c \
				ft_utils14.c \
				ft_utils15.c \
				ft_utils16.c \
				ft_utils17.c \
				ft_utils18.c \
				ft_utils19.c \
				ft_utils20.c \
				ft_utils21.c \
				ft_utils22.c \
				ft_utils23.c \
				ft_utils24.c \
				ft_parsing.c \
				ft_parsing_2.c \
				ft_pars_chev.c \
				ft_pars_chev2.c \
				ft_redir.c \
				ft_redir2.c \
				ft_redir3.c \
				ft_redir4.c \
				ft_redir5.c \
				ft_redir6.c \
				ft_redir7.c \
				ft_redir8.c \
				ft_redir9.c \
				ft_redir10.c \
				ft_env.c \
				ft_env2.c \
				ft_env3.c \
				ft_exp_unset.c \
				ft_exp_unset2.c \
				ft_exp_unset3.c \
				ft_exp_unset4.c \
				ft_exec_builtin.c \
				ft_exec_builtin2.c \
				ft_init.c \
				ft_absolut_path.c \


OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I./includes

LINKFLAGS	=	-lreadline -lncurses ./libreadline.a

RM			=	rm -f

all:			${NAME}

$(NAME):		${OBJS}
				${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LINKFLAGS}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all
