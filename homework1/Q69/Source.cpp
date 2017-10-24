#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(string str);
int main(){
	int length = 0;
	string str = "";
	cin >> length;
	char* temp = new char[length + 1];
	cin >> temp;
	str = temp;
	int max = 1;

	for (int i = 0; i < length; i++){
		for (int j = i; j < length; j++){
			if (isPalindrome(str.substr(i, j - i+1))){
				if (max < j - i + 1){
					max = j - i + 1;
				}
			}
		}
	}
	cout << max;
	return 0;
}

bool isPalindrome(string str){
	int length = str.length();
	int half = length / 2;
	for (int i = 0; i < half; i++){
		if (str[i] != str[length - i - 1]){
			return false;
		}
	}
	return true;
}