#include <iostream>
#include <chrono>

//int main() {
	const int sizeY = 10;
	const int sizeX = 10;
	char water = '=';
	char trees = 'T';
	char lake = 'O';
	char land = '#';
	int amountOfTrees = 0;
	//const int min = 0;
	//const int max = 3;
	char mapSymbols[4] = { water, trees, lake, land };
	//char map[sizeY][sizeX];
	
		
	//for (int y = 0; y < sizeY; y++) {
	//	for (int x = 0; x < sizeX; x++) {
	//		std::cout << map[y][x] << ' ';
	//	}
	//	std::cout << std::endl;
	//}

	//	return 0;
	//}

//bool canPlaceTree()
//{
//	return true;
//}

int main() {
	for (int i = 0; i < sizeY; i++) {
		std::cout << std::endl;
		for (int j = 0; j < sizeX; j++) {
			char chosenChar = mapSymbols[rand() % 4];
			
			if (chosenChar == 'T') {
				++amountOfTrees;
				chosenChar = mapSymbols[3];
				continue;
			}
			else{
				std::cout << chosenChar;
			}
		}
	}
	std::cout << "\n" << amountOfTrees;
}





