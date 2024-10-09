#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>

// Structure to hold coordinates
struct Coordinates
{
    int yCoord;
    int xCoord;
};

// Function declarations
std::vector<Coordinates> searchWholeMap(char charToFind);
void replaceChar(char replacementChar, Coordinates coords);
void replaceAllChar(char charToReplace, char replacementChar);
Coordinates searchMap(char charToFind);
void printMap();

// Constants and global variables
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
    // Seed random number generator
    std::srand(static_cast<int>(std::time(NULL)));

    //Randomly Generates Map in "map" 2D array
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

// Searches the map for the first occurrence of the input character
Coordinates searchMap(char charToFind) {
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; i < sizeX; j++) {
            if (map[i][j] == charToFind) {
                Coordinates result = {i, j};
                return result;
            }
        }
    }
    // Return an invalid coordinate if no character is found
    return{ -1, -1 };
}

// Searches the entire map for all occurrences of the input character (AI Generated Function)
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
// Replaces a single specified character at a set of coordinates
void replaceChar(char replacementChar, Coordinates coords) {
    if (coords.yCoord < sizeY && coords.yCoord > -1 && coords.xCoord < sizeX && coords.xCoord > -1) {
        map[coords.yCoord][coords.xCoord] = replacementChar;
    }
    else {
        std::cerr << "Character Doesn't exist in the map couldn't replace character" << std::endl;
    }

}
// Replaces all occurrences of a specified character with another character
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


// Prints the map to the console
void printMap() {
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            std::cout << map[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}