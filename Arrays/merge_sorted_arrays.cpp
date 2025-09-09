#include <iostream>
#include <vector>
using namespace std;

//    Merge Sorted Arrays Problem
//    Leetcode Problem 88

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) { //O(1) SC & O(m+n) TC
        int idx = m + n - 1, i = m - 1, j = n - 1;

        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j]) {
                A[idx--] = A[i--];
            } else {
                A[idx--] = B[j--];
            }
        }

        while (j >= 0) {
            A[idx--] = B[j--];
        }
    }
};

int main() {
    int m, n;
    cout << "Enter size of first array (m): ";
    cin >> m;
    cout << "Enter elements of first array: ";
    vector<int> A(m + 100); // extra space to accommodate B, adjust if needed
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }

    cout << "Enter size of second array (n): ";
    cin >> n;
    cout << "Enter elements of second array: ";
    vector<int> B(n);
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    Solution sol;
    sol.merge(A, m, B, n);

    cout << "Merged Array: ";
    for (int i = 0; i < m + n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
