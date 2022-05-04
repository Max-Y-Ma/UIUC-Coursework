#include "maze.h"
using namespace std;

Player::Player()
{
	// Initialize default player object
	health_ = 0;
	number_of_moves_ = 0;
	points_ = 0;
}

Player::Player(int game_difficulty)
{
	// Initialize current game object
	health_ = game_difficulty;
	number_of_moves_ = 0;
	points_ = 0;
}

int Player::getHealth()
{
	return health_;
}

void Player::setHealth(int health)
{
	health_ = health;
}

int Player::getNumMoves()
{
	return number_of_moves_;
}

void Player::setNumMoves(int number_of_moves)
{
	number_of_moves_ = number_of_moves;
}

int Player::getPoints()
{
	return points_;
}

void Player::setPoints(int points)
{
	points_ = points;
}

Game::Game()
{
	// Initialize default game object
	board_ = NULL;
	board_size_ = 0;
	game_end_ = false;
	playerX_ = 0;
	playerY_ = 0;
}

Game::Game(int board_size, bool game_end)
{
	// Initialize current game object
	board_ = NULL;
	board_size_ = board_size;
	game_end_ = game_end;
	playerX_ = 0;
	playerY_ = 0;
}

void Game::createBoard()
{   
	// Dynamically allocate board of correct size
	if ((board_ = (char*)realloc(board_, board_size_ * board_size_)) == NULL) {
		cout << "Possible Memory Leak" << endl;
		exit(1);
	}

	// File I/O
	ifstream mazefile;

	switch (board_size_)
	{
	case 4:
		mazefile.open("Maze4.txt");
		break;
	case 5:
		mazefile.open("Maze5.txt");
		break;
	case 6:
		mazefile.open("Maze6.txt");
		break;
	case 7:
		mazefile.open("Maze7.txt");
		break;
	case 8:
		mazefile.open("Maze8.txt");
		break;
	default:
		cout << "Invalid Maze File Opened!" << endl;
		break;
	}

	// Get player starting location
	mazefile >> playerX_ >> playerY_;

	// Set maze from mazefile
	char temp;
	mazefile >> noskipws >> temp;
	for (int i = 0; i < board_size_; i++) {				// Row Loop
		for (int j = 0; j < board_size_; j++) {			// Column Loop
			mazefile >> noskipws >> temp;				// Read each character from file
			*(board_ + i * board_size_ + j) = temp;		// Set character in the maze
		}
		mazefile >> temp;		// Read extra newline
	}

	// Close mazefile
	mazefile.close();
}

void Game::updateBoard(char user_move, Player& player)
{
	// Check for valid user input
	if (user_move != 'w' && user_move != 'a' && user_move != 'd' && user_move != 's') {
		cout << "Invalid Move! Please Try Again!" << endl;
		return;
	}

	// Set next move position
	char* next_location = NULL;
	if (user_move == UP) {
		next_location = board_ + (playerY_ - 1) * board_size_ + playerX_;
	}
	else if (user_move == DOWN) {
		next_location = board_ + (playerY_ + 1) * board_size_ + playerX_;
	}
	else if (user_move == LEFT) {
		next_location = board_ + playerY_ * board_size_ + (playerX_ - 1);
	}
	else if (user_move == RIGHT) {
		next_location = board_ + playerY_ * board_size_ + (playerX_ + 1);
	}

	// Check that next position is valid / not a wall
	if (*(next_location) == WALL) {
		player.setHealth(player.getHealth() - 1);
		return;
	}

	// Check that next position is not the end of the game
	if (*(next_location) == END) {
		game_end_ = true;
		return;
	}

	// Check for chest or end game location
	if (*(next_location) == CHEST) {
		player.setPoints(player.getPoints() + 5);
		*(next_location) = WALL;
		return;
	}

	// Erase previous player location
	*(board_ + playerY_ * board_size_ + playerX_) = PATH;

	// Update new player location;
	if (user_move == UP)
		playerY_--;
	else if (user_move == DOWN)
		playerY_++;
	else if (user_move == LEFT)
		playerX_--;
	else if (user_move == RIGHT)
		playerX_++;
}

void Game::printBoard()
{
	// Set player location
	*(board_ + playerY_ * board_size_ + playerX_) = PLAYER;

	// Print the board
	for (int i = 0; i < board_size_; i++) {
		for (int j = 0; j < board_size_; j++) {
			cout << *(board_ + i * board_size_ + j);
		}
		cout << "\n";
	}
}

int Game::getBoardSize()
{
	return board_size_;
}

void Game::setBoardSize(int board_size)
{
	board_size_ = board_size;
}

bool Game::getGameEnd()
{
	return game_end_;
}

void Game::setGameEnd(bool game_end)
{
	game_end_ = game_end;
}

int Game::getPlayerX()
{
	return playerX_;
}

void Game::setPlayerX(int playerX)
{
	playerX_ = playerX;
}

int Game::getPlayerY()
{
	return playerY_;
}

void Game::setPlayerY(int playerY)
{
	playerY_ = playerY;
}
