#include<iostream>
#include<string>
#include "Header.h"

using namespace std;

int main(){
	int length = 0;
	cin >> length;
	long long* line = new long long[length];
	for (int i = 0; i < length; i++){
		cin >> line[i];
	}
	int num = 0;
	cin >> num;

	for (int j = 0; j < num-1; j++){
		execute(line,length);
	}
	delete line;
	return 0;
}

void execute(long long* line, int length){
	char* inputType = new char[10];
	long long inputNum;
	cin >> inputType;

	if (!strcmp(inputType, "add")){
		cin >> inputNum;
		add(line,inputNum,length);
	}
	else if (!strcmp(inputType, "sub")){
		cin >> inputNum;
		sub(line, inputNum, length);
	}
	else if (!strcmp(inputType, "mul")){
		cin >> inputNum;
		mul(line, inputNum, length);
	}
	else if (!strcmp(inputType, "pow")){
		cin >> inputNum;
		pow(line, inputNum, length);
	}
	else if (!strcmp(inputType, "sqa")){
		cin >> inputType;
		sqa(line, length);
	}
	else if (!strcmp(inputType, "print")){
		print(line, length);
	}
}

void add(long long* line, long long num, int length){
	for (int i = 0; i < length; i++){
		line[i] += num;
	}
}

void sub(long long* line, long long num, int length){
	for (int i = 0; i < length; i++){
		line[i] -= num;
	}
}

void mul(long long* line, long long num, int length){
	for (int i = 0; i < length; i++){
		line[i] *= num;
	}
}

void pow(long long* line, long long num, int length){
	for (int i = 0; i < length; i++){
		line[i] = power(line[i], num);
	}
}

void sqa(long long* line, int length){
	long long result = 0;
	for (int i = 0; i < length; i++){
		result += line[i]*line[i];
	}
	cout << result;
}

void print(long long* line, int length){
	for (int i = 0; i < length - 1; i++){
		cout << line[i] << " ";
	}
	cout << line[length - 1]<<endl;
}

long long power(int x, int y){
	long long result = 1;
	for (int i = 0; i < y; i++){
		result *= x;
	}
	return result;
}