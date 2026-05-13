#include <iostream>
#include <vector>

using namespace std;

void subsets(string &s, int idx, string curr) {
    if (idx == s.size()) {
        cout << curr << endl;
        return;
    }

    // include current character
    subsets(s, idx + 1, curr + s[idx]);

    // exclude current character
    subsets(s, idx + 1, curr);
}

int main() {
    string s;
    cin >> s;

    subsets(s, 0, "");

    return 0;
}