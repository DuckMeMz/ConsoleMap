#include "map_generator.h"

// Define the map array
char map[sizeY][sizeX];

// Function to return the map array
char (*getMap())[sizeX] {
    return map;
}

// (Other function implementations remain the same)

Coordinates searchMap(char charToFind) {
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            if (map[i][j] == charToFind) {
                return { i, j };
            }
        }
    }
    return { -1, -1 };
}

// Other functions go here...
