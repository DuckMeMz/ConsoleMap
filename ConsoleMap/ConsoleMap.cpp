#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime> 

const int sizeY = 20;
const int sizeX = 20;
char water = '=';
char tree = 'T';
char lake = 'O';
char land = '#';
int amountOfTrees = 0;
const int min = 0;
char mapSymbols[4] = { water, tree, lake, land };
int max = sizeof(mapSymbols) / sizeof(mapSymbols[0]);
char map[sizeY][sizeX];

bool canSpawnTree(char map[sizeY][sizeX], int y, int x);
bool canSpawnLake(char map[sizeY][sizeX], int y, int x);

int main() {
    std::srand(static_cast<int>(std::time(NULL)));


    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            char chosenChar = mapSymbols[std::rand() % max];
            if (chosenChar == tree && !canSpawnTree(map, i, j)) {
                chosenChar = land;
            }
            if (chosenChar == lake && !canSpawnLake(map, i, j)) {
                chosenChar = land;
            }
            map[i][j] = chosenChar;
        }
    }


    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            std::cout << map[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}

bool canSpawnTree(char map[sizeY][sizeX], int y, int x) {
    if ((y > 0 && map[y - 1][x] == water) ||
        (y < sizeY - 1 && map[y + 1][x] == water) ||
        (x > 0 && map[y][x - 1] == water) ||
        (x < sizeX - 1 && map[y][x + 1] == water)) {
        return false;
    }
    return true;
}

bool canSpawnLake(char map[sizeY][sizeX], int y, int x) {
    if ((y > 0 && map[y - 1][x] == water) ||
        (y < sizeY - 1 && map[y + 1][x] == water) ||
        (x > 0 && map[y][x - 1] == water) ||
        (x < sizeX - 1 && map[y][x + 1] == water)) {
        return false;
    }
    return true;
}