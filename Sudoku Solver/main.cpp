#include <bits/stdc++.h>

using namespace std;

void printGrid(int grid[9][9]){
    for(int i=0 ; i<9 ; i++){
        for(int j=0 ; j<9 ; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

bool isValid(int grid[9][9], int row, int col, int num){
    for(int i=0 ; i<9 ; i++){
        if(grid[row][i] == num || grid[i][col] == num || grid[3*(row/3) + i/3][3*(col/3) + i%3] == num){
            return false;
        }
    }
    return true;
}

bool checkGrid(int grid[9][9]){
    for(int i=0 ; i<9 ; i++){
        for(int j=0 ; j<9 ; j++){
            if(grid[i][j] != 0){
                int num = grid[i][j];
                grid[i][j] = 0;
                if(!isValid(grid, i, j, num)){
                    grid[i][j] = num;
                    return false;
                }
                grid[i][j] = num;
            }
        }
    }
    return true;
}

bool solveSudoku(int grid[9][9]){
    int row, col;
    bool isEmpty = false;
    for(int i=0 ; i<9 ; i++){
        for(int j=0 ; j<9 ; j++){
            if(grid[i][j] == 0){
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if(isEmpty) break;
    }
    if(!isEmpty) return true;

    for(int num = 1 ; num <= 9 ; num++){
        if(isValid(grid, row, col, num)){
            grid[row][col] = num;
            if(solveSudoku(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int option, level, grid[9][9];
    cout << "===================" << endl;
    cout << "   Sudoku Solver   " << endl;
    cout << "===================" << endl << endl;

    cout << "1. Enter a custom Sudoku grid\n2. Select a pre-defined grid\nPlease choose an option: ";
    while(cin >> option){
        if(option == 1){
            cout << "\nEnter your Sudoku grid (use 0 for empty cells):\n";
            for(int i=0 ; i<9 ; i++){
                for(int j=0 ; j<9 ; j++){
                    cin >> grid[i][j];
                }
            }
            break;
        }
        else if(option == 2){
           cout << "\n1. Easy\n2. Medium\n3. Hard\nSelect a difficulty level: ";
            while(cin >> level){
                if(level == 1){
                    int grid1[9][9] = {
                        {5, 3, 0, 0, 7, 0, 0, 0, 0},
                        {6, 0, 0, 1, 9, 5, 0, 0, 0},
                        {0, 9, 8, 0, 0, 0, 0, 6, 0},
                        {8, 0, 0, 0, 6, 0, 0, 0, 3},
                        {4, 0, 0, 8, 0, 3, 0, 0, 1},
                        {7, 0, 0, 0, 2, 0, 0, 0, 6},
                        {0, 6, 0, 0, 0, 0, 2, 8, 0},
                        {0, 0, 0, 4, 1, 9, 0, 0, 5},
                        {0, 0, 0, 0, 8, 0, 0, 7, 9}
                    };
                    memcpy(grid, grid1, 9 * 9 * sizeof(int));
                    break;
                }
                else if(level == 2){
                    int grid2[9][9] = {
                        {0, 0, 0, 6, 0, 0, 4, 0, 0},
                        {7, 0, 0, 0, 0, 3, 6, 0, 0},
                        {0, 0, 0, 0, 9, 1, 0, 8, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 5, 0, 1, 8, 0, 0, 0, 3},
                        {0, 0, 0, 3, 0, 6, 0, 4, 5},
                        {0, 4, 0, 2, 0, 0, 0, 6, 0},
                        {9, 0, 3, 0, 0, 0, 0, 0, 0},
                        {0, 2, 0, 0, 0, 0, 1, 0, 0}
                    };
                    memcpy(grid, grid2, 9 * 9 * sizeof(int));
                    break;
                }
                else if(level == 3){
                    int grid3[9][9] = {
                        {0, 0, 0, 0, 0, 0, 0, 1, 2},
                        {0, 0, 0, 0, 0, 7, 0, 0, 0},
                        {5, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 3, 0, 8, 0, 0, 0},
                        {0, 0, 4, 0, 7, 0, 0, 0, 0},
                        {0, 0, 0, 9, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 0, 0, 6, 0},
                        {0, 0, 0, 4, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 3, 0, 0}
                    };
                    memcpy(grid, grid3, 9 * 9 * sizeof(int));
                    break;
                }
                else{
                    cout << "Invalid selection. Please try again: ";
                }
            }
            break;
        }
        else{
            cout << "Invalid choice. Please try again: ";
        }
    }

    if(option == 1){
        if(checkGrid(grid)){
            if(solveSudoku(grid)){
                cout << "\nSolved Sudoku Grid:\n";
                printGrid(grid);
            }
        }
        else{
            cout << "\nNo solution exists!" << endl;
        }
    }
    else{
        cout << "\nInitial Sudoku Grid:\n";
        printGrid(grid);
        if(solveSudoku(grid) && checkGrid(grid)) {
            cout << "\nSolved Sudoku Grid:\n";
            printGrid(grid);
        }
        else{
            cout << "No solution exists!" << endl;
        }
    }

    return 0;
}
