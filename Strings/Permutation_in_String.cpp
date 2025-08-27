//Leetcode 567
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isFreqSame(int freq1[],int freq2[]){//O(1)
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};

        for(int i=0;i<s1.length();i++){
            freq[s1[i]-'a']++;
        }

        int winSize=s1.length();

        for(int i=0;i<s2.length();i++){
            int windIdx=0,idx=i;

            int windFreq[26]={0};

            while(windIdx<winSize && idx<s2.length()){
                windFreq[s2[idx]-'a']++;
                windIdx++; idx++;
            }
            if(isFreqSame(freq,windFreq)){//found
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    string s1, s2;

    cout << "Enter s1: ";
    cin >> s1;
    cout << "Enter s2: ";
    cin >> s2;

    bool result = sol.checkInclusion(s1, s2);

    if(result){
        cout << "s2 contains a permutation of s1" << endl;
    } else {
        cout << "s2 does NOT contain a permutation of s1" << endl;
    }

    return 0;
}
