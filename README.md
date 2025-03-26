# Tetris-game-project

Tetris Game - C++ Implementation
This is a simple command-line implementation of the classic Tetris game written in C++. The game allows the player to manipulate falling tetrominoes in a grid, clearing lines as they accumulate blocks.

Table of Contents
Game Overview

Table of Contents

Game Controls

Game Features

Usage

Functions

Data Structures Used

Conclusion

Game Overview
In Tetris, the objective is to manipulate tetrominoes (geometric shapes composed of four square blocks) as they fall from the top of the screen. The player must arrange the tetrominoes so that they form complete horizontal lines without gaps. When a line is completed, it disappears, and all lines above it fall down. The game ends when the blocks reach the top of the screen.

Game Controls
Left Arrow (←): Move the current tetromino left.

Right Arrow (→): Move the current tetromino right.

Up Arrow (↑): Rotate the current tetromino.

Down Arrow (↓): Move the current tetromino down (Soft drop).

Spacebar: Hard drop the current tetromino to the bottom of the screen.

Esc: Quit the game.

Game Features
Tetrominoes: The game includes seven different shapes (T, S, Z, I, O, J, and L) that randomly appear one by one.

Grid: The game board is 10 columns wide and 20 rows tall.

Line Clearing: When a full line is detected, it is removed, and the player earns points.

Leveling: The level increases as the player clears lines, making the tetrominoes fall faster.

Score: The player earns points for each line cleared. The score is displayed at the bottom of the game board.

Game Over: The game ends when a tetromino reaches the top of the screen.

Usage
To compile and run this Tetris game, follow the steps below:

On Windows:
Make sure you have a C++ compiler installed, such as g++ from MinGW or Visual Studio.

Open a terminal (Command Prompt or PowerShell).

Save the provided code to a file, for example tetris.cpp.

Compile the program:

bash
Copy
g++ tetris.cpp -o tetris
Run the game:

bash
Copy
./tetris
Functions
Here are the key functions implemented in the Tetris game:

Tetromino::rotate()

Rotates the current tetromino 90 degrees clockwise.

Game::drawBoard()

Clears the screen and redraws the game board, displaying the current tetrominoes and the occupied blocks on the grid.

Game::isCurrentPiece(int row, int col)

Checks if the given row and column are part of the current tetromino piece.

Game::checkCollision(int dx, int dy, vector<vector<int>> shape)

Checks for collisions with the boundaries of the board or other blocks, given a potential movement (dx, dy) or rotated shape.

Game::placeTetromino()

Places the current tetromino on the board after it has landed, and clears any filled lines.

Game::clearLines()

Clears any completed lines from the board and shifts the remaining blocks down.

Game::spawnNew()

Spawns a new tetromino at the top of the screen and checks if it causes a game over condition.

Game::move(int dx)

Moves the current tetromino left or right based on user input.

Game::softDrop()

Moves the current tetromino down one unit, simulating a "soft" drop. If the tetromino cannot move further down, it is placed on the board.

Game::hardDrop()

Drops the current tetromino directly to the bottom of the board.

Game::rotatePiece()

Rotates the current tetromino and checks for collisions after rotation.

Game::run()

Starts and controls the game loop, drawing the board, handling user input, and managing game state.

Game::input()

Reads user input for moving or rotating the tetromino, or quitting the game.

Data Structures Used
The game utilizes the following data structures:

2D Vector for Game Board:

The board is represented as a 2D vector (vector<vector<int>>) with dimensions 10 (width) by 20 (height).

Each cell is either 0 (empty) or 1 (occupied by a block).

cpp
Copy
vector<vector<int>> board;
2D Vector for Tetromino Shapes:

Tetrominoes are represented as a 4x4 matrix, where each cell is either 0 (empty) or 1 (filled block). These shapes are stored in a vector of vectors for each of the 7 different types.

cpp
Copy
vector<vector<vector<int>>> tetrominoShapes;
Tetromino Class:

The Tetromino class holds the current shape of the tetromino and its position (x, y) on the board.

The rotate() function allows for rotating the tetromino, and the class allows for easy manipulation and checking of individual tetrominoes.

cpp
Copy
class Tetromino {
    vector<vector<int>> shape;
    int x, y;
};
Time Management:

To manage the speed of the tetromino falling, the game uses chrono::steady_clock::time_point and chrono::duration to track the time since the last tetromino movement.

cpp
Copy
chrono::steady_clock::time_point lastDropTime;
Conclusion
This implementation of Tetris is a simple and effective way to experience the classic puzzle game on the command line. The game includes basic features like line clearing, scoring, levels, and tetromino rotation. The controls are intuitive and easy to use, making the game accessible to players of all ages.

Key highlights include:

The dynamic speed of falling tetrominoes that increases with the level.

Real-time user input for manipulating tetrominoes.

Clear and concise game logic for detecting collisions, line clears, and handling game-over conditions.

While this implementation uses basic ASCII characters for rendering, it serves as a great foundation for adding more advanced features, such as improved graphics, sound, or enhanced gameplay mechanics.

Feel free to modify or expand on this code to improve or personalize the game further!
