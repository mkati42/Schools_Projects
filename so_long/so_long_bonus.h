/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:49:31 by mkati             #+#    #+#             */
/*   Updated: 2023/06/06 16:31:48 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include	"./mlx/mlx.h"
# include	<fcntl.h>
# include	"./gnl/get_next_line.h"
# include	"./libft/libft.h"
# include	"./printf/ft_printf.h"

# define GROUND "xpms/others/ground.xpm"
# define WALL "xpms/others/wall.xpm"
# define COIN "xpms/knife/knife1.xpm"
# define COIN2 "xpms/knife/knife2.xpm"
# define EXIT "xpms/others/exit.xpm"
# define FOE_R "xpms/others/enemy_right.xpm"
# define FOE_L "xpms/others/enemy_left.xpm"
# define P_RIGHT "xpms/right/right.xpm"
# define P_RIGHTB "xpms/right/right_breath.xpm"
# define P_LEFT "xpms/left/left.xpm"
# define P_LEFTB "xpms/left/left_breath.xpm"
# define SIZE 128
# define RED 0XFF0000
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
	char	**map;
	int		p_count;
	int		e_count;
	int		c_count;
	int		f_count;
	int		exit_count;
	int		collect_count;
	int		line_count;
	int		column_count;
	int		line_len;
}		t_map;

typedef struct s_img
{
	void	*knife1;
	void	*knife2;
	void	*foe_r;
	void	*foe_l;
	void	*p_right;
	void	*p_rightb;
	void	*p_left;
	void	*p_leftb;
	void	*img_e;
	void	*img_p;
	void	*img_c;
	void	*img_g;
	void	*img_w;
	int		w;
	int		h;
}		t_img;

typedef struct s_data
{
	char	**c_map;
	void	*mlx;
	void	*win;
	int		coin_s;
	int		play_s;
	int		play_f;
	int		f_flag;
	int		p_i;
	int		p_j;
	int		f_i;
	int		f_j;
	int		e_i;
	int		e_j;
	int		i;
	int		j;
	int		step_count;
	char	*step_c;
	int		window_h;
	int		window_w;
	t_map	map_data;
	t_img	img;
}		t_data;

void	error_messages_bonus(char *error_message);
void	file_name_control_bonus(char *path);
void	control_count_bonus(t_data *data);
void	control_count_bonus(t_data *data);
void	cmap_count_control_bonus(t_data *data, int i, int j);
void	point_put_bonus(t_data *data, int i, int j);
void	c_map_create_bonus(char *path, t_data *data,
			int line_count, int column);
void	valid_map_bonus(char *path, t_data *data);
void	create_map_bonus(char *path, t_data *data);
void	real_crtmap_bonus(char *path, t_data *data, int line_count, int column);
void	data_mapn_img_bonus(t_data *data);
void	foe_data_bonus(t_data *data);
void	player_data_bonus(t_data *data);
void	close_window_bonus(t_data *data);
void	win_game_bonus(int x, int y, t_data *data);
void	move_control_bonus(int x, int y, t_data *data);
void	foe_put_img_bonus(t_data *data);
void	foe_put_img_bonus2(t_data *data, int column, int i);
void	player_put_img_bonus(t_data *data, int column, int i);
void	coin_put_img_bonus(t_data *data, int column, int i);
int		render_window_bonus(t_data *data);
void	my_xpm_put_window_bonus(t_data *data, int i, int column, int j);
void	my_xpm_to_file_bonus(void *mlx, t_data *data);
int		count_char_bonus(t_data *data);
int		all_line_bonus(t_data *data);
int		wall_control_bonus(int line_count, char **map);
int		control_topn_bot_bonus(int line, char **map);
int		map_line_count_bonus(char *path, int line_count);
int		close_hook_bonus(t_data *data);
int		moves_hook_bonus(int keycode, t_data *data);
void	count_flag_second(t_data *data);
void	lose_control(t_data *data);
void	write_step_bonus(t_data *data);
void	xpm_control_bonus(void);
void	xpm_control2_bonus(void);
void	xpm_control3_bonus(void);

#endif