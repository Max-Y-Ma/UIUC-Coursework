#include "maze.h"
using namespace std;

int main() {
	// User input variables
	char user_movement;	// User movement input
	char user_input;	// User input
	int board_size = 0;		// User input board size
	int game_difficulty = 0;	// User input game difficulty

	// Main Game Loop
	do {
		// Take user input for the board size
		do {
			cout << "Enter Board Size (4 <-> 8): ";
			cin >> board_size;
		} while (board_size < 4 || board_size > 8);

		// Take user input for the game difficulty
		do {
			cout << "Enter Difficulty (1 = HARD, 2 = MEDIUM, 3 = EASY): ";
			cin >> game_difficulty;
		} while (game_difficulty < 1 || game_difficulty > 3);

		// Create game and player objects
		Game game(board_size, false);
		Player player(game_difficulty);

		// Create game board
		game.createBoard();

		// Start Game Message
		cout << "------------------------------------------------------" << endl;
		cout << "It's Time! The Game will Begin!" << endl;

		// Print inital board
		cout << "------------------------------------------------------" << endl;
		cout << "-------------- Press 'r' to reset board --------------" << endl;
		cout << "--- " << "Health: " << player.getHealth()
			<< " --- Number of Moves: " << player.getNumMoves()
			<< " --- Points: " << player.getPoints() << " ---" << endl;
		cout << "------------------------------------------------------\n" << endl;
		game.printBoard();

		do {
			// Take in user input during the game
			cout << "\nMake a move: ";
			cin >> user_movement;
		
			// Update and print new board
			cout << "------------------------------------------------------" << endl;
			cout << "-------------- Press 'r' to reset board --------------" << endl;
			cout << "--- " << "Health: "  << player.getHealth() 
				<< " --- Number of Moves: " << player.getNumMoves() 
				<< " --- Points: " << player.getPoints() << " ---" << endl;
			cout << "------------------------------------------------------\n" << endl;
			game.updateBoard(user_movement, player);
			game.printBoard();
			player.setNumMoves(player.getNumMoves() + 1);
		} while (user_movement != 'r' && game.getGameEnd() != true && player.getHealth() != -1);	// 'R' is to reset the game



		// Reset Game Message
		cout << "Press 'q' to Quit!" << endl;
		cout << "Press any key to start a new game!" << endl;

		// Read User Input
		cin >> user_input;

	} while (user_input != 'q');

	// Final Message
	cout << "The Game has Finished!" << endl;

	// Return 0
	return 0;
}