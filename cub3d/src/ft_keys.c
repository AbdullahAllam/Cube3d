# include "../inc/cub3d.h"

int	ft_destroy(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game);
	//free_all(game);
	exit(0);
}

int	ft_key(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		ft_destroy(game);
	else if (keycode == ARROW_UP || keycode == KEY_W)
        game->player.walkDirection = +1;
	else if (keycode == ARROW_DOWN || keycode == KEY_S)
        game->player.walkDirection = -1;
    else if (keycode == ARROW_LEFT)
        game->player.turnDirection = -1;
    else if (keycode == ARROW_RIGHT)
	    game->player.turnDirection = +1;
	else if (keycode == KEY_A)
	    game->player.sideDirection = -1;
	else if (keycode == KEY_D)
	    game->player.sideDirection = +1;
	else
        return (0);
	//ft_redraw(game);
	return (0);
}

int	ft_key_rel(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		ft_destroy(game);
	else if (keycode == ARROW_UP || keycode == KEY_W)
        game->player.walkDirection = 0;
	else if (keycode == ARROW_DOWN || keycode == KEY_S)
        game->player.walkDirection = 0;
    else if (keycode == ARROW_LEFT)
        game->player.turnDirection = 0;
    else if (keycode == ARROW_RIGHT)
	    game->player.turnDirection = 0;
	else if (keycode == KEY_A)
	    game->player.sideDirection = 0;
	else if (keycode == KEY_D)
	    game->player.sideDirection = 0;
	else
        return (0);
	//ft_redraw(game);
	return (0);
}

