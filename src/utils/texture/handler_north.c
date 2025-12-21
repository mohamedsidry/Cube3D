/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_north.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:29:50 by msidry            #+#    #+#             */
/*   Updated: 2025/12/21 16:28:22 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


void set_north_texture(t_error *err, t_gametxt *textures, char *line)
{
    static int duplicate;
    char *msg;
    if (duplicate)
    {
        msg = find_replace(ERROR_DUP, "$TXT", "north (NO) :", 0) ;
        setError(err, msg);
        setStat(err, EXIT_FAILURE);
        free(msg);
        return ;
    }
    duplicate = 1;
    texture_format_handler(err, &textures->north_txt, line);
}
