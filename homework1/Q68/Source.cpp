#include<iostream>

using namespace std;

void append(char* str,char* toAppend);
void replace(char* str, char* toReplace, char* toStr);
void reverse(char* str);
void changecase(char* str,char* command);
void length(char * str);
void print(char* str);
void execute(char* str,int num);
int main(){
	char* str = new char[10000];
	int num = 0;
	str[0] = 0;
	cin >> num;
	execute(str, num);
	return 0;
}

void execute(char* str,int num){
	char* Type = new char[10];
	for (int i = 0; i < num; i++){
		cin >> Type;
		if (!strcmp(Type, "append")){
			char* toAppend = new char[10000];
			cin >> toAppend;
			append(str, toAppend);
		}
		else if (!strcmp(Type, "replace")){
			char* toReplace = new char[10000];
			char* toStr = new char[10000];
			cin >> toReplace;
			cin >> toStr;
			replace(str, toReplace, toStr);
		}
		else if (!strcmp(Type, "reverse")){
			reverse(str);
		}
		else if (!strcmp(Type, "changecase")){
			char* command = new char[10000];
			cin >> command;
			changecase(str, command);
		}
		else if (!strcmp(Type, "length")){
			length(str);
		}
		else if (!strcmp(Type, "print")){
			print(str);
		}
	}
}

void append(char* str,char* toAppend){
	strcat_s(str, 10000, toAppend);
}
void replace(char* str, char* toReplace, char* toStr){
	char* result = new char[100000];
	result[0] = 0;
	int lastIndex = 0;
	int toReplaceLength = strlen(toReplace);
	int length = strlen(str);
	int count = 0;
	for (int i = 0; i <= length - toReplaceLength; i++){
		int j = i;
		for (j = i; j < i+toReplaceLength; j++){
			if (str[j] != toReplace[j - i]){
				break;
			}
		}
		if (j == i + toReplaceLength){
			char* temp = new char[10000];
			for (int k = 0; k < i - lastIndex; k++){
				temp[k] = str[lastIndex + k];
			}
			temp[i - lastIndex] = 0;
			strcat_s(result, 10000, temp);
			strcat_s(result, 10000, toStr);
			lastIndex = i + toReplaceLength;
			i = i + toReplaceLength - 1;
		}
	}
	char* temp = new char[10000];
	for (int k = 0; k < strlen(str) - lastIndex; k++){
		temp[k] = str[lastIndex + k];
	}
	temp[strlen(str) - lastIndex] = 0;
	strcat_s(result, 10000, temp);
	str[0] = 0;
	strcat_s(str, 10000, result);
}
void reverse(char* str){
	int length = strlen(str);
	char* temp = new char[length + 1];
	for (int i = 0; i < length; i++){
		temp[i] = str[length - i-1];
	}
	for (int i = 0; i < length; i++){
		str[i] = temp[i];
	}
}
void changecase(char* str, char* command){
	int length = strlen(str);
	if (!strcmp(command, "low")){
		for (int i = 0; i < length; i++){
			if (str[i] >= 'A'&&str[i] <= 'Z'){
				str[i] += 32;
			}
		}
	}
	else{
		for (int i = 0; i < length; i++){
			if (str[i] >= 'a'&&str[i] <= 'z'){
				str[i] -= 32;
			}
		}
	}
}
void length(char * str){
	cout << strlen(str)<<endl;
}
void print(char* str){
	cout << str << endl;
}

