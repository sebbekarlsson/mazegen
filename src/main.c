#include <stdio.h>
#include "include/maze.h"


int main(int argc, char* argv[])
{
    maze_T* maze = init_maze(640, 480);

    maze_free(maze);

    return 0;
}
