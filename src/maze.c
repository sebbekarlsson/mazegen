#include "include/maze.h"
#include "include/structures.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/param.h>


maze_T* init_maze(int width, int height)
{
    maze_T* maze = calloc(1, sizeof(struct MAZE_STRUCT));
    maze->width = width;
    maze->height = height;
    maze->data = calloc(width * height, sizeof(int));
    
    maze->structure_type = -1;

    maze_iterate(maze, maze_generate);

    return maze;
}

void maze_free(maze_T* maze)
{
    free(maze->data);
    free(maze);
}

void maze_iterate(
    maze_T* maze,
    void (*callback)(maze_T* maze, int x, int y, int structure_type)
)
{
    for (int x = 0; x < maze->width; x++)
        for (int y = 0; y < maze->height; y++)
            callback(maze, x, y, maze_get_location_data(maze, x, y));
}

int maze_get_new_structure_type()
{
    int min_number = 1;
    int max_number = 3;

    return rand() % (max_number + 1 - min_number) + min_number;
}

int maze_get_location_data(maze_T* maze, int x, int y)
{
    return maze->data[y*maze->width+x];
}

int maze_set_location_data(maze_T* maze, int x, int y, int structure_type)
{
    maze->data[y*maze->width+x] = structure_type;
}

void maze_generate(maze_T* maze, int x, int y, int structure_type)
{
    if (maze->structure_type == -1)
        maze->structure_type = maze_get_new_structure_type();

    // intersection to the left or right
    if (maze_get_location_data(maze, MAX(0, x - 1) , y) == MAZE_STRUCTURE_INTERSECTION || maze_get_location_data(maze, MIN(maze->height-1, x + 1) , y) == MAZE_STRUCTURE_HORIZONTAL)
    {
       maze->structure_type = MAZE_STRUCTURE_HORIZONTAL;
    }
    // intersection above or below
    else if (maze_get_location_data(maze, x, MAX(0, y - 1)) == MAZE_STRUCTURE_INTERSECTION || maze_get_location_data(maze, x, MIN(maze->height-1, y + 1)) == MAZE_STRUCTURE_INTERSECTION)
        maze->structure_type = MAZE_STRUCTURE_VERTICAL;
    else
    {
        maze->structure_type = maze_get_new_structure_type();
    }

    maze_set_location_data(maze, x, y, maze->structure_type);
}
