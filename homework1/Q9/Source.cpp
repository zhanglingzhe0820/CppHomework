#include<iostream>

using namespace std;

int sum(int n,int m);
bool isPrime(int number);
int main(){
	int n = 1;
	int m = 1;

	cin >> n >> m;
	cout << sum(n, m);
	return 0;
}

int sum(int n, int m){
	int result = 0;
	for (; n <= m; n++){
		if (isPrime(n)){
			result += n;
		}
	}
	return result;
}

bool isPrime(int number){
	if (number == 1){
		return false;
	}
	for (int i = 2; i <= number / 2; i++){
		if (number%i == 0){
			return false;
		}
	}
	return true;
}
