/*
Name: Joey Macauley
Date: April 14, 2021
*/

#include "header.h"

/*************************************************************
* Function: displayBoard()
* Date Created: 04/09/2021
* Date Last Modified: 04/11/2021 
* Description: Display the board
* Input parameters: char board[][BOARD_SIZE], int rows, int cols
* Returns: N/A 
*************************************************************/
void displayBoard(char board[][BOARD_SIZE], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	} 
}

/*************************************************************
* Function: generateTile() 
* Date Created: 04/09/2021
* Date Last Modified: 04/11/2021  
* Description: Generate a tile our of 4 different ooption
* Input parameters: void
* Returns: char value
*************************************************************/
char generateTile(const int TILE_TYPES[4])
{
	int randIndex = rand() % 4; 	
		
	return TILE_TYPES[randIndex];  
}

/*************************************************************
* Function: initBoard() 
* Date Created: 04/09/2021
* Date Last Modified: 04/11/2021 
* Description: Creates 2D array to represent game board. 
* Input parameters: char board[][BOARD_SIZE], int rows, int cols
* Returns: char value
*************************************************************/
void initBoard(char board[][BOARD_SIZE], int rows, int cols, const int TILE_TYPES[4])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = generateTile(TILE_TYPES);
		}
	} 
}

/*************************************************************
* Function: displayBoardPosition() 
* Date Created: 04/09/2021
* Date Last Modified: 04/11/2021 
* Description: Display "@" system as a postion identifier on the board
* Input parameters: char board[][BOARD_SIZE], int& rows, int& cols, int& currRow, int& currCol, char& saveTile
* Returns: N/A
*************************************************************/
void displayBoardPosition(char board[][BOARD_SIZE], int& rows, int& cols, int& currRow, int& currCol, char& saveTile)

{
	char currPosition = '@'; 
	if (currRow == 0 && currCol == 0)
	{
		board[currRow][currCol] = currPosition;
	}
	else 
	{
		saveTile = board[currRow][currCol];
		board[currRow][currCol] = currPosition; 	
	}
}

/*************************************************************
* Function: displayPlayerStats() 
* Date Created: 04/09/2021
* Date Last Modified: 04/11/2021 
* Description: Output player stats for their health, attack, and defense. 
* Input parameters: int playerStats[3]
* Returns: N/A
*************************************************************/
void displayPlayerStats(int playerStats[3])
{
	cout << "Health: " << playerStats[0] << " Attack: " << playerStats[1] << " Defense: " << playerStats[2] << endl << endl; 
}

/*************************************************************
* Function: displayInventoryStats() 
* Date Created: 04/09/2021
* Date Last Modified: 04/11/2021 
* Description: Display what the player is holding in their inventory
* Input parameters: int playerCurrentInventoryStats[][2], string inventoryDescription[BOARD_SIZE], int numItems
* Returns: N/A
*************************************************************/
void displayInventoryStats(int playerCurrentInventoryStats[][2], string inventoryDescription[BOARD_SIZE], int numItems)
{
	cout << endl; 
	for (int i = 0; i < numItems; i++)
	{
		string defense = "Yes"; 
		if (playerCurrentInventoryStats[i][1] == 0) {
			defense = "No"; }
		cout << inventoryDescription[i] << " - " << "Strength: " << playerCurrentInventoryStats[i][0] << " Defensive: " << defense << endl; 
	}	
}

/*************************************************************
* Function: displayScore() 
* Date Created: 04/09/2021
* Date Last Modified: 04/11/2021 
* Description: Output score each round
* Input parameters: int score
* Returns: N/A
*************************************************************/
void displayScore(int score)
{
	cout << "\nCurrent Score: " << score << endl; 
}

/*************************************************************
* Function: updateStats() 
* Date Created: 04/09/2021
* Date Last Modified: 04/11/2021 
* Description: Update player stats depending on loot collected 
* Input parameters: int playerStats[3], int playerCurrentInventoryStats[][2], int numItems
* Returns: N/A
*************************************************************/
void updateStats(int playerStats[3], int playerCurrentInventoryStats[][2], int numItems)
{
	if (playerCurrentInventoryStats[numItems-1][1] == 0)
		playerStats[1] = playerStats[1] + playerCurrentInventoryStats[numItems-1][0]; 
	else
		playerStats[2] = playerStats[2] + playerCurrentInventoryStats[numItems-1][0];

}

/*************************************************************
* Function: menuPrompt() 
* Date Created: 04/09/2021
* Date Last Modified: 04/11/2021 
* Description: Output menu for player choice
* Input parameters: void
* Returns: char value
*************************************************************/
char menuPrompt(void)
{
	char choice = '\0';
	cout << "Pick a direction to move in:" << endl;
	cout << "Directions: (u)p, (d)own, (l)eft, (r)ight " << endl;
	cout << "Actions: (s)earch tile, (c)lear tile" << endl;
	cout << "Options: (i)nventory, (q)uit" << endl;
	cin >> choice;
	return choice; 
}

/*************************************************************
* Function: validateMove() 
* Date Created: 04/09/2021
* Date Last Modified: 04/11/2021 
* Description: Make sure a players move isn't out of bounds
* Input parameters: int BOARD_SIZE, int currRow, int currCol 
* Returns: Boolean Value
*************************************************************/
bool validateMove(int BOARD_SIZE, int currRow, int currCol)
{
	if (currRow >= 0 & currRow < BOARD_SIZE)
	{
		if (currCol >= 0 & currRow < BOARD_SIZE)
			return true; 
		else
			return false; 
	}
	else 
	{
		return false; 
	}	
}

/************************************************************* 
* Function: fightMonster() 
* Date Created: 04/09/2021
* Date Last Modified: 04/11/2021 
* Description: simulate a monster fight, determine if the player wins or loses 
* Input parameters: int playerStats[3], int playerCurrentInventoryStats[][2], int numItems, char board[][BOARD_SIZE], int currRow, int currCol
* Returns: Boolean Value
*************************************************************/
bool fightMonster(int playerStats[3])
{
	int monsterHealth = 0; 
	int monsterAttack = 0; 
	
	monsterHealth = rand() % 181 + 20; 
	monsterAttack = rand() % 91 + 10; 
	
	cout << "\nPlayer Health: " << playerStats[0] << endl; 
	cout << "Player Attack/Defense: " << playerStats[1] << "/" << playerStats[2] << endl; 
	cout << "Monster Health/Attack: " << monsterHealth << "/" << monsterAttack << endl; 
	cout << "\nResult: " << endl;		
	if (playerStats[1] >= monsterHealth)
	{
		cout << "Player Attacks for " << playerStats[1] << " KILLING the monster!" << endl; 
		playerStats[1] = 50; playerStats[2] = 0;
		return true; 
	}	
	else if (monsterAttack <= playerStats[2]) 
	{
		cout << "Player Attacks for " << playerStats[1] << " but the monster survives!" << endl; 
		cout << "Monster hits player for " << monsterAttack << " damage!" << endl; 
		cout << "Player survived? YES!" << endl; 
		playerStats[1] = 50; playerStats[2] = 0; 
		return true; 
	}		
	else if (monsterAttack > playerStats[2])
	{
		cout << "Player Attacks for " << playerStats[1] << " but the monster survives!" << endl; 
		cout << "Monster hits player for " << monsterAttack << " damage!" << endl; 
		cout << "Player survived? "; 
		playerStats[0] = playerStats[0] - abs(monsterAttack - playerStats[2]); 
		if (playerStats[0] <= 0)
		{
			cout << "No...\n";
			return false; 
		}
		else 
		{
			cout << "YES!\n";
			playerStats[1] = 50; playerStats[2] = 0; 
			return true; 
		}
	}
	return false; 
}


/*************************************************************
* Function: addToInventory() 
* Date Created: 04/09/2021
* Date Last Modified: 04/11/2021 
* Description: Add loot to inventory 
* Input parameters: const string LOOT_LIST_DESCRIPTIONS[NUM_LOOT_ITEMS], const int LOOT_LIST_VALUES[NUM_LOOT_ITEMS][2], int playerCurrentInventoryStats[][2], string inventoryDescription[BOARD_SIZE], int& numItems
* Returns: N/A
*************************************************************/
void addToInventory(const string LOOT_LIST_DESCRIPTIONS[NUM_LOOT_ITEMS], const int LOOT_LIST_VALUES[NUM_LOOT_ITEMS][2], int playerCurrentInventoryStats[][2], string inventoryDescription[BOARD_SIZE], int& numItems)
{
	int random = rand() % 10; 
	inventoryDescription[numItems] = LOOT_LIST_DESCRIPTIONS[random]; 
	playerCurrentInventoryStats[numItems][0] = LOOT_LIST_VALUES[random][0];
	playerCurrentInventoryStats[numItems][1] = LOOT_LIST_VALUES[random][1];
	numItems++; 
	
	string defense = "Yes"; 
	if (LOOT_LIST_VALUES[random][1] == 0) 
	{ 
		defense = "No"; 
	}
	cout << "\nYou collected a " << LOOT_LIST_DESCRIPTIONS[random] << ". (Strength: " << LOOT_LIST_VALUES[random][0] << ", Defensive? " << defense << ")" << endl; 
}

/*************************************************************
* Function: wipeInventory() 
* Date Created: 04/09/2021
* Date Last Modified: 04/11/2021 
* Description: Completely clear inventory of all loot. 
* Input parameters: int playerCurrentInventoryStats[][2], string inventoryDescription[BOARD_SIZE], int& numItems
* Returns: N/A
*************************************************************/
void wipeInventory(int playerCurrentInventoryStats[][2], string inventoryDescription[BOARD_SIZE], int& numItems)
{
	for (int i = 0; i < numItems; i++)
	{
		playerCurrentInventoryStats[i][0] = {}; 
		playerCurrentInventoryStats[i][0] = {}; 
		inventoryDescription[i] = {}; 
	}
	numItems = 0; 
	
}
