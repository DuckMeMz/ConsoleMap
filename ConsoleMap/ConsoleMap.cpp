#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>

struct Coordinates
{
    int yCoord;
    int xCoord;
};
std::vector<Coordinates> searchWholeMap(char charToFind);
void replaceChar(char replacementChar, Coordinates coords);
void replaceAllChar(char charToReplace, char replacementChar);
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

    replaceAllChar('T', 'S');
    replaceChar('X', { 1,1 });
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

std::vector<Coordinates> searchWholeMap(char charToFind) {
    std::vector<Coordinates> foundCoords;
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            if (map[i][j] == charToFind) {
                Coordinates result = { i, j };
                foundCoords.push_back(result);
            }
        }
    }
    return foundCoords;
}

void replaceChar(char replacementChar, Coordinates coords) {
    if (coords.yCoord < sizeY && coords.yCoord > -1 && coords.xCoord < sizeX && coords.xCoord > -1) {
        map[coords.yCoord][coords.xCoord] = replacementChar;
    }
    else {
        std::cerr << "Character Doesn't exist in the map couldn't replace character" << std::endl;
    }

}

void replaceAllChar(char charToReplace, char replacementChar) {
    std::vector<Coordinates> coordsList = searchWholeMap(charToReplace);
    for (const auto& coords : coordsList) {
        if (coords.yCoord < sizeY && coords.yCoord > -1 && coords.xCoord < sizeX && coords.xCoord > -1) {
            map[coords.yCoord][coords.xCoord] = replacementChar;
        }
        else {
            std::cerr << "Character Doesn't exist in the map couldn't replace character" << std::endl;
        }

    }
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