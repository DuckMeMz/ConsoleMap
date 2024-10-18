#ifndef MAP_GENERATOR_H
#define MAP_GENERATOR_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Structure to hold coordinates
struct Coordinates
{
    int yCoord;
    int xCoord;
};

// Constants and global variables
const int sizeY = 20;
const int sizeX = 20;
const char water = '=';
const char tree = 'T';
const char lake = 'O';
const char land = '#';
extern char map[sizeY][sizeX]; // Declare the map array as extern so it can be defined in the source file

// Function declarations
void treeWaterRule(char replacementChar);
std::vector<Coordinates> searchWholeMap(char charToFind);
void replaceChar(char replacementChar, Coordinates coords);
void replaceAllChar(char charToReplace, char replacementChar);
Coordinates searchMap(char charToFind);
void printMap();
char randomElementGenerator(float landweight, float waterweight, float lakeweight, float treeweight);
void randomlyGenerateMap(float landweight, float waterweight, float lakeweight, float treeweight);

// Function to return the generated map
char (*getMap())[sizeX];

#endif // MAP_GENERATOR_H
