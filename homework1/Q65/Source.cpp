#include<iostream>

using namespace std;

int caculate(long long* input,int length);
int caculateTwo(int* line);
int main(){
	int num = 0;
	cin >> num;
	long long* input = new long long[num];
	for (int i = 0; i < num; i++){
		cin >> input[i];
	}
	cout << caculate(input, num);
	delete input;
	return 0;
}

int caculate(long long* input,int length){
	int result = 0;
	for (int i = 0; i < length; i++){
		unsigned long long offset = 0x8000000000000000;
		int* temp = new int[3];
		while (!(input[i]&offset)){
			offset >>= 1;
		}
		temp[0] = 1;
		offset >>= 1;
		temp[1] = input[i] & offset ? 1 : 0;
		offset >>= 1;
		temp[2] = input[i] & offset ? 1 : 0;
		result += caculateTwo(temp);
	}
	return result;
}

int caculateTwo(int* line){
	int result = 0;
	for (int i = 0; i < 3; i++){
		if (line[i] == 1){
			result += pow(2, 2 - i);
		}
	}
	return result;
}

