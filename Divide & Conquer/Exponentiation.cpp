// https://cses.fi/problemset/task/1095

#include <iostream>

using namespace std;

#define ll long long

const ll M = 1000000007;
ll powerMod(ll A, ll k) {
  if (k == 0)
    return 1;

  if (k % 2 == 0) {
    ll half = powerMod(A, k / 2);

    return (half * half) % M;
  } else {
    ll half = powerMod(A, (k - 1) / 2);

    return ((A % M) * ((half * half) % M)) % M;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long A, k;

    cin >> A >> k;

    cout << powerMod(A, k) << endl;
  }

  return 0;
}
