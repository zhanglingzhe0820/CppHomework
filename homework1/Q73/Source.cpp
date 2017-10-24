#include<iostream>

using namespace std;

char* getChars(char number);
void arrange(int index,char* str,char* result);
int main(){
	char* str = new char[1000];
	cin >> str;
	int length = strlen(str);
	arrange(0,str,"");
	return 0;
}

void arrange(int index,char* str,char* result){
	if (strlen(result) == strlen(str)){
		cout << result << endl;
	}
	else{
		int length1 = strlen(getChars(str[index]));
		for (int i = 0; i < length1; i++){
			char* newResult = new char[1000];
			int length2 = strlen(result);
			for (int j = 0; j < length2; j++){
				newResult[j] = result[j];
			}
			newResult[strlen(result)] = getChars(str[index])[i];
			newResult[strlen(result) + 1] = 0;
			arrange(index + 1, str, newResult);
		}
	}
}

char* getChars(char number){
	char* result = new char[5];
	switch (number){
	case '2':
		result[0] = 'a';
		result[1] = 'b';
		result[2] = 'c';
		result[3] = 0;
		return result;
	case '3':
		result[0] = 'd';
		result[1] = 'e';
		result[2] = 'f';
		result[3] = 0;
		return result;
	case '4':
		result[0] = 'g';
		result[1] = 'h';
		result[2] = 'i';
		result[3] = 0;
		return result;
	case '5':
		result[0] = 'j';
		result[1] = 'k';
		result[2] = 'l';
		result[3] = 0;
		return result;
	case '6':
		result[0] = 'm';
		result[1] = 'n';
		result[2] = 'o';
		result[3] = 0;
		return result;
	case '7':
		result[0] = 'p';
		result[1] = 'q';
		result[2] = 'r';
		result[3] = 's';
		result[4] = 0;
		return result;
	case '8':
		result[0] = 't';
		result[1] = 'u';
		result[2] = 'v';
		result[3] = 0;
		return result;
	case '9':
		result[0] = 'w';
		result[1] = 'x';
		result[2] = 'y';
		result[3] = 'z';
		result[4] = 0;
		return result;
	}
}