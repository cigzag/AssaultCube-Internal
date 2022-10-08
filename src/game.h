//
// Created by wyattw on 8/10/22.
//

#ifndef HACK_GAME_H
#define HACK_GAME_H

#include <stdbool.h>
#include <sys/types.h>

#define PLAYER_OFFSET 0x1F2B40
#define HEALTH_OFFSET 0x100
#define AMMO_OFFSET 0x154

typedef struct {
    pid_t pid;
    unsigned long module;
} Game;

void open_game(Game *game);

#endif //HACK_GAME_H
