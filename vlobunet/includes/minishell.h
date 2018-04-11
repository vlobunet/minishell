/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:17:25 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 18:17:26 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <signal.h>
# include <unistd.h>

char **g_env;

# define C_RESET		"\033[0m"
# define C_ERROR		"\033[0;31m"
# define C_GREEN		"\033[1;32m"
# define C_YELLO		"\033[1;33m"
# define C_SINIY		"\033[1;34m"
# define C_FIOLE		"\033[1;35m"
# define C_GOLYB		"\033[0;36m"
# define C_ROZOV		"\033[0;37m"

# define BUFF_SIZE 4096

typedef struct		s_param
{
	int				e;
	int				b;
	int				n;
	int				flag;
}					t_param;

char				*ft_scanf(int fd);
char				*ft_get_env_var(char *str);
void				ft_print_message(void);
void				ft_get_env(char **env);
void				ft_get_cmd(char *str);
char				**ft_split(char *str);
char				**realloc_envv(int size);
int					get_next_line(const int fd, char **line);
char				*set_str(char *src);
char				*ft_resize(char buff, char *s1);
void				error_cat_1(int n, char **atribut);
int					print_str_fd(char *str, int fd, t_param *lst_pr, int i);
int					print_file_fd(t_param *lst_pr, char *f_name, int i, int fd);
int					cheack_file_name(char *cmd_attr);
int					ft_pars_param(char *cmd_attr, t_param *lst_pr);
void				echo_src1(char **atribut, int fd1, int flag, int n);
void				echo_src2(char **atribut, int fd1, int flag, int n);
int					ft_ch_sumb(char *str, char s);

void				run_exit(void);
void				run_setenv(char *str);
void				run_set(char *cmd_attr0, char *cmd_attr1);
void				run_unsetenv(char *str);
void				run_env(char *str);
void				run_echo(char *str);
void				run_cat(char *cmd_attr);
void				run_getenv(char *atribut);
void				run_cd(char *cmd);
void				run_info(void);
void				exec_cmd(char *name, char *str_atr);
char				*run_get_env(char *env);

void				run_man(char *cmd_atr);
int					man_echo(void);
int					man_cd(void);
int					man_cat(void);
int					man_unsetenv(void);
int					man_getenv(void);

void				ft_freestrarr(char **arr);
void				error_setenv(int i);
void				error_unset(char *str);
void				error_command(char *name);
void				error_arg(char arg);
void				error_file(char *arg);
void				sintax_error(void);

#endif
