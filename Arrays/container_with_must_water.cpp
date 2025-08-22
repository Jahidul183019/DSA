//Leetcode 11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*This code will give TLE

int maxArea (vector <int> &height){         //<--------- O(n^2)

    int maxWater = 0; //Ans

    for (int i =0; i < height.size(); i++){

        for (int j = i+1; j < height.size(); j++){

            int w = j-i;
            int ht = min (height [i], height [j]);
            int currWater = w * ht;
            maxWater = max (maxWater, currWater);
        }
    }

    return maxWater;
}*/



//Optimal Approach (2 Pointer)

int maxArea (vector <int> &height){           //<---------- O(n)

    int maxWater = 0; //Ans
    int lp = 0, rp = height.size()-1;

    while (lp < rp){

        int w = rp - lp;
        int ht = min(height[lp], height[rp]);
        int currWater = w * ht;
        maxWater = max(maxWater, currWater);

        height[lp] < height[rp] ? lp++ : rp--;
    }

    return maxWater;
}

int main() {
    int n;
    cout << "Enter number of lines: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter heights: ";
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }

    cout << "Maximum Water Area = " << maxArea(height) << endl;

    return 0;
}
