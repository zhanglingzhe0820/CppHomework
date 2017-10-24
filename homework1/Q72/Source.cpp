#include<iostream>

using namespace std;

long long calculate(char* str);
int translate(char sign);
int main(){
	char* str = new char[1000];
	cin >> str;
	cout << calculate(str);
	return 0;
}

long long calculate(char* str){
	long long result = 0;
	int length = strlen(str);
	for (int i = 0; i < length; i++){
		if (i <= length - 2 && (str[i] == 'I' || str[i] == 'X' || str[i] == 'C')){
			if (translate(str[i]) < translate(str[i + 1])){
				result -= translate(str[i]);
			}
			else{
				result += translate(str[i]);
			}
		}
		else{
			result += translate(str[i]);
		}
	}
	return result;
}

int translate(char sign){
	switch (sign){
	case 'I':
		return 1;
	case 'X':
		return 10;
	case 'C':
		return 100;
	case 'M':
		return 1000;
	case 'V':
		return 5;
	case 'L':
		return 50;
	case 'D':
		return 500;
	}
}