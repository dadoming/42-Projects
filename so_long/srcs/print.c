#include "so_long.h"

// Prints initial map
void print_initial_map(win_s *w)
{
    int i = 0;
    int j = 0;
    while(i < w -> height)
    {
        while (j < w -> width)
        {
            if (w -> map[i][j] == '1')
                mlx_put_image_to_window(w -> mlx, w -> win, w -> wall_image, j * (w -> size_width), i * (w -> size_height));
            else
                mlx_put_image_to_window(w -> mlx, w -> win, w -> floor_image, j * (w -> size_width), i * (w -> size_height));
            if(w -> map[i][j] == 'C')
                mlx_put_image_to_window(w -> mlx, w -> win, w -> coin_image, j * (w -> size_width), i * (w -> size_height));
            else if(w -> map[i][j] == 'E')
            {
                mlx_put_image_to_window(w -> mlx, w -> win, w -> wall_image, j * (w -> size_width), i * (w -> size_height));
                mlx_put_image_to_window(w -> mlx, w -> win, w -> exit_image, j * (w -> size_width), i * (w -> size_height));
            }
            else if(w -> map[i][j] == 'B')
                mlx_put_image_to_window(w -> mlx, w -> win, w -> bomb_image, j * (w -> size_width), i * (w -> size_height));
            else if(w -> map[i][j] == 'P')
            {
                mlx_put_image_to_window(w -> mlx, w -> win, w -> p_img_1, j * (w -> size_width), i * (w -> size_height));
                w -> p_x = j;
                w -> p_y = i;
            }
            j++;
        }
        j = 0;
        i++;
    }
}