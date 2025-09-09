#include <iostream>
using namespace std;

const int MAX = 1000; // maximum size allowed

bool linearSearch(int mat[][MAX], int rows, int cols, int key) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == key) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int mat[MAX][MAX];  // allocate large enough array

    // input
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    int key;
    cin >> key;

    cout << (linearSearch(mat, rows, cols, key) ? "Found" : "Not Found") << endl;

    return 0;
}
