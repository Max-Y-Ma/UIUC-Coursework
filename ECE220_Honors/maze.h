#pragma once

// Maze macros
#define WALL '#'
#define PATH ' '
#define CHEST 'C'
#define PLAYER 'P'
#define END 'E'

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

#include <iostream>
#include <fstream>
using namespace std;

// Player class to hold the information of the player: number of moves, health status, and stuff
class Player {
private:
	// Private Members
	int health_;												// Player health
	int number_of_moves_;										// Player moves left
	int points_;												// Player points
public:
	Player();													// Default Constructor
	Player(int game_difficulty);								// Specific Player 

	// Member Functions
	int getHealth();											// Get player health
	void setHealth(int health);									// Set player health
	int getNumMoves();											// Get player number of moves
	void setNumMoves(int number_of_moves);						// Set player number of moves
	int getPoints();											// Get player points
	void setPoints(int points);									// Set player points
};

// Game class to hold the game board and control updating/rendering the game board
class Game {
private:
	// Private Members				
	char* board_;												// Pointer to the game board
	int board_size_;											// Size of the game board
	bool game_end_;												// Game state 
	int playerX_;												// Player X position
	int playerY_;												// Player Y position
public:
	Game();														// Default Constuctor
	Game(int board_size, bool game_end);						// Specific Maze Constuctor

	// Member Functions
	void createBoard();											// Create game board
	void updateBoard(char user_move, Player& player);			// Update game board based on given move
	void printBoard();											// Print game board
	int getBoardSize();											// Get board size
	void setBoardSize(int board_size);							// Set board size
	bool getGameEnd();											// Get game end state
	void setGameEnd(bool game_end);								// Set game end state
	int getPlayerX();											// Get player Xpos
	void setPlayerX(int playerX);								// Set player Xpos
	int getPlayerY();											// Get player Ypos	
	void setPlayerY(int playerY);								// Set player Ypos
};
