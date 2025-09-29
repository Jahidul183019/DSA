#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// Time Complexity of countSort: O(n + k) where k = 10 (digits)
// Space Complexity of countSort: O(n + k) = O(n) since k is constant
void countSort(vector<int>& arr, int pos) {
    int n = arr.size();

    vector<int> freq(10, 0); // k = 10 digits

    // Counting occurrences of each digit
    for (int i = 0; i < n; i++) {
        freq[(arr[i] / pos) % 10]++;
    }

    // Cumulative frequency
    for (int i = 1; i < 10; i++) {
        freq[i] += freq[i - 1];
    }

    vector<int> ans(n);

    // Building sorted array (stable sort)
    for (int i = n - 1; i >= 0; i--) {
        ans[--freq[(arr[i] / pos) % 10]] = arr[i];
    }

    // Copy back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }
}

// Time Complexity of radixSort: O(d * (n + k)), where
// n = number of elements, k = 10, d = number of digits in max element
// Space Complexity: O(n + k) = O(n)
void radixSort(vector<int>& arr) {
    int max_elem = INT_MIN;

    for (auto x : arr) {
        max_elem = max(x, max_elem); // Finding max element
    }

    // Run countSort for each digit position
    for (int pos = 1; max_elem / pos > 0; pos *= 10) {
        countSort(arr, pos);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    radixSort(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
Time Complexity:
- Worst case: O(d*(n + k))
  Where:
    n = number of elements
    k = 10 (digits)
    d = number of digits in the maximum element
- Since k = 10 is constant, complexity is often written as O(d*n)

Space Complexity:
- O(n + k) = O(n) (because k = 10 is constant)
*/
