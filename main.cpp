/*
Name: Joey Macauley
Date: April 14, 2021
*/

#include "header.h"


int main() {

	char board[BOARD_SIZE][BOARD_SIZE];
	char choice = '\0';
	int gameScore = 0;
	int playerStats[3] = {100, 50, 0};
	int playerCurrentInventoryStats[MAX_INVENTORY_SIZE][2];
	string inventoryDescription[MAX_INVENTORY_SIZE];
	int currentInventoryCount = 0; 
	int currRow = 0;
	int currCol = 0;
	int row = 0; 
	int col = 0;
	char saveTile = '\0'; 
	int probability = 0;   
	bool validMove = false; 
	bool wonFight = false; 
	string trash = ""; 	
	
	srand(time(0));
	
	initBoard(board, BOARD_SIZE, BOARD_SIZE, TILE_TYPES);
	saveTile = board[0][0]; 
	displayBoardPosition(board, row, col, currRow, currCol, saveTile);

	do
	{
		cout << "----------------------------------------------------" << endl; 
		displayScore(gameScore);
		displayPlayerStats(playerStats);
		displayBoard(board, BOARD_SIZE, BOARD_SIZE);
		cout << "\nCurrent Tile: " << saveTile << endl; 
		choice = menuPrompt();

		switch (choice)
		{
		case 'u':
			validMove = validateMove(BOARD_SIZE, currRow - 1, currCol);
			if(validMove == true)
			{
				board[row][col] = saveTile; 
				currRow = currRow - 1; 
				displayBoardPosition(board, row, col, currRow, currCol, saveTile);
				row = currRow; col = currCol; 
			}
			else
				cout << "INVALID MOVE... TRY AGAIN!" << endl; 
			break;
		case 'd':
			validMove = validateMove(BOARD_SIZE, currRow + 1, currCol);
			if(validMove == true)
			{
				board[row][col] = saveTile; 
				currRow = currRow + 1;
				displayBoardPosition(board, row, col, currRow, currCol, saveTile);
				row = currRow; col = currCol; 
			}
			else
				cout << "Invalid Move... Try Again!" << endl; 
			break;
		case 'l':
			validMove = validateMove(BOARD_SIZE, currRow, currCol - 1);
			if(validMove == true)
			{
				board[row][col] = saveTile; 
				currCol = currCol- 1; 
				displayBoardPosition(board, row, col, currRow, currCol, saveTile);
				row = currRow; col = currCol; 
			}
			else
				cout << "Invalid Move... Try Again!" << endl; 
			break;
		case 'r':
			validMove = validateMove(BOARD_SIZE, currRow, currCol + 1);
			if(validMove == true)
			{
				board[row][col] = saveTile; 
				currCol = currCol + 1; 
				displayBoardPosition(board, row, col, currRow, currCol, saveTile);
				row = currRow; col = currCol; 
			}
			else
				cout << "Invalid Move... Try Again!" << endl; 
			break;
		case 'i':
			displayInventoryStats(playerCurrentInventoryStats, inventoryDescription, currentInventoryCount);
			break;
		case 's':
			if (saveTile == CLEAR_VALUE)
				break; 
			else 
			{
				saveTile = CLEAR_VALUE; 
				probability = rand() % 2; 
				if (probability != 1) //NO MONSTER FIGHT
				{
					gameScore = gameScore + 5; 
					addToInventory(LOOT_LIST_DESCRIPTIONS, LOOT_LIST_VALUES, playerCurrentInventoryStats, inventoryDescription, currentInventoryCount);	
					updateStats(playerStats, playerCurrentInventoryStats, currentInventoryCount);
				}
				else //MONSTER FIGHT
				{
					wonFight = fightMonster(playerStats);
					if (wonFight == true) //WIN
					{
						wipeInventory(playerCurrentInventoryStats, inventoryDescription, currentInventoryCount);
						addToInventory(LOOT_LIST_DESCRIPTIONS, LOOT_LIST_VALUES, playerCurrentInventoryStats, inventoryDescription, currentInventoryCount);	
						updateStats(playerStats, playerCurrentInventoryStats, currentInventoryCount);
						gameScore = gameScore + 5; 
					}
					else //LOSE
					{
						choice = 'q'; 
					}
					cout << "\n[Press enter to continue...]" << endl; //PAUSE
					getline(cin, trash); 
					getline(cin, trash);
				}
			}
			break;
		case 'c':
			if (saveTile == CLEAR_VALUE)
				break; 
			else 
			{
				saveTile = CLEAR_VALUE; 
				probability = rand() % 10; 
				if (probability != 1) //NO MONSTER FIGHT
				{
					gameScore = gameScore + 1; 
				}
				else //MONSTER FIGHT
				{
					wonFight = fightMonster(playerStats);
					if (wonFight == true) //WIN
					{
						wipeInventory(playerCurrentInventoryStats, inventoryDescription, currentInventoryCount); 
						gameScore = gameScore + 1; 
					}
					else //LOSE
					{
						choice = 'q'; 
					}
					cout << "\n[Press enter to continue...]" << endl; //PAUSE
					getline(cin, trash); 
					getline(cin, trash);
				}
			}
				
			break;
		default:
			break;
		}
	} while (choice != 'q');

	cout << "Game Over!" << endl;
	cout << "Score: " << gameScore << endl;

	return 0;
}
