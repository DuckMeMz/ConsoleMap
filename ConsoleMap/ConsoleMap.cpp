#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

struct Coordinates
{
    int yCoord;
    int xCoord;
};

void replaceChar(char replacementChar, Coordinates coords);
Coordinates searchMap(char charToFind);
void printMap();

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
    //Don't push an invalid character
    //Work on fix for crash
    Coordinates coords = searchMap('F');
    replaceChar('S', coords);
    printMap();

    
    return 0;
}

Coordinates searchMap(char charToFind) {
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; i < sizeX; j++) {
            if (map[i][j] == charToFind) {
                Coordinates result = {i, j};
                return result;
            }
        }
    }
}

void replaceChar(char replacementChar, Coordinates coords) {
    map[coords.yCoord][coords.xCoord] = replacementChar;
}


//Changes to the map should be made before this function.
void printMap() {
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            std::cout << map[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}