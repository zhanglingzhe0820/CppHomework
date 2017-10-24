#include<iostream>

using namespace std;

long long getInt(char *);
char* transTochar(long long);
char* calculate(char*, char*, char*);
int main(){
	char* inputType = new char[10];
	char* inputNum1 = new char[100];
	char* inputNum2 = new char[100];

	cin >> inputType;
	cin >> inputNum1;
	cin >> inputNum2;

	cout << calculate(inputType, inputNum1, inputNum2);

	return 0;
}

long long getInt(char* num){
	long long result = 0;
	long long length = strlen(num);
	for (int i = length - 1; i >= 0; i--){
		long long temp = pow(13, length - i - 1);
		switch (num[i]){
		case '0':
			break;
		case '1':
			result += temp * 1;
			break;
		case '2':
			result += temp * 2;
			break;
		case '3':
			result += temp * 3;
			break;
		case '4':
			result += temp * 4;
			break;
		case '5':
			result += temp * 5;
			break;
		case '6':
			result += temp * 6;
			break;
		case '7':
			result += temp * 7;
			break;
		case '8':
			result += temp * 8;
			break;
		case '9':
			result += temp * 9;
			break;
		case 'A':
			result += temp * 10;
			break;
		case 'B':
			result += temp * 11;
			break;
		case 'C':
			result += temp * 12;
			break;
		case '-':
			result = result*(-1);
			break;
		}
	}
	return result;
}

char* transTochar(long long num){
	char* result = new char[100];
	for (int i = 0; i < 100; i++){
		result[i] = 0;
	}
	if (num >= 0){
		while (num >= 13){
			switch (num % 13){
			case 0:
				strcat_s(result, 100, "0");
				break;
			case 1:
				strcat_s(result, 100, "1");
				break;
			case 2:
				strcat_s(result, 100, "2");
				break;
			case 3:
				strcat_s(result, 100, "3");
				break;
			case 4:
				strcat_s(result, 100, "4");
				break;
			case 5:
				strcat_s(result, 100, "5");
				break;
			case 6:
				strcat_s(result, 100, "6");
				break;
			case 7:
				strcat_s(result, 100, "7");
				break;
			case 8:
				strcat_s(result, 100, "8");
				break;
			case 9:
				strcat_s(result, 100, "9");
				break;
			case 10:
				strcat_s(result, 100, "A");
				break;
			case 11:
				strcat_s(result, 100, "B");
				break;
			case 12:
				strcat_s(result, 100, "C");
				break;
			}
			num = num / 13;
		}
		switch (num){
		case 0:
			strcat_s(result, 100, "0");
			break;
		case 1:
			strcat_s(result, 100, "1");
			break;
		case 2:
			strcat_s(result, 100, "2");
			break;
		case 3:
			strcat_s(result, 100, "3");
			break;
		case 4:
			strcat_s(result, 100, "4");
			break;
		case 5:
			strcat_s(result, 100, "5");
			break;
		case 6:
			strcat_s(result, 100, "6");
			break;
		case 7:
			strcat_s(result, 100, "7");
			break;
		case 8:
			strcat_s(result, 100, "8");
			break;
		case 9:
			strcat_s(result, 100, "9");
			break;
		case 10:
			strcat_s(result, 100, "A");
			break;
		case 11:
			strcat_s(result, 100, "B");
			break;
		case 12:
			strcat_s(result, 100, "C");
			break;
		}
	}
	else{
		num = -num;
		while (num >= 13){
			switch (num % 13){
			case 0:
				strcat_s(result, 100, "0");
				break;
			case 1:
				strcat_s(result, 100, "1");
				break;
			case 2:
				strcat_s(result, 100, "2");
				break;
			case 3:
				strcat_s(result, 100, "3");
				break;
			case 4:
				strcat_s(result, 100, "4");
				break;
			case 5:
				strcat_s(result, 100, "5");
				break;
			case 6:
				strcat_s(result, 100, "6");
				break;
			case 7:
				strcat_s(result, 100, "7");
				break;
			case 8:
				strcat_s(result, 100, "8");
				break;
			case 9:
				strcat_s(result, 100, "9");
				break;
			case 10:
				strcat_s(result, 100, "A");
				break;
			case 11:
				strcat_s(result, 100, "B");
				break;
			case 12:
				strcat_s(result, 100, "C");
				break;
			}
			num = num / 13;
		}
		switch (num){
		case 0:
			strcat_s(result, 100, "0");
			break;
		case 1:
			strcat_s(result, 100, "1");
			break;
		case 2:
			strcat_s(result, 100, "2");
			break;
		case 3:
			strcat_s(result, 100, "3");
			break;
		case 4:
			strcat_s(result, 100, "4");
			break;
		case 5:
			strcat_s(result, 100, "5");
			break;
		case 6:
			strcat_s(result, 100, "6");
			break;
		case 7:
			strcat_s(result, 100, "7");
			break;
		case 8:
			strcat_s(result, 100, "8");
			break;
		case 9:
			strcat_s(result, 100, "9");
			break;
		case 10:
			strcat_s(result, 100, "A");
			break;
		case 11:
			strcat_s(result, 100, "B");
			break;
		case 12:
			strcat_s(result, 100, "C");
			break;
		}
		strcat_s(result, 100, "-");
	}
	char* ulti = new char[strlen(result)+1];
	for (int i = 0; i < strlen(result); i++){
		ulti[i] = result[strlen(result) - i-1];
	}
	ulti[strlen(result)] = 0;
	return ulti;
}

char* calculate(char* inputType, char* inputNum1, char* inputNum2){
	long long result = 0;
	if (!strcmp(inputType, "add")){
		result = getInt(inputNum1) + getInt(inputNum2);
	}
	else if (!strcmp(inputType, "sub")){
		result = getInt(inputNum1) - getInt(inputNum2);
	}
	else if (!strcmp(inputType, "mul")){
		result = getInt(inputNum1) * getInt(inputNum2);
	}
	return transTochar(result);
}