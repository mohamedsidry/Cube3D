/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:14:17 by msidry            #+#    #+#             */
/*   Updated: 2025/12/13 11:44:18 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

//static void leakCheck(void);
int	main(int argc, char *argv[])
{
	t_game *game;

	game = NULL;
	game_init(&game, argc, argv);
	game_destroy(&game);
	//atexit(leakCheck);
	return (0);
}

// static void leakCheck(void)
// {
//  	system("leaks -q cube3D");
// }
