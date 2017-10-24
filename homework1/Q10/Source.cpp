#include<iostream>

using namespace std;

long long fib(int index);
int main(){
	int index = 0;

	cin >> index;
	cout << fib(index);
	return 0;
}

long long fib(int index){
	if (index == 0){
		return 0;
	}
	else if (index == 1){
		return 1;
	}
	else{
		long long pastTwo = 0;
		long long pastOne = 1;
		long long result = 0;
		for (int i = 2; i <= index; i++){
			result = pastTwo + pastOne;
			pastTwo = pastOne;
			pastOne = result;
		}
		return result;
	}
}
