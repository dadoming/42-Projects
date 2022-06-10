/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:06:39 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/09 18:02:58 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//mktt
//https://opengameart.org/content/animated-pirate-captain
// adicionar funcao para calcular a posicao do navio if ((width / 2) < i)


void print_map(win_s *w, img_s *img)
{
    img -> floor_image = mlx_xpm_file_to_image(w -> mlx, "./sprites/sand.xpm", &(img -> x), &(img -> y));
    img -> wall_image = mlx_xpm_file_to_image(w -> mlx, "./sprites/water.xpm", &(img -> x), &(img -> y));
    img -> coin_image = mlx_xpm_file_to_image(w -> mlx, "./sprites/coin.xpm", &(img -> x), &(img -> y));
    img -> bomb_image = mlx_xpm_file_to_image(w -> mlx, "./sprites/bomb.xpm", &(img -> x), &(img -> y));
    img -> exit_image = mlx_xpm_file_to_image(w -> mlx, "./sprites/boat_l-r.xpm", &(img -> x), &(img -> y));
    
    int i = 0;
    int j = 0;
    while(j < w -> width)
    {
        while (i < w -> height)
        {
            if(w -> map[i][j] == '1')
            {
                mlx_put_image_to_window(w -> mlx, w -> win, img -> wall_image, i * (img -> x), j * (img -> y));
            }
            else if(w -> map[i][j] == '0')
            {
                mlx_put_image_to_window(w -> mlx, w -> win, img -> floor_image, j * (img -> x), i * (img -> y));
            }
            else if(w -> map[i][j] == 'C')
            {
                mlx_put_image_to_window(w -> mlx, w -> win, img -> floor_image, j * (img -> x), i * (img -> y));
                mlx_put_image_to_window(w -> mlx, w -> win, img -> coin_image, j * (img -> x), i * (img -> y));
            }
            else if(w -> map[i][j] == 'E')
            {
                mlx_put_image_to_window(w -> mlx, w -> win, img -> floor_image, j * (img -> x), i * (img -> y));
                mlx_put_image_to_window(w -> mlx, w -> win, img -> exit_image, j * (img -> x), i * (img -> y));
            }
            else if(w -> map[i][j] == 'B')
            {
                mlx_put_image_to_window(w -> mlx, w -> win, img -> floor_image, j * (img -> x), i * (img -> y));
                mlx_put_image_to_window(w -> mlx, w -> win, img -> bomb_image, j * (img -> x), i * (img -> y));
            }
            else if(w -> map[i][j] == 'P')
            {
                
            }
            i++;
        }
        i = 0;
        j++;
    }

}

int main(int argc, char **argv)
{
    win_s ptr;
    img_s img;
    
    if (argc != 2)
        exit(1);

    // Init
    if(initialization(&ptr, argv[1]) != 0)
        return(1);

    // Open screen
    ptr.mlx = mlx_init();
    if(!ptr.mlx)
        return(3);

    // Create window with calculated needed size format
    ptr.win = mlx_new_window(ptr.mlx, 32 * ptr.width, 32 * ptr.height, "so_long");//trocar o tamanho da window 
    if(!ptr.win)
        return (4);
    
    //write(ptr.map_file, "11111111111", 11); -> conferir se funciona para escrever para a janela usando o output do ecra
    
    print_map(&ptr, &img); 
    
    // Key event to close window
    mlx_hook(ptr.win, 2, 1L << 0, &key_close_window, &ptr);
    mlx_hook(ptr.win, 17, 1L << 2, &x_close_window, &ptr);
    
    // To keep the key input active
    mlx_loop(ptr.mlx);
    return (0);
}
