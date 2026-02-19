#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double EPS = 1e-9;

int main() {
    double x;
    cin >> x;
    
    double st = 0;
    double end = x;
    double mid;

    while (end - st > EPS) {
        mid = st + (end - st) / 2.0;

        if (mid * mid < x)
            st = mid;
        else
            end = mid;
    }

    cout << fixed << setprecision(6) << st << endl;
    cout<< pow(x,1.0/2) << endl;

    return 0;
}
