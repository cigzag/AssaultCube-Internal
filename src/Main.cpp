#include <iostream>
#include <thread>
#include <fmt/format.h>
#include <dlfcn.h>
#include <sys/mman.h>
#include <unistd.h>

#include "utils.h"
#include "game.h"

void Initialize() {
	fmt::print("Loading AssaultCube...\n");

    Game game;
    open_game(&game);
    printf("pid: %d\n", game.pid);
    printf("assaultcube_client.real module: %lx\n", game.module);

    int number = 150;
    unsigned long ptr;

    while (true) {
        if (read_addr(game.pid, game.module + PLAYER_OFFSET, &ptr, sizeof(ptr))) {
            write_addr(game.pid, ptr + HEALTH_OFFSET, &number, sizeof(number));
            write_addr(game.pid, ptr + AMMO_OFFSET, &number, sizeof(number));
        }
    }
}

std::thread* thread;
int __attribute__((constructor)) Start() {
	thread = new std::thread(Initialize);

	return 0;
}

void __attribute__((destructor)) Stop() {
	thread->join();
	fmt::print("Hack unloaded!\n");
}