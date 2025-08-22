//Leetcode Q. 50

#include <iostream>
using namespace std;

class solution{

    public:

    double myPow (double x, int n){         //<------------O(log n)

        long binForm = n;

        if(n<0){
            x = 1/x;
            binForm = -binForm;
        }

        double ans = 1;

        while (binForm>0){

            if(binForm % 2 == 1){
                ans *= x;
            }

            x *= x; //x^2
            binForm /= 2;
        }

        return ans;
    }
};

int main() {
    solution s;

    double x;
    int n;
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    cout << x << "^" << n << " = " << s.myPow(x, n) << endl;

    return 0;
}

/*Corner Case

double myPow (double x, int n){

    if (n == 0) return 1.0;
    if (x == 0) return 0.0;
    if (x == 1) return 1.0;
    if (x == -1 && n%2 == 0) return 1.0;
    if (x == -1 && n%2 != 0) return -1.0;
}*/