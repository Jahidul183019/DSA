#include <iostream>
using namespace std;

void allPoss(string &s, string curr) {
    if (curr.size() == s.size()) {
        cout << curr << endl;
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        allPoss(s, curr + s[i]);
    }
}

int main() {
    string s;
    cin >> s;

    allPoss(s, "");

    return 0;
}