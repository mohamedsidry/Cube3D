/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:13:59 by msidry            #+#    #+#             */
/*   Updated: 2025/11/15 20:17:43 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void print_line(void *content);
void game_init(t_game**ref, int argc, char *argv[])
{
    *ref = ft_calloc(1, sizeof(t_game));
    if (!*ref)
    {
        ft_putendl_fd(strerror(errno), 2);
        exit(EXIT_FAILURE);
    }
    (*ref)->argc = argc;
    (*ref)->argv = argv;
    (*ref)->scene.path = argv[1];
    (*ref)->scene.fd = -1;
    (*ref)->scene.map = NULL;
    init_error(*ref);
    validatorInput(*ref);
    init_map(*ref);
    ft_lstiter((*ref)->scene.map, print_line);
    //validatorMap(*ref);
    isAllGood(ref);
}


static void print_line(void *content)
{
    char *colored = find_replace(MAPLINE, "$MAPLINE", (char *)content, 0);
    ft_putendl_fd(colored, 1);
    free (colored);
}
