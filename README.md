# General purpose Maze generator
> A maze generator to be used however you want.


## Usage
> To use it:
```C
#include <maze/maze.h>


int main(int argc, char* argv[])
{
    //                       width    height
    maze_T* maze = init_maze(640,     480);

    /*
    * Get a structure type at a position.
    * They can be one of the following enumerations:
    *   MAZE_STRUCTURE_EMPTY,
    *   MAZE_STRUCTURE_INTERSECTION,
    *   MAZE_STRUCTURE_HORIZONTAL,
    *   MAZE_STRUCTURE_VERTICAL
    */
    maze_get_location_data(maze, x, y);

    // dont forget to free it
    maze_free(maze);

    return 0;
}
```
