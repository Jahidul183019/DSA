#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double EPS = 1e-9;

double multiply(double mid,int n){
    double ans=1;
    
    for(int i=0;i<n;i++){
        ans*=mid;
    }
    return ans;
}
int main() {
    double x;
    int n;
    cin >> x >> n;

    double st = 0.0;
    double end = x;
    double mid;

    while (end - st > EPS) {
        mid = st + (end - st) / 2.0;

        if (multiply(mid,n) < x)
            st = mid;
        else
            end = mid;
    }

    cout << fixed << setprecision(6) << st << endl;
    cout<< pow(x,1.0/n) << endl;

    return 0;
}
