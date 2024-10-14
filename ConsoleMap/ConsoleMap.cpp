#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <random>
#include <type_traits>
#include <cassert>
#include <iterator>



// Structure to hold coordinates
struct Coordinates
{
    int yCoord;
    int xCoord;
};

// Function declarations
void treeWaterRule(char replacementChar);
std::vector<Coordinates> searchWholeMap(char charToFind);
void replaceChar(char replacementChar, Coordinates coords);
void replaceAllChar(char charToReplace, char replacementChar);
Coordinates searchMap(char charToFind);
void printMap();
char randomElementGenerator(float landweight, float waterweight, float lakeweight, float treeweight);
void randomlyGenerateMap(float landweight, float waterweight, float lakeweight, float treeweight);

// Constants and global variables
const int sizeY = 20;
const int sizeX = 20;
char water = '=';
char tree = 'T';
char lake = 'O';
char land = '#';
int amountOfTrees = 0;
const int min = 0;
int ruleBroken = 0;
char mapSymbols[4] = { water, tree, lake, land };
int max = sizeof(mapSymbols) / sizeof(mapSymbols[0]);
char map[sizeY][sizeX];

int main() {
    // Seed random number generator
    std::srand(static_cast<int>(std::time(0)));


    randomlyGenerateMap(0.65f, 0.15f, 0.05f, 0.15f);
    printMap();
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

void treeWaterRule(char replacementChar) {
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            if (map[i][j] == tree) {
                if (i < sizeY && map[i + 1][j] == water || //Down
                    i > 0 && map[i - 1][j] == water || //Up
                    j > 0 && map[i][j - 1] == water || //Left
                    j < sizeX && map[i][j + 1] == water || // Right
                    i > 0 && j < sizeX && map[i - 1][j + 1] || // Top Right 
                    i < sizeY && j < sizeX && map[i + 1][j + 1] || // Bottom Right
                    i < sizeY && j > sizeX && map[i + 1][j - 1] || // Bottom Left
                    i > 0 && j > 0 && map[i - 1][j - 1]){ // Top Left
                    replaceChar(replacementChar, {i, j});
                }
            }
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

char randomElementGenerator(float landweight, float waterweight, float lakeweight, float treeweight)
{
    int landweightint = static_cast<int>(landweight * 1000);
    int waterweightint = static_cast<int>((waterweight * 1000) + landweightint);
    int lakeweightint = static_cast<int>((lakeweight * 1000) + waterweightint);
    int treeweightint = static_cast<int>((treeweight * 1000) + lakeweightint);
    float randomNum = rand() % 1000 + 1;
    char chosenChar = 'S';
    if (randomNum <= landweightint  ) { 
        chosenChar = land;
    }
    else if (randomNum > landweightint && randomNum <= waterweightint) {
        chosenChar = water;
    }
    else if (randomNum > waterweightint && randomNum <= lakeweightint) {
        chosenChar = lake;
    }
    else if (randomNum > lakeweightint && randomNum <= treeweightint) {

        chosenChar = tree;
    }
    else {
        std::cout << "MONKE NIPPLES " << randomNum << std::endl;
        
    }
        
    return chosenChar;
}


void randomlyGenerateMap(float landweight, float waterweight, float lakeweight, float treeweight){
     for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            char mapchosenChar = randomElementGenerator(landweight, waterweight, lakeweight, treeweight);
            map[i][j] = mapchosenChar;
        }
    }
}