# Tetris-game-project

Tetris Game - C++ Implementation
This is a simple command-line implementation of the classic Tetris game written in C++. The game allows the player to manipulate falling tetrominoes in a grid, clearing lines as they accumulate blocks.

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

Line Clearing: When a horizontal line is completely filled with blocks, it disappears, and the player earns points.

Leveling: The level increases as the player clears lines, making the tetrominoes fall faster.

Score: The player earns points for each line cleared. The score is displayed at the bottom of the game board.

Implementation
1. Tetrominoes
The tetrominoes are represented as 4x4 matrices, each containing values that correspond to the blocks of the tetromino. There are seven types of tetrominoes, and each type is initialized as a 4x4 grid. The tetrominoes are represented as vector<vector<int>>, where 1 indicates a block and 0 represents an empty space.

2. Game Board
The game board is a 2D vector (vector<vector<int>>) with dimensions 10 (width) by 20 (height). Each element in the board is either 0 (empty) or 1 (occupied by a block).

3. Game Logic
Collision Checking: Before moving or rotating a tetromino, the game checks for collisions with the borders of the board or with other placed blocks.

Line Clearing: When a full line is detected, it is removed, and all lines above it shift down.

Leveling: Every 5 lines cleared, the game level increases. Higher levels make tetrominoes fall faster.

Game Over: The game ends when a new tetromino cannot be placed because the board is already filled to the top.

4. User Input
The game uses the conio.h library to capture real-time keyboard input. The user can control the tetrominoes with the arrow keys and other keys as mentioned above. The input is processed continuously in a loop during the game.

5. Rendering
The game board is redrawn every frame using the system("cls") command to clear the screen (works for Windows). The tetrominoes and the board are displayed in the console using ASCII characters (# for blocks and space for empty spots).

6. Game Speed
The tetrominoes fall at a rate determined by the level. As the player progresses through levels, the tetrominoes fall faster, increasing the game's difficulty.

How to Play
Start the game: When you run the program, the game will begin automatically.

Control the tetrominoes: Use the arrow keys to move, rotate, or drop the current tetromino.

Clear lines: Arrange the tetrominoes to form complete horizontal lines. The more lines you clear, the higher your score.

Game Over: The game ends when a tetromino reaches the top of the screen. The final score is displayed, and you can press Esc to quit.

Compiling and Running the Game
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
Known Issues
The game currently works best in a Windows command prompt (due to the use of system("cls") for screen clearing).

It may not run as expected on non-Windows platforms without modification (e.g., system("cls") is Windows-specific).

License
This code is released under the MIT License. Feel free to modify and use it for personal or educational purposes.
