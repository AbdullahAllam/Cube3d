#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	NoEventMask = 0L,
	KeyPressMask = 1L<<0,
	KeyReleaseMask = 1L<<1,
	ButtonPressMask	= 1L<<2,
	ButtonReleaseMask = 1L<<3,
	EnterWindowMask	= 1L<<4,
	LeaveWindowMask = 1L<<5,
	PointerMotionMask = 1L<<6,
	PointerMotionHintMask = 1L<<7,
	Button1MotionMask = 1L<<8,
	Button2MotionMask = 1L<<9,
	Button3MotionMask = 1L<<10,
	Button4MotionMask = 1L<<11,
	Button5MotionMask = 1L<<12,
	ButtonMotionMask = 1L<<13,
	KeymapStateMask = 1L<<14,
	ExposureMask = 1L<<15,
	VisibilityChangeMask = 1L<<16,
	StructureNotifyMask = 1L<<17,
	ResizeRedirectMask = 1L<<18,
	SubstructureNotifyMask = 1L<<19,
	SubstructureRedirectMask = 1L<<20,
	FocusChangeMask = 1L<<21,
	PropertyChangeMask = 1L<<22,
	ColormapChangeMask = 1L<<23,
	OwnerGrabButtonMask = 1L<<24
};

# ifdef __APPLE__
#  include "../mlx/mlx.h"
#  define ARROW_UP		126
#  define ARROW_DOWN	125
#  define ARROW_LEFT	123
#  define ARROW_RIGHT	124
#  define KEY_W			13
#  define KEY_A			0
#  define KEY_S			1
#  define KEY_D			2
#  define ESC_KEY		53
#  define KEY_Q			12
# elif __linux
#  include "../mlx_linux/mlx.h"
#  define ARROW_UP		65362
#  define ARROW_DOWN	65364
#  define ARROW_LEFT	65361
#  define ARROW_RIGHT	65363
#  define KEY_W			119
#  define KEY_A			97
#  define KEY_S			115
#  define KEY_D			100
#  define ESC_KEY		65307
#  define KEY_Q			113
# else
#  error Stop compilation: unknown system
# endif

#define PI 3.14159265
#define TWO_PI 6.28318530

# define WINDOW_W		1280
# define WINDOW_H		960
# define ANGLE_STEP		0.02f
# define LINEAR_STEP	0.3f
# define MAP_SCALE      4
# define FOV_ANGLE      (60 * (PI / 180))
# define NUM_RAYS       WINDOW_W
# define TEXTURE_WIDTH  64
# define TEXTURE_HEIGHT 64
# define FPS 30
# define FRAME_TIME_LENGTH (1000 / FPS)

typedef struct s_player {
    float x;
    float y;
    float width;
    float height;
    int turnDirection;
    int walkDirection;
    int sideDirection;
    float rotationAngle;
    float walkSpeed;
    float turnSpeed;
}   t_player;

typedef struct s_ray {
    float rayAngle;
    float wallHitX;
    float wallHitY;
    float distance;
    int wasHitVertical;
    int isRayFacingUp;
    int isRayFacingDown;
    int isRayFacingLeft;
    int isRayFacingRight;
    int wallHitContent;
}   t_ray;

typedef struct s_game
{
	t_player    player;
    int         **map;
    t_ray       rays[NUM_RAYS];
    void	    *mlx;
	void	    *win;
}	t_game;

int     ft_destroy(t_game *game);
int     ft_key(int keycode, t_game *game);
void    ft_setup(t_game *game);
int     ft_key_rel(int keycode, t_game *game);



#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20

extern int map[MAP_NUM_ROWS][MAP_NUM_COLS];
#endif
