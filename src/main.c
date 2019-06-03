/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:55:32 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/20 21:55:33 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void                paint_heat(t_map *map)
{
    int y = 0;
    int x = 0;

    while (y < map->rows)
    {
        x = 0;
        while (x < map->cols)
        {
            if (ft_numlen(map->heat[y][x]) == 1 && map->heat[y][x] != -1)
                printf(" %d ", map->heat[y][x]);
            else
                printf("%d ", map->heat[y][x]);
            x++;
        }
        printf("\n");
        y++;
    }
}

static void         paint_token(t_oken token)
{
    int     i = 0;

    while (i < token.rows)
    {
        printf("%s", token.shape[i]);
        i++;
    }
}

void                paint_map(t_map *map)
{
    int i = 0;

    while(i < map->rows)
    {
        printf("%s", map->map[i]);
        i++;
    }
}

static void         size_of_map(char *line, t_map *map)
{
    int     i;
    char    *tmp;

    i = 0;
    tmp = line + 8;
    map->rows = ft_atoi(tmp);
    while (tmp[i] >= '0' && tmp[i] <= '9')
        i++;
    map->cols = ft_atoi(tmp + i);
}

static void         map_info(t_map *map)
{
    char    *line;

    while (get_next_line(map->fd, &line))
    {
        if (ft_strnequ(line, "$$$ exec p1 : [./pdemian", 24))
            map->player = 1;
        if (line[0] == 'P')
        {
            size_of_map(line, map);
            free(line);
            break ;
        }
        free(line);
    }
    map->me = (map->player) ? 'O' : 'X';
    map->enemy = (map->player) ? 'X' : 'O';
}

int                 main(void)
{
    t_oken      token;
    t_map       map;
    char        *line;
    int         i = 0;

    map.fd = 0;
    ft_bzero(&map, sizeof(t_map));
    // map.fd = open("../test.txt", O_RDONLY);
    while (get_next_line(map.fd, &line))
    {
        if (line[0] == 'l')
            map_info(&map);
        if (line[0] == ' ')
            parse(&map, &token);
        // free(line);
    }
    // paint_map(&map);
    // paint_heat(&map);
    // paint_token(token);
    // printf("Enemy position:\nx = %d\ny = %d\n", map.e_start_x, map.e_start_y);
    // system("leaks a.out");
    // exit(1);
    return (0);
}