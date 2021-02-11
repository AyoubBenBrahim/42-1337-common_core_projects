/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:57:07 by ahel-men          #+#    #+#             */
/*   Updated: 2019/07/18 21:38:39 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "key_nd_mouse_codes.h"

typedef enum		e_bool
{
	False,
	True,
}					t_bool;

typedef struct		s_crd
{
	int				z1;
	int				z2;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				color;
}					t_crd;

typedef struct		s_list2
{
	int				count;
	int				cart_x;
	int				cart_y;
	int				z;
	int				color;
	struct s_list2	*next;
}					t_list2;

typedef struct		s_stock
{
	int				i;
	int				x;
	int				count;
	int				*x_ligne;
	int				x_nb;
	char			**tab;
}					t_stock;

typedef struct		s_bres
{
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				swap;
	int				temp;
	int				s1;
	int				s2;
	int				p;
}					t_bres;

typedef struct		s_option
{
	t_bool			iso;
	t_bool			rotation;
	int				zoom;
	int				absc;
	int				ordn;
	void			*mlx;
	void			*win;
	int				color;
	int				z;
	float			anglex;
	t_list2			*head;
	int				keycod;
	int				count;
	int				win_x;
	int				win_y;
}					t_option;

void				draw_line(t_option *opt, t_crd coord);
t_list2				*read_file(int fd, t_option *opt);
void				destroy_leaks(t_option *t_opt);
int					ft_parse(char *str, t_list2 **tmp,
					t_option *opt);
void				draw(t_list2 *head, t_option *opt);
int					mouse_press(int button, int x, int y, t_option *param);
int					key_press(int keycode, t_option *opt);
void				ft_option_init(t_option *option, void *mlx, void *win);
void				menu(t_option *opt);
int					sign(int x);
void				ft_rotate(t_crd *coord, t_option *opt);
void				projection(int *x, int *y, int *z, t_option *opt);
int					check_file(char **tab);
void				string_put(t_option *opt, char *str);

#endif
