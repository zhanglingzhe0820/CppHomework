#include<iostream>

using namespace std;


int main(){
	char* input = new char[100];
	cin >> input;
	char* result = new char[100];
	int length = strlen(input);
	for (int i = 0; i < length; i++){
		result[i] = input[length - i - 1];
	}
	result[length] = 0;
	cout << result;
	return 0;
}