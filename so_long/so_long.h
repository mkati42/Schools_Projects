/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:49:31 by mkati             #+#    #+#             */
/*   Updated: 2023/06/06 16:33:59 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	"./mlx/mlx.h"
# include	<fcntl.h>
# include	"./gnl/get_next_line.h"
# include	"./libft/libft.h"
# include	"./printf/ft_printf.h"

# define GROUND "xpms/others/ground.xpm"
# define WALL "xpms/others/wall.xpm"
# define COIN "xpms/knife/knife1.xpm"
# define EXIT "xpms/others/exit.xpm"
# define P_RIGHT "xpms/right/right.xpm"
# define SIZE 128
# define ERRORFD "Error!\nFd open error!"
# define ERRORALLOC "Error!\nAllocation error!"
# define ERRORPATH "Error!\nInvalid file or wrong path"
# define INVMAP	"Error!\nInvalid char count"
# define INVCHAR "Error!\nThere is not some character"
# define INVPLAYER "Error!\nThe number of players cannot be more than one"
# define ROWSERROR "Error!\nRows are not equal each other"
# define WALLERROR "Error!\nThere's something wrong with the walls dude"
# define VALIDERROR "Error!\nInvalid map.There are places that can't be reached."
# define NOXPM	"Error!\nThere is not some xpm"

typedef struct s_map
{
	int		p_count;
	int		e_count;
	int		c_count;
	int		exit_count;
	int		collect_count;
	int		line_count;
	int		column_count;
	int		line_len;
	char	**map;
}		t_map;

typedef struct s_img
{
	int		w;
	int		h;
	char	*c_img;
	void	*img_e;
	void	*img_p;
	void	*img_c;
	void	*img_g;
	void	*img_w;
}		t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			p_i;
	int			p_j;
	int			e_i;
	int			e_j;
	int			i;
	int			j;
	int			step_count;
	char		*step_c;
	int			window_h;
	int			window_w;
	char		**c_map;
	t_map		map_data;
	t_img		img;
}		t_data;

void	file_name_control(char *path);
int		map_line_count(char *path, int line_count);
void	create_map(char *path, t_data *data);
void	real_crtmap(char *path, t_data *data, int line, int column);
void	error_messages(char *error_message);
void	data_mapn_img(t_data *data);
void	control_count(t_data *data);
int		count_char(t_data *data);
int		all_line(t_data *data);
int		wall_control(int line_count, char **map);
int		control_topn_bot(int line, char **map);
void	player_data(t_data *data);
void	open_window(t_data *data);
void	my_xpm_put_window(t_data *data, int i, int column, int j);
void	my_xpm_to_file(void *mlx, t_data *data);
void	render_window(t_data *data);
int		moves_hook(int keycode, t_data *data);
void	move_control(int x, int y, t_data *data);
void	win_game(int x, int y, t_data *data);
void	close_window(t_data *data);
void	valid_map(char *path, t_data *data);
void	point_put(t_data *data, int i, int j);
void	c_map_create(char *path, t_data *data, int line_count, int column);
void	cmap_count_control(t_data *data, int i, int j);
int		close_hook(t_data *data);
void	write_step(t_data *data);
void	xpm_control(void);

#endif