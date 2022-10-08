//
// Created by wyattw on 8/10/22.
//

#include <stdbool.h>
#include <sys/types.h>

#ifndef HACK_UTILS_H
#define HACK_UTILS_H

bool read_addr(pid_t pid, unsigned long addr, void *buffer, size_t size);

bool write_addr(pid_t pid, unsigned long addr, void *buffer, size_t size);

pid_t find_pid(char *name);

unsigned long module_addr(pid_t pid, char *name);

#endif //HACK_UTILS_H
