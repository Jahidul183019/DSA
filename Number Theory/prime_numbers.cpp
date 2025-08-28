#include <iostream>
using namespace std;

string isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return "Non Prime";
        }
    }
    return "Prime";
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << isPrime(n) << endl;

    return 0;
}