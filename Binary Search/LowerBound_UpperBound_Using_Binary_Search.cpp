#include <iostream>
using namespace std;

int lower_bound(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int ans = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int upper_bound(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int ans = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > target) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cin >> target;

    int lb = lower_bound(arr, n, target);
    int ub = upper_bound(arr, n, target);

    cout << "Lower Bound Index: " << lb << endl;
    cout << "Upper Bound Index: " << ub << endl;
    cout << "Frequency: " << ub - lb << endl;

    return 0;
}
