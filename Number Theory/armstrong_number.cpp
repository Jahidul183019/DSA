#include <iostream>

using namespace std;

bool isArmstrong (int n){
	
	int copyN = n;
	int sumofcubes = 0;
	
	while (n != 0){
		int dig = n%10;
		sumofcubes += (dig*dig*dig);
		n = n/10;
	}
	
	return sumofcubes == copyN;
}

int main(){
	
	int n = 111;
	
	if(isArmstrong(n)){
		cout << "Is an Armstrong number" << endl;
	}
	
	else{
		cout << "Not an Armstrong number" << endl;
	}
	
	return 0;
}
	
		