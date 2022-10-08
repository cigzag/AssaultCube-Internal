//
// Created by wyattw on 8/10/22.
//

#include "game.h"
#include "utils.h"
#include <stdio.h>
#include <iostream>
#include <unistd.h>

void open_game(Game *game) {
    while((game->pid = find_pid((char*)"assaultcube_client.real")) == 0) {
        usleep(1000);
    }
    while ((game->module = module_addr(game->pid, (char*)"assaultcube_client.real")) == 0) {
        usleep(1000);
    }
}