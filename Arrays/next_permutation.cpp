#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//   Next Permutation Problem
//   Leetcode Problem 31

class Solution {
public:
    void nextPermutation(vector<int>& A) { //TC : O(n) & SC : O(1)
        int pivot = -1, n = A.size();

        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) {
            reverse(A.begin(), A.end());
            return;
        }

        for (int i = n - 1; i > pivot; i--) {
            if (A[i] > A[pivot]) {
                swap(A[i], A[pivot]);
                break;
            }
        }

        int i = pivot + 1, j = n - 1;
        while (i <= j) {
            swap(A[i++], A[j--]);
        }
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    Solution sol;
    sol.nextPermutation(A);

    cout << "Next Permutation: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}

                              // Using STL
/*
class Solution {
public:
    void nextPermutation(vector<int>& A) { //TC : O(1) & SC : O(1)
        next_permutation(A.begin(), A.end());
    }
};
*/