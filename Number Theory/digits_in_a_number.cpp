//TC: O (log10(n))

#include <iostream>
using namespace std;

void printDigits (int n){
	
    int count = 0;
    int sum = 0;

    while (n != 0){
        int digit = n % 10;
		
        cout << digit << endl;
		
        count++;
        sum += digit;
		
        n = n / 10;
    }
    cout << "Total digits = " << count << endl;
    cout << "Sum of digits = " << sum << endl;
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
	
    printDigits(n);
    return 0;
}

/* Shortcut of count digit:

cout<< (int) (log10(n)+1) << endl;

*/