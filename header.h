/*
Name: Joey Macauley
Date: April 14, 2021
*/

#ifndef PA8_H
#define PA8_H

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std; 

//Global Variables
const int BOARD_SIZE = 10;  
const int MAX_INVENTORY_SIZE = 10;  
const int NUM_TILE_TYPES = 4; 
const int TILE_TYPES[4] = {43,45,61,126};
const int CLEAR_VALUE = ' '; 
const int NUM_LOOT_ITEMS = 10; 
const int LOOT_LIST_VALUES[NUM_LOOT_ITEMS][2] = {{15,0}, {15,1}, {25,0}, {25,1}, {35,0}, {35,1}, {45,0}, {45,1}, {55,0}, {55,1}};
const string LOOT_LIST_DESCRIPTIONS[NUM_LOOT_ITEMS] = {"Sword", "Shield", "Hand Axe", "Shield", "Sword", "Shield", "Hand Axe", "Shield", "Sword", "Shield"};

//Function Protypes
void displayBoard(char board[][BOARD_SIZE], int rows, int cols);
char generateTile(const int TILE_TYPES[4]);
void initBoard(char board[][BOARD_SIZE], int rows, int cols, const int TILE_TYPES[4]);
void displayBoardPosition(char board[][BOARD_SIZE], int& rows, int& cols, int& currRow, int& currCol, char& saveTile);
void displayPlayerStats(int playerStats[3]);
void displayInventoryStats(int playerCurrentInventoryStats[][2], string inventoryDescription[BOARD_SIZE], int numItems);
void displayScore(int score);
void updateStats(int playerStats[3], int playerCurrentInventoryStats[][2], int numItems);
char menuPrompt(void);
bool validateMove(int BOARD_SIZE, int currRow, int currCol);
bool fightMonster(int playerStats[3]);
void addToInventory(const string LOOT_LIST_DESCRIPTIONS[NUM_LOOT_ITEMS], const int LOOT_LIST_VALUES[NUM_LOOT_ITEMS][2], int playerCurrentInventoryStats[][2], string inventoryDescription[BOARD_SIZE], int& numItems);
void wipeInventory(int playerCurrentInventoryStats[][2], string inventoryDescription[BOARD_SIZE], int& numItems);

#endif


