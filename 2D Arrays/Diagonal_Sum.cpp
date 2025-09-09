/*
#include <iostream>
#include <vector>

using namespace std;

int diagonalSum(vector<vector<int>> mat, int n) {
    int sum=0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i==j){
                sum+=mat[i][j];
            }else if(j==n-i-1){
                sum+=mat[i][j];
            }
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n ;

    vector<vector<int>> mat(n, vector<int>(n));

    // input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    cout << diagonalSum(mat,n) << endl;

    return 0;
}
*/

                               //Efficient Way

#include <iostream>
#include <vector>

using namespace std;

int diagonalSum(vector<vector<int>> mat, int n) {//TC:O(n)
    int sum=0;
    //Primary Diagonal : j=i
    //Secondary Diagonal : j=n-i-1
    for (int i = 0; i < n; i++) {
                sum+=mat[i][i];
             if(i!=n-i-1){
                sum+=mat[i][n-i-1];
            }
        }
    return sum;
}

int main() {
    int n;
    cin >> n ;

    vector<vector<int>> mat(n, vector<int>(n));

    // input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    cout << diagonalSum(mat,n) << endl;

    return 0;
}