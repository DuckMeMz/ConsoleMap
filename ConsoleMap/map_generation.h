#ifndef map_generation_h
#define map_generation_h

#include<vector>


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

#endif // !map_generation_h

