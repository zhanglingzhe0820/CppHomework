#include<iostream>

using namespace std;

long long power(int x, int y);

int main(){
	int x=1;
	int y=1;

	cin >> x >> y;
	cout << power(x, y);
}

long long power(int x, int y){
	long long result = 1;
	for (int i = 0; i < y; i++){
		result *= x;
	}
	return result;
}