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

int main() {
    std::srand(static_cast<int>(std::time(NULL)));


    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            char chosenChar = mapSymbols[std::rand() % max];
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

