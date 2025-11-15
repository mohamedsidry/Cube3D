/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:53:59 by msidry            #+#    #+#             */
/*   Updated: 2025/11/15 19:57:52 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void init_map(t_game *ref)
{
    char *rawline;
    char *pureline;

    if (!isAllOk(ref))
        return ;
    while (true)
    {
        rawline = get_next_line(ref->scene.fd);
        if (!rawline)
            break;
        pureline = ft_strtrim(rawline, "\n \v\t\r\b");
        if (pureline && *pureline)
            ft_lstadd_back(&ref->scene.map, ft_lstnew(pureline));
        else
            free(pureline);
        free(rawline);
    }
    close(ref->scene.fd);
    ref->scene.fd = -1;
}
