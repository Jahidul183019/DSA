//Leetcode 238

#include <iostream>
#include <vector>
using namespace std;

/*This will give TLE

vector <int> productExceptself (vector <int> &nums){            //<--------- O(n^2)

    int n = nums.size();

    for(int i = 0; i < n; i++)[

        for(int j = 0; j < n; j++){

            if(i != j){
                ans[i] *= nums[j];
            }
        }
    ]

    return ans;
}*/


//Optimal --------> TC O(n) and SC O(1)

/*This has TC O(n) and SC O(n)

vector <int> productExceptself (vector <int> &nums){           //<-------- TC O(n) and SC O(n)

    int n = nums.size();
    vector <int> ans (n, 1);
    vector <int> prefix (n, 1);
    vector <int> suffix (n, 1);

    //Prefix
    for(int i = 1; i < n; i++){
        prefix[i] = prefix [i-1] * nums [i-1];
    }

    //Suffix
    for(int i = n-2; i >= 0; i--){
        suffix[i] = suffix[i+1] * nums [i+1];
    }

    for(int i = 0; i<n; i++){
        ans[i] = prefix[i] * suffix[i];
    }

    return ans;
}*/

/*This has TC O(n) and SC O(1)*/

vector<int> productExceptself (vector<int> &nums){           //<-------- TC O(n) and SC O(1)

    int n = nums.size();
    vector<int> ans(n, 1);

    // Prefix --> ans
    for(int i = 1; i < n; i++){
        ans[i] = ans[i-1] * nums[i-1];
    }

    int suffix = 1;

    // Suffix
    for(int i = n-2; i >= 0; i--){
        suffix *= nums[i+1]; // i-th suffix
        ans[i] *= suffix;
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<int> result = productExceptself(nums);

    cout << "Product of array except self: ";
    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
