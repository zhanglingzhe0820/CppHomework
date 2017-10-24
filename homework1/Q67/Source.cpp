#include<iostream>
#include<string>

using namespace std;

int getLastLength(string str);
int main(){
	string str = "";
	getline(cin, str);
	cout << getLastLength(str);
	return 0;
}

int getLastLength(string str){
	int count = 0;
	int length = str.length();
	for (int i = 0; i < length; i++){
		if (str[i] == ' '){
			count++;
		}
	}
	for (int j = 0; j < length; j++){
		if (str[j] == ' '){
			count--;
			if (count == 0){
				return length - j - 1;
			}
		}
	}
}