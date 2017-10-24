#include<iostream>
#include<sstream>

using namespace std;

int numOfCheck(int length);
int* rearrange(char* input);
int addPostion(int position);
void calculate(int length,int* Des);
bool isCheck(int index);
int main(){
	char* input = new char[1000];
	cin >> input;
	int* Des = rearrange(input);
	calculate(strlen(input),Des);
	return 0;
}

void calculate(int length,int* Des){
	int lengthDes = length + numOfCheck(length);
	int(*result)[1000] = new int[numOfCheck(length)][1000];
	int* count = new int[numOfCheck(length)];
	for(int i = 0; i < numOfCheck(length); i++){
		count[i] = 0;
	}
	for (int j = 0; j < lengthDes; j++){
		if (!isCheck(j + 1)){
			int index = 0;
			unsigned int offset = 0x00000001;
			while (offset <= (j + 1)){
				if (offset&(j + 1)){
					result[index][count[index]] = j;
					count[index]++;
				}
				offset <<= 1;
				index++;
			}
		}
	}
	for (int k = 0; k < 7; k++){
		if (pow(2, k) < lengthDes){
			for (int p = 0; p < count[k]; p++){
				Des[int(pow(2, k)) - 1] ^= Des[result[k][p]];
			}
		}
		else{
			break;
		}
	}
	for (int q = 0; q < lengthDes; q++){
		cout << Des[q];
	}
}

bool isCheck(int index){
	unsigned int offset = 0x80000000;
	int count = 0;
	for (int i = 0; i < 32; i++){
		if (index&offset){
			count++;
		}
		offset >>= 1;
	}
	if (count == 1){
		return true;
	}
	else{
		return false;
	}
}

int* rearrange(char* input){
	int lengthSou = strlen(input);
	int lengthDes = strlen(input) + numOfCheck(strlen(input));
	int* result = new int[lengthDes];
	for (int i = 0; i < lengthSou; i++){
		result[i + addPostion(i+1)] = int(input[i] - 0x30);
	}
	for (int i = 0; i < lengthDes; i++){
		if(isCheck(i + 1)){
			result[i] = 0;
		}
	}
	return result;
}

int addPostion(int position){
	if (position == 1){
		return 2;
	}
	else if (position == 2 || position==3 || position==4){
		return 3;
	}
	else if (position == 5 || position == 6 || position == 7 || position == 8 || position == 9 || position == 10 || position == 11){
		return 4;
	}
	else if (position == 11 || position == 12 || position == 13 || position == 14 || position == 15 || position == 16 || position == 17 || position == 18 || position == 19 || position == 20 || position == 21 || position == 22 || position == 23 || position == 24 || position == 25 || position == 26){
		return 5;
	}
	else if (position >= 27 && position <= 57){
		return 6;
	}
	else{
		return 7;
	}
}

int numOfCheck(int length){
	if (length >= 2 && length <= 4){
		return 3;
	}
	else if (length >= 5 && length <= 11){
		return 4;
	}
	else if (length >= 12 && length <= 26){
		return 5;
	}
	else if (length >= 27 && length <= 57){
		return 6;
	}
	else if (length >= 58 && length <= 120){
		return 7;
	}
	else{
		return 0;
	}
}