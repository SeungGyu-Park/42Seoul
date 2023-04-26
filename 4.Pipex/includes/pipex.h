/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunggpa <seunggpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 04:47:40 by seunggpa          #+#    #+#             */
/*   Updated: 2022/06/29 05:06:21 by seunggpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <sys/wait.h>

void			error(char *s);
size_t			ft_strlen(const char *a);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dsize);
void			ft_putstr_fd(char *s, int fd);
void			execute(char *argv, char **envp);
void			free_paths(char **paths);
char			**find_cmd(char **envp);
int				check_access(char *cmd);
void			child_proc(char **argv, char **envp, int *fd);
void			parent_proc(char **argv, char **envp, int *fd);
char			*ft_strjoin(char const *s1, char const *s2);

char			**ft_split(char const *s, char c);
void			error_cmd(char *s, char **cmd);
char			*find_path_strjoin(char **paths, int i, char **cmd);
char			**ft_find_path_utils(char **envp, char **cmd);
char			*find_path(char **cmd, char **envp);

#endif
