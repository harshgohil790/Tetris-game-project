#include <iostream>
#include <vector>
#include <conio.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <windows.h>  // For setting console text color

using namespace std;

const int WIDTH = 10;
const int HEIGHT = 20;

// Tetromino shapes with colors
vector<vector<vector<int>>> tetrominoShapes = {
    {{1,1,1,0}, {0,1,0,0}, {0,0,0,0}, {0,0,0,0}}, // T
    {{0,1,1,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}}, // S
    {{1,1,0,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}}, // Z
    {{1,0,0,0}, {1,0,0,0}, {1,0,0,0}, {1,0,0,0}}, // I
    {{1,1,0,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}}, // O
    {{0,1,0,0}, {0,1,0,0}, {1,1,0,0}, {0,0,0,0}}, // J
    {{1,0,0,0}, {1,0,0,0}, {1,1,0,0}, {0,0,0,0}}  // L
};

// Define colors for shapes 
vector<int> shapeColors = {5, 2, 4, 3, 6, 1, 14}; // T, S, Z, I, O, J, L

// Function to set console text color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

class Tetromino {
public:
    vector<vector<int>> shape;
    int x, y, type;

    Tetromino(int type) {
        this->type = type;
        shape = tetrominoShapes[type];
        x = WIDTH / 2 - 2;
        y = 0;
    }

    void rotate() {
        vector<vector<int>> rotated(4, vector<int>(4, 0));
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                rotated[i][j] = shape[3 - j][i];
        shape = rotated;
    }
};

class Game {
private:
    vector<vector<int>> board;
    Tetromino* current;
    int score = 0;
    int level = 1;
    int linesCleared = 0;
    bool isGameOver = false;
    chrono::steady_clock::time_point lastDropTime;

public:
    Game() {
        board = vector<vector<int>>(HEIGHT, vector<int>(WIDTH, 0));
        srand(time(0));
        current = new Tetromino(rand() % 7);
        lastDropTime = chrono::steady_clock::now();
    }

    void drawBoard() {
        system("cls");
        for (int i = 0; i < HEIGHT; ++i) {
            cout << "|";
            for (int j = 0; j < WIDTH; ++j) {
                if (isCurrentPiece(i, j)) {
                    setColor(shapeColors[current->type]);
                    cout << "#";
                } else if (board[i][j]) {
                    setColor(7); // Set default color for placed blocks
                    cout << "#";
                } else {
                    setColor(7);
                    cout << " ";
                }
            }
            setColor(7);
            cout << "|" << endl;
        }
        for (int i = 0; i < WIDTH + 2; ++i) cout << "=";
        cout << "\nScore: " << score << "  Level: " << level << endl;
    }

    bool isCurrentPiece(int row, int col) {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (current->shape[i][j] && current->y + i == row && current->x + j == col)
                    return true;
        return false;
    }

    bool checkCollision(int dx, int dy, vector<vector<int>> shape = {}) {
        if (shape.empty()) shape = current->shape;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (shape[i][j]) {
                    int newX = current->x + j + dx;
                    int newY = current->y + i + dy;
                    if (newX < 0 || newX >= WIDTH || newY >= HEIGHT || (newY >= 0 && board[newY][newX]))
                        return true;
                }
        return false;
    }

    void placeTetromino() {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (current->shape[i][j]) {
                    int newX = current->x + j;
                    int newY = current->y + i;
                    if (newY >= 0) board[newY][newX] = 1;
                }
        clearLines();
        spawnNew();
    }

    void clearLines() {
        int lines = 0;
        for (int i = HEIGHT - 1; i >= 0; --i) {
            bool full = true;
            for (int j = 0; j < WIDTH; ++j)
                if (!board[i][j]) full = false;
            if (full) {
                lines++;
                for (int k = i; k > 0; --k) board[k] = board[k - 1];
                board[0] = vector<int>(WIDTH, 0);
                i++;
            }
        }
        if (lines > 0) {
            score += lines * 100;
            linesCleared += lines;
            if (linesCleared >= level * 5) level++;
        }
    }

    void spawnNew() {
        current = new Tetromino(rand() % 7);
        if (checkCollision(0, 0)) isGameOver = true;
    }

    void move(int dx) {
        if (!checkCollision(dx, 0)) current->x += dx;
    }

    void softDrop() {
        if (!checkCollision(0, 1)) {
            current->y++;
        } else {
            placeTetromino();
        }
    }

    void hardDrop() {
        while (!checkCollision(0, 1)) current->y++;
        placeTetromino();
    }

    void rotatePiece() {
        auto temp = current->shape;
        current->rotate();
        if (checkCollision(0, 0, current->shape)) current->shape = temp;
    }

    void run() {
        while (!isGameOver) {
            drawBoard();
            input();

            auto now = chrono::steady_clock::now();
            chrono::duration<float> elapsed = now - lastDropTime;

            if (elapsed.count() >= (1.0f / level)) {
                softDrop();
                lastDropTime = now;
            }
        }
        cout << "\nGame Over! Final Score: " << score << endl;
    }

    void input() {
        if (_kbhit()) {
            char ch = _getch();
            switch (ch) {
                case 75: move(-1); break;
                case 77: move(1);  break;
                case 72: rotatePiece(); break;
                case 80: softDrop(); break;
                case 32: hardDrop(); break;
                case 27: isGameOver = true; break;
            }
        }
    }
};

int main() {
    Game game;
    game.run();
    return 0;
}

