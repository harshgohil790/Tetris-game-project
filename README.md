# Tetris-game-project

# Tetris Game - C++ Implementation

This is a simple command-line implementation of the classic Tetris game written in C++. The game allows the player to manipulate falling tetrominoes in a grid, clearing lines as they accumulate blocks.

## Table of Contents

1. [Game Overview](#game-overview)
2. [Game Controls](#game-controls)
3. [Game Features](#game-features)
4. [Usage](#usage)
5. [Functions](#functions)
6. [Data Structures Used](#data-structures-used)
7. [Conclusion](#conclusion)

## Game Overview

In Tetris, the objective is to manipulate tetrominoes (geometric shapes composed of four square blocks) as they fall from the top of the screen. The player must arrange the tetrominoes so that they form complete horizontal lines without gaps. When a line is completed, it disappears, and all lines above it fall down. The game ends when the blocks reach the top of the screen.

## Game Controls

- *Left Arrow (←)*: Move the current tetromino left.
- *Right Arrow (→)*: Move the current tetromino right.
- *Up Arrow (↑)*: Rotate the current tetromino.
- *Down Arrow (↓)*: Move the current tetromino down (Soft drop).
- *Spacebar*: Hard drop the current tetromino to the bottom of the screen.
- *Esc*: Quit the game.

## Game Features

- *Tetrominoes*: The game includes seven different shapes (T, S, Z, I, O, J, and L) that randomly appear one by one.
- *Grid*: The game board is 10 columns wide and 20 rows tall.
- *Line Clearing*: When a full line is detected, it is removed, and the player earns points.
- *Leveling*: The level increases as the player clears lines, making the tetrominoes fall faster.
- *Score*: The player earns points for each line cleared. The score is displayed at the bottom of the game board.
- *Game Over*: The game ends when a tetromino reaches the top of the screen.

## Usage

To compile and run this Tetris game, follow the steps below:

### On Windows:
1. Make sure you have a C++ compiler installed, such as *g++* from MinGW or Visual Studio.
2. Open a terminal (Command Prompt or PowerShell).
3. Save the provided code to a file, for example tetris.cpp.
4. Compile the program:
   ```bash
   g++ tetris.cpp -o tetris
