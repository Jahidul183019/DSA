/*
You are given a 2D array (matrix) of size rows × cols containing integers.
Your task is to search for a given element (key) inside the matrix.

If the element exists in the matrix, return its position as a pair (row, col).

If the element does not exist, return (-1, -1).

⚠️ Assume 0-based indexing (first row = 0, first column = 0).

📥 Input Format

First line: two integers rows and cols → number of rows and columns.

Next rows × cols integers → elements of the matrix (row-wise).

Last line: integer key → the element to be searched.

📤 Output Format

Print the pair (row, col) if found.

Otherwise, print -1 -1.
*/

#include <iostream>
using namespace std;

const int MAX = 1000; // maximum size allowed

pair<int, int> linearSearch(int mat[][MAX], int rows, int cols, int key) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == key) {
                return {i, j}; // return row and col
            }
        }
    }
    return {-1, -1}; // not found
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int mat[MAX][MAX];

    // input
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    int key;
    cin >> key;

    pair<int, int> pos = linearSearch(mat, rows, cols, key);

    cout << pos.first << " " << pos.second << endl;

    return 0;
}
