# include "../inc/cub3d.h"

void    ft_setup(t_game *game)
{
    game->player.x = WINDOW_W / 2;
    game->player.y = WINDOW_H / 2;
    game->player.width = 1;
    game->player.height = 1;
    game->player.turnDirection = 0;
    game->player.walkDirection = 0;
    game->player.rotationAngle = PI / 2;
    game->player.walkSpeed = 100;
    game->player.turnSpeed = 45 * (PI / 180);
}