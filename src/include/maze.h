#ifndef MAZE_H
#define MAZE_H
#include <stdint.h>


typedef struct MAZE_STRUCT
{
    int width;
    int height;
    int* data;
    int structure_type;
} maze_T;

maze_T* init_maze(int width, int height);

void maze_free(maze_T* maze);

void maze_iterate(
    maze_T* maze,
    void (*callback)(maze_T* maze, int x, int y, int structure_type)
);

int maze_get_new_structure_type();

int maze_get_location_data(maze_T* maze, int x, int y);

int maze_set_location_data(maze_T* maze, int x, int y, int structure_type);

void maze_generate(maze_T* maze, int x, int y, int structure_type);
#endif
