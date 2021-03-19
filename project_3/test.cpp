/**
 * test.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 * Fall 2019
 *
 * Tianjie Qiu
 * tjqiu
 *
 * This is a test function for ohhi.cpp.
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();
void test_cols_are_different();
void test_board_has_no_duplicates();
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_solve_balance_row();
void test_check_valid_input();
void test_check_valid_move();

// declare more test functions here

void startTests() {
    test_count_unknown_squares();
    test_row_has_no_threes_of_color();
    test_cols_are_different();
    test_board_has_no_duplicates();
    test_solve_three_in_a_row();
    test_solve_three_in_a_column();
    test_solve_balance_row();
    test_check_valid_input();
    test_check_valid_move();
    // add your calls to test functions here
}


void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"XOXO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << count_unknown_squares(board, size_1) << endl;

    string test_board_2[] = {"XOXO",
                             "XXOO",
                             "OOOX",
                             "XXOX"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << count_unknown_squares(board, size_2) << endl;

    string test_board_3[] = {"----",
                             "----",
                             "----",
                             "----"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << count_unknown_squares(board, size_3) << endl;
}

void test_row_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];
    
    string test_board_1[] = {"XOOO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << row_has_no_threes_of_color(board, size_1, 0, RED) << endl;
    cout << row_has_no_threes_of_color(board, size_1, 0, BLUE) << endl;
    cout << row_has_no_threes_of_color(board, size_1, 1, RED) << endl;
    cout << row_has_no_threes_of_color(board, size_1, 1, BLUE) << endl;
    cout << row_has_no_threes_of_color(board, size_1, 3, RED) << endl;
    cout << row_has_no_threes_of_color(board, size_1, 3, BLUE) << endl;
    
    string test_board_2[] = {"OO",
                             "OO",
                             "-X",
                             "O-"};
    int size_2 = 2;
    read_board_from_string(board, test_board_2, size_2);
    cout << row_has_no_threes_of_color(board, size_2, 1, RED) << endl;
    cout << row_has_no_threes_of_color(board, size_2, 1, BLUE) << endl;
}

void test_cols_are_different(){
    int board[MAX_SIZE][MAX_SIZE];
    
    string test_board_1[] = {"--OO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << cols_are_different(board, size_1, 0, 1);
    
    string test_board_2[] = {"OOOO",
                             "OOOO",
                             "OO-X",
                             "OOO-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << cols_are_different(board, size_2, 0, 1);
    cout << cols_are_different(board, size_2, 2, 3);
    
    string test_board_3[] = {"XXOO",
                             "XXOO",
                             "XX-X",
                             "XXO-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << cols_are_different(board, size_3, 0, 1);
}

void test_board_has_no_duplicates(){
    int board[MAX_SIZE][MAX_SIZE];
    
    string test_board_1[] = {"--OO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_duplicates(board, 4);
    
    string test_board_2[] = {"O-OO",
                             "X-XO",
                             "X-XX",
                             "O-O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_has_no_duplicates(board, 4);
    
    string test_board_3[] = {"O-OO",
                             "X-XO",
                             "O-XX",
                             "O-O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_has_no_duplicates(board, 4);
}

void test_solve_three_in_a_row(){
    int board[MAX_SIZE][MAX_SIZE];
    
    string test_board_1[] = {"--OO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_row(board, size_1, 0, true);
    print_board(board, size_1);
    
    string test_board_2[] = {"OO--",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    solve_three_in_a_row(board, size_2, 0, true);
        print_board(board, size_1);
    
    string test_board_3[] = {"-OO-",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    solve_three_in_a_row(board, size_3, 0, true);
        print_board(board, size_1);
    
    string test_board_4[] = {"-O-O",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    solve_three_in_a_row(board, size_4, 0, true);
        print_board(board, size_1);
    
    string test_board_5[] = {"-O",
                             "xO"};
    int size_5 = 2;
    read_board_from_string(board, test_board_5, size_5);
    solve_three_in_a_row(board, size_5, 0, true);
        print_board(board, size_5);
}

void test_solve_three_in_a_column(){
    int board[MAX_SIZE][MAX_SIZE];
    
    string test_board_1[] = {"--OO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_column(board, size_1, 0, true);
        print_board(board, size_1);
    
    string test_board_2[] = {"X-OO",
                             "X-OO",
                             "---X",
                             "--O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    solve_three_in_a_column(board, size_2, 0, true);
        print_board(board, size_1);
    
    string test_board_3[] = {"--OO",
                             "--OO",
                             "X--X",
                             "X-O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    solve_three_in_a_column(board, size_3, 0, true);
        print_board(board, size_1);
    
    string test_board_4[] = {"X-OO",
                             "--OO",
                             "X--X",
                             "--O-"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    solve_three_in_a_column(board, size_4, 0, true);
        print_board(board, size_1);
    
    string test_board_5[] = {"-O",
                             "XO"};
    int size_5 = 2;
    read_board_from_string(board, test_board_5, size_5);
    solve_three_in_a_column(board, size_5, 0, true);
        print_board(board, size_5);
}

void test_solve_balance_row(){
    int board[MAX_SIZE][MAX_SIZE];
    
    string test_board_1[] = {"--OO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_balance_row(board, size_1, 0, true);
    print_board(board, size_1);
    
    string test_board_2[] = {"---O",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    solve_balance_row(board, size_2, 0, true);
    print_board(board, size_2);
    
    string test_board_3[] = {"XX-O",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    solve_balance_row(board, size_3, 0, true);
    print_board(board, size_2);
    
    string test_board_4[] = {"----",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_2);
    solve_balance_row(board, size_2, 0, true);
    print_board(board, size_4);
    
    string test_board_5[] = {"-O",
                             "X-"};
    int size_5 = 2;
    read_board_from_string(board, test_board_5, size_5);
    solve_balance_row(board, size_5, 0, true);
    print_board(board, size_5);
}

void test_check_valid_input(){
    int board[MAX_SIZE][MAX_SIZE];
    int row;
    int col;
    
    string test_board_1[] = {"--OO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    check_valid_input(size_1, 0, 'A', 'X', row, col);
    print_board(board, size_1);
    
    string test_board_2[] = {"--OO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    check_valid_input(size_1, 5, 'A', 'X', row, col);
    print_board(board, size_1);
    
    string test_board_3[] = {"--OO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    check_valid_input(size_1, 1, 'F', 'X', row, col);
    print_board(board, size_1);
    
    string test_board_4[] = {"--OO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    check_valid_input(size_1, 1, 'A', 'A', row, col);
    print_board(board, size_1);
    
    string test_board_5[] = {"--OO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    check_valid_input(size_1, 1, 'A', 'O', row, col);
    print_board(board, size_1);
}

void test_check_valid_move(){
    int board1[MAX_SIZE][MAX_SIZE];
       int board2[MAX_SIZE][MAX_SIZE];
    
    string test_board_11[] = {"--OO",
                             "--OO",
                             "---X",
                             "--O-"};
    string test_board_12[] = {"--OO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board1, test_board_11, size_1);
        read_board_from_string(board2, test_board_12, size_1);
    check_valid_move(board1, board2, size_1 , 1, 1, 1);
    print_board(board1, size_1);
        print_board(board2, size_1);
    
    string test_board_21[] = {"--OO",
                             "--OO",
                             "---X",
                             "--O-"};
    string test_board_22[] = {"--OO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_2 = 4;
    read_board_from_string(board1, test_board_21, size_2);
        read_board_from_string(board2, test_board_22, size_1);
    check_valid_move(board1, board2, size_1 , 1, 3, 1);
    print_board(board1, size_1);
        print_board(board2, size_1);
    
    string test_board_31[] = {"--OO",
                             "--OO",
                             "---X",
                             "--O-"};
    string test_board_32[] = {"X-OO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_3 = 4;
    read_board_from_string(board1, test_board_31, size_2);
        read_board_from_string(board2, test_board_32, size_3);
    check_valid_move(board1, board2, size_1 , 1, 1, 2);
    print_board(board1, size_1);
        print_board(board2, size_1);
}
