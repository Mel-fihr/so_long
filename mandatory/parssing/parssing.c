/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:50:54 by mel-fihr          #+#    #+#             */
/*   Updated: 2024/02/06 20:44:12 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    parssing_1(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < data->height)
    {
        if (data->map[i][0] != '1' || data->map[i][data->width - 2] != '1')
        {
            printf("Error1\n");
            exit(0);
        }
        i++;
    }
    while (j < data->width - 1)
    {
        if (data->map[0][j] != '1' || data->map[data->height - 1][j] != '1')
        {
            printf("Error2\n");
            exit(0);
        }
        j++;
    }
}

void    parssing_rectangular(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->height)
    {
        j = 0;
        while (j < (data->width - 1))
        {
            if (data->map[i][j] == '\0')
            {
                printf("Error4\n");
                exit(0);
            }
            j++;
        }
        i++;
    }
}

void    parssing_ecp(t_data *data)
{
    t_ecp ecp;

    ecp.i = 0;
    ecp.j = 0;
    ecp.c = 0;
    ecp.e = 0;
    ecp.p = 0;
    while (ecp.i < data->height)
    {
        ecp.j = 0;
        while (ecp.j < data->width)
        {
            if (data->map[ecp.i][ecp.j] == 'E')
                ecp.e++;
            if (data->map[ecp.i][ecp.j] == 'C')
                ecp.c++;
            if (data->map[ecp.i][ecp.j] == 'P')
                ecp.p++;
            ecp.j++;
        }
        ecp.i++;
    }
    if (ecp.e != 1 || ecp.c < 1 || ecp.p != 1)
    {
        printf("Error3\n");
        exit(0);
    }
}


void    parssing(t_data *data)
{
    int a;
    int b;

    a = 0;
    parssing_1(data);
    parssing_ecp(data);
    parssing_rectangular(data);
    flood_fill(data, data->p_x, data->p_y);
    while (a < data->height)
    {
        b = 0;
        while (b < data->width - 1)
        {
            
            if (data->map[a][b] != '1')
            {
                printf("Errorm\n");
                exit(0);
            }
            b++;
        }
        a++;
    }
    data->map = readmap(data->file, data);
}
