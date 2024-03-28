/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:33:21 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/03/28 08:26:05 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_images
{
	void	*wall;
	void	*floor;
	void	*exite;
	void	*collect;
	void	*player;
}					t_images;

typedef struct s_ecp
{
	int		i;
	int		j;
	int		c;
	int		e;
	int		p;
}					t_ecp;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	char			**map;
	int				height;
	int				width;
	int				p_x;
	int				p_y;
	int				collect;
	int				exitss;
	int				move;
	char			*file;
}					t_data;

typedef struct s_all
{
	t_data		*data;
	t_images	*images;
}				t_all;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		ft_strchr(const char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
char	**readmap(char *file, t_data *data);
char	**ft_split(char const *s, char c);
void	parssing(t_data *data);
void	put_map(t_data *data, t_images *images);
void	xpm_to_img(t_images *images, t_data *data);
int		player_movement(int keycode, t_all *all);
void	up(t_all *all, int i, int j);
void	down(t_all *all, int i, int j);
void	left(t_all *all, int i, int j);
void	right(t_all *all, int i, int j);
void	check_exit(t_all *all, int i, int j);
void	check_fd(int fd);
void	p_x_y(t_data *data);
int		close_game(t_all *all);
int		esc(t_all *all);
void	flood_fill(t_data *data, int i, int j);
void	init(t_ecp *ecp);
int		ft_printf(const char *str, ...);
int		ft_putnbr(int num);
int		ft_printf_char(int i);
void	check_file_extention(char *file);

#endif
