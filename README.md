# Tetris-game-project

# Tetris Game - C++ Implementation



## Table of Contents
1. [Overview](#overview)
2. [Usage](#usage)
3. [Game Features](#game-features)
4. [Functions Used](#functions-used)
5. [Data Structures Used](#data-structures-used)
6. [Conclusion](#conclusion)

---

## Overview
This project is a simple implementation of the classic Tetris game in C++ using a console-based interface. Players can manipulate Tetromino pieces to clear lines, earning points and progressing through levels as the game speed increases.

---

## Usage
To play the game:
1. Clone this repository:
    bash
    git clone <repository-url>
    
2. Compile the source code:
    bash
    g++ -o tetris TetrisGame.cpp
    
3. Execute the compiled program:
    bash
    ./TetrisGame
    
4. Use the controls listed below during gameplay:
    - *Left Arrow*: Move the Tetromino piece left
    - *Right Arrow*: Move the Tetromino piece right
    - *Up Arrow*: Rotate the Tetromino piece
    - *Down Arrow*: Soft drop
    - *Spacebar*: Hard drop
    - *Escape (ESC)*: Exit the game

---
![WhatsApp Image 2025-03-28 at 12 40 08_8501f8ee](https://github.com/user-attachments/assets/73949ee3-9e8e-4032-8431-b8f27fd9f22e)



## Game Features
1. *Tetromino Shapes*:
   - The game includes seven standard Tetromino shapes: T, S, Z, I, O, J, L.

2. *Dynamic Difficulty*:
   - As players clear lines, the game increases speed by moving to higher levels.

3. *Collision Detection*:
   - Pieces cannot overlap, move beyond the board's boundaries, or descend into occupied rows.

4. *Scoring Mechanism*:
   - Earn 100 points for each cleared line. Progress in levels by clearing lines consistently.

5. *Game Over Condition*:
   - The game ends when a Tetromino cannot be placed at the spawn point.

---

## Functions Used
### Key Methods in Classes:
- void drawBoard(): Draws the current state of the game board in the console.
- bool isCurrentPiece(int row, int col): Determines if a cell is occupied by the current Tetromino.
- bool checkCollision(int dx, int dy, vector<vector<int>> shape): Detects boundary and placement collisions.
- void placeTetromino(): Places the current Tetromino piece on the board and clears lines.
- void clearLines(): Removes full rows from the board and updates the score and level.
- void spawnNew(): Generates a new Tetromino piece at the spawn position.
- void move(int dx): Moves the Tetromino horizontally.
- void softDrop(): Moves the Tetromino one step downward.
- void hardDrop(): Drops the Tetromino to its lowest possible position immediately.
- void rotatePiece(): Rotates the current Tetromino piece, ensuring valid placement.
- void run(): Manages the main game loop, rendering, and inputs.
- void input(): Processes keyboard input for player commands.

---

## Data Structures Used
### Key Constructs:
1. **vector<vector<int>>**:
   - Represents the game board and Tetromino shapes as 2D grids.

2. **class Tetromino**:
   - Defines the attributes and behaviors of a single Tetromino piece, including rotation.

3. **class Game**:
   - Contains the main logic for gameplay, input handling, and the core game loop.

  

---

## Conclusion
This console-based Tetris implementation showcases essential programming principles such as object-oriented design, collision detection, and real-time input handling. It's a great learning tool for developing interactive games with C++. Contributions and feedback are welcome to enhance its features further.

---
