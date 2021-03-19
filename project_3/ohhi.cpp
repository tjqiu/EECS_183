/**
 * ohhi.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1
 * Fall 2020
 *
 * Tianjie Qiu
 * tjqiu
 *
 * This is a command-line application to read, check, solve and play basic instances of ohhi, a Sudoku-like
 * puzzle game. This will allow you to play a random or custom game, slove a custom game.
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"
#include "driver.h"

/**
 * --------------------------------------------------------
 * ---------- UTILITY FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

// This function counts the number of unkown squares
int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // initialize the counter
    int unknownCount = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // judge whether a square is unknown
            if (board[i][j] == UNKNOWN) {
                ++unknownCount;
            }
        }
    }
    return unknownCount;
}


/**
 * --------------------------------------------------------
 * --------- VALIDITY CHECKING FUNCTIONS ------------------
 * --------------------------------------------------------
 */

// This function judges whether a certain row has consecutive three same
// color square
bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
    bool threeColor = true;
    for (int i = 0; i < size - 2; ++i) {
        // judge whether there are consecutive three square are same color
        if (board[row][i] == color && board[row][i + 1] == color &&
            board[row][i + 2] == color) {
            threeColor = false;
        }
    }
    return threeColor;
}

// This function judges whether a certain column has consecutive
// three same color square
bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    bool threeColor = true;
    for (int i = 0; i < size - 2; ++i) {
        // judge whether there are consecutive three square are same color
        if (board[i][col] == color && board[i + 1][col] == color &&
            board[i + 2][col] == color) {
            threeColor = false;
        }
    }
    
    return threeColor;
}

// This function judges whether a board has consecutive three same color square
bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    bool threeColor = true;
    // go through every row, column and color
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // k indicates the color
            for (int k = 1; k <= 2; ++k) {
                // call two function to check each row and column
                if (!(row_has_no_threes_of_color(board, size, i, k) &&
                      col_has_no_threes_of_color(board, size, j, k))) {
                    threeColor = false;
                }
            }
        }
    }
    
    return threeColor;
}

// This function judges whether two certain rows are different
bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
    bool isDifferent = false;
    for (int i = 0; i < size; ++i) {
        // if there exists UNKOWN, return true
        if (board[row1][i] == UNKNOWN || board[row2][i] == UNKNOWN) {
            isDifferent = true;
        }
        // if there exists difference, return true
        else if (board[row1][i] != board[row2][i]) {
            isDifferent = true;
        }
    }
    return isDifferent;
}

// This function judges whether two certain columns are different
bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    bool isDifferent = false;
    for (int i = 0; i < size; ++i) {
        // if there exists UNKOWN, return true
        if (board[i][col1] == UNKNOWN || board[i][col2] == UNKNOWN) {
            isDifferent = true;
        }
        // if there exists difference, return true
        else if (board[i][col1] != board[i][col2]) {
            isDifferent = true;
        }
    }
    return isDifferent;
}

// This function judges whether two boards have identical row or column
bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    bool noDuplicates = true;
    // go through every row and column
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // judge whether exist identical
            if (i != j && !(rows_are_different(board, size, i, j) &&
                            cols_are_different(board, size, i, j))) {
                noDuplicates = false;
            }
        }
    }
    
    return noDuplicates;
}


/**
 * --------------------------------------------------------
 * ---------- SOLVING FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

// This function solve by avoiding three consecutive same color square
void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    int color;
    // size needs to be larger than 2 to have three consecutive square
    if (size > 2){
        // judge wether the leftmost can be solved
        if (board[row][0] == board[row][1] && size > 2 &&
            board[row][0] != UNKNOWN && board[row][2] == UNKNOWN) {
            board[row][2] = opposite_color(board[row][1]);
            color = opposite_color(board[row][1]);
            // output
            mark_square_as(board, size, row, 2, color, announce);
        }
        //judge whether the rightmost can be solved
        if (board[row][size - 1] == board[row][size - 2] && size > 2 &&
            board[row][size - 1] != UNKNOWN &&
            board[row][size - 3] == UNKNOWN) {
            board[row][size - 3] = opposite_color(board[row][size - 1]);
            color = opposite_color(board[row][size - 1]);
            // output
            mark_square_as(board, size, row, size - 3, color, announce);
        }
        // judge whether the rightmost can be solved, pull this out to
        // combine the below for loop together
        if (board[row][0] == board[row][2] && board[row][1] == UNKNOWN &&
            board[row][0] != UNKNOWN) {
            board[row][1] = opposite_color(board[row][0]);
            color = opposite_color(board[row][0]);
            // output
            mark_square_as(board, size, row, 1, color, announce);
        }
        
        for (int i = 1; i < size - 2; ++i) {
            // solve one in the middle of two same color
            if (board[row][i] == board[row][i + 2] &&
                board[row][i + 1] == UNKNOWN && board[row][i] != UNKNOWN) {
                board[row][i + 1] = opposite_color(board[row][i]);
                color = opposite_color(board[row][i]);
                // output
                mark_square_as(board, size, row, i + 1, color, announce);
            }
            // solve two ends of two consecutive same color
            if (board[row][i] == board[row][i + 1] &&
                board[row][i] != UNKNOWN) {
                // left end
                if (board[row][i - 1] == UNKNOWN) {
                    board[row][i - 1] = opposite_color(board[row][i]);
                    color = opposite_color(board[row][i]);
                    // output
                    mark_square_as(board, size, row, i - 1, color, announce);
                }
                // right end
                if (board[row][i + 2] == UNKNOWN) {
                    board[row][i + 2] = opposite_color(board[row][i]);
                    color = opposite_color(board[row][i]);
                    // output
                    mark_square_as(board, size, row, i + 2, color, announce);
                }
            }
        }
    }
}

// This function solve by avoiding three consecutive same color square
void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    int color;
    // size needs to be larger than 2 to have three consecutive square
    if (size > 2){
        // judge wether the uppermost can be solved
        if (board[0][col] == board[1][col] && size > 2 &&
            board[0][col] != UNKNOWN && board[2][col] == UNKNOWN) {
            board[2][col] = opposite_color(board[1][col]);
            color = opposite_color(board[1][col]);
            // output
            mark_square_as(board, size, 2, col, color, announce);
        }
        //judge whether the lowermost can be solved
        if (board[size - 1][col] == board[size - 2][col] && size > 2 &&
            board[size - 1][col] != UNKNOWN &&
            board[size - 3][col] == UNKNOWN) {
            board[size - 3][col] = opposite_color(board[size - 1][col]);
            color = opposite_color(board[size - 1][col]);
            // output
            mark_square_as(board, size, size - 3, col, color, announce);
        }
        // judge whether the uppermost can be solved, pull this out to combine
        // the below for loop together
        if (board[0][col] == board[2][col] && board[1][col] == UNKNOWN &&
            board[0][col] != UNKNOWN) {
            board[1][col] = opposite_color(board[0][col]);
            color = opposite_color(board[0][col]);
            // output
            mark_square_as(board, size, 1, col, color, announce);
        }
        for (int i = 1; i < size - 2; ++i) {
            // solve one in the middle of two same color
            if (board[i][col] == board[i + 2][col] &&
                board[i + 1][col] == UNKNOWN && board[i][col] != UNKNOWN) {
                board[i + 1][col] = opposite_color(board[i][col]);
                color = opposite_color(board[i][col]);
                // output
                mark_square_as(board, size, i + 1, col, color, announce);
            }
            // solve two ends of two consecutive same color
            if (board[i][col] == board[i + 1][col] &&
                board[i][col] != UNKNOWN) {
                // upper end
                if (board[i - 1][col] == UNKNOWN) {
                    board[i - 1][col] = opposite_color(board[i][col]);
                    color = opposite_color(board[i][col]);
                    // output
                    mark_square_as(board, size, i - 1, col, color, announce);
                }
                // lower end
                if (board[i + 2][col] == UNKNOWN) {
                    board[i + 2][col] = opposite_color(board[i][col]);
                    color = opposite_color(board[i][col]);
                    // output
                    mark_square_as(board, size, i + 2, col, color, announce);
                }
            }
        }
    }
}


// solve by consider the equal number of two color in a certain row
void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    int redCount = 0;
    int blueCount = 0;
    int color;
    // count the color
    for (int i = 0; i < size; ++i) {
        if (board[row][i] == BLUE) {
            ++blueCount;
        }
        else if (board[row][i] == RED) {
            ++redCount;
        }
    }
    // if blue is half
    if (blueCount == size / 2) {
        for (int j = 0; j < size; ++j) {
            if (board[row][j] == UNKNOWN) {
                board[row][j] = RED;
                color = RED;
                // output
                mark_square_as(board, size, row, j, color, announce);
            }
        }
    }
    // if red is half
    else if (redCount == size / 2) {
        for (int j = 0; j < size; ++j) {
            if (board[row][j] == UNKNOWN) {
                board[row][j] = BLUE;
                color = BLUE;
                // output
                mark_square_as(board, size, row, j, color, announce);
            }
        }
    }
}

// solve by consider the equal number of two color in a certain column
void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    int redCount = 0;
    int blueCount = 0;
    int color;
    // count the color
    for (int i = 0; i < size; ++i) {
        if (board[i][col] == BLUE) {
            ++blueCount;
        }
        else if (board[i][col] == RED) {
            ++redCount;
        }
    }
    // if blue is half
    if (blueCount == size / 2) {
        for (int j = 0; j < size; ++j) {
            if (board[j][col] == UNKNOWN) {
                board[j][col] = RED;
                color = RED;
                // output
                mark_square_as(board, size, j, col, color, announce);
            }
        }
    }
    // if red is half
    else if (redCount == size / 2) {
        for (int j = 0; j < size; ++j) {
            if (board[j][col] == UNKNOWN) {
                board[j][col] = BLUE;
                color = BLUE;
                // output
                mark_square_as(board, size, j, col, color, announce);
            }
        }
    }
}



/**
 * --------------------------------------------------------
 * ---------- GAMEPLAY FUNCTIONS --------------------------
 * --------------------------------------------------------
 */

// this function judges whether a board is solved
bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    bool isSolved = true;
    // check whether exists unknown square
    if (count_unknown_squares(board, size) > 0) {
        isSolved = false;
    }
    // judge whether break the rule
    if (!board_is_valid(board, size)) {
        isSolved = false;
    }
    return isSolved;
}

// this function judges whether an input is valid
bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    bool isValid = true;
    // decide whether row and column is within range
    if (row_input < 1 || row_input > size || toupper(col_input) < 'A' ||
        toupper(col_input) - 64 > size) {
        isValid = false;
    }
    // decide whether color is within range
    else if (!(toupper(color_char) == UNKNOWN_LETTER ||
               toupper(color_char) == RED_LETTER ||
               toupper(color_char) == BLUE_LETTER)) {
        isValid = false;
    }
    if (isValid == false) {
        // output if invalid
        cout << "Sorry, that's not a valid input." << endl;
    }
    else {
        // if valid, convert the input
        row = row_input - 1;
        col = toupper(col_input) - 65;
    }
    return isValid;
}

// this function judges whether a move is valid
bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    bool isValid = true;
    int copyBoard[MAX_SIZE][MAX_SIZE];
    // cannot change colored square on original board
    if (original_board[row][col] != UNKNOWN) {
        isValid = false;
        cout<< "Sorry, original squares cannot be changed." << endl;
    }
    else {
        // copy the current board
        copy_board(current_board, copyBoard, size);
        copyBoard[row][col] = color;
        // call functions to check rules
        if (!board_is_valid(copyBoard, size)) {
            isValid = false;
            cout << "Sorry, that move violates a rule." << endl;
        }
    }
    return isValid;
}
