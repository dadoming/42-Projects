/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:51:19 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/09 17:14:22 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

typedef struct s_images{
    void *bomb_image;
    void *wall_image;
    void *floor_image;
    void *coin_image;
    void *exit_image;
    int x;
    int y;
} img_s;

#endif