/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:48:49 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/22 13:32:17 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct			s_lst
{
	char				map;

	int					h;
	int					w;
	int					x;
	int					y;
	int					nul;
	struct s_lst		*next;
}						t_lst;

t_lst					*ft_list_new(char *map);
t_lst					*ft_list_pushback(t_lst **beg, char *map);
void					ft_list_delone(t_lst **to_del);
void					ft_list_del(t_lst **beg);
int						ft_list_size(t_lst *beg);

char					**ft_map_dup(char **map);
void					*ft_arrncpy(long long *dst,
									long long *src, int i, int n);
void					ft_map_del(char **map);
int						ft_find_coordinate(char *tetr, int *h, int *w);
char					ft_map_create(char *map, int coord, int h, int w);
int						ft_print_map(t_lst *tetr, int size);

int						ft_solver(t_lst *tetramino);
int						ft_try_to_solve(t_lst *tetr, long long *map, int size);

int						ft_sqrt(int n);
void					ft_strdel(char **as);
char					*ft_strndup(const char *s1, size_t n);
void					*ft_memset(void *b, int c, size_t len);
char					*ft_strnew(size_t size);

int						ft_is_tetramino_valid(char *cur, int iter);
int						ft_usage_file(void);
int						ft_error_msg(int fd);
int						ft_is_map_valid(char *buff, int res1);
t_lst					*ft_map_reader(int fd, t_lst **tetramino);

#endif
