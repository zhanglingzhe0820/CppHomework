#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

bool compare(string str1, string str2);
int main(){
	int length = 0;
	cin >> length;
	string *input=new string[length];
	for (int i = 0; i < length; i++){
		cin >> input[i];
	}
	sort(input, input + length, compare);
	for (int i = 0; i < length; i++){
		cout << input[i] << endl;
	}
	return 0;
}

bool compare(string str1, string str2){
	if (str1.size() < str2.size()){
		return true;
	}
	else if (str1.size() > str2.size()){
		return false;
	}
	else{
		int index = 0;
		while (index != str1.size()){
			char c1 = str1[index];
			char c2 = str2[index];
			int temp=0;
			if (c1 - 'a' == c2 - 'A'){
				temp=-1;
			}
			else if (c1 - 'A' == c2 - 'a'){
				temp=1;
			}
			else{
				c1 = (c1 <= 'Z') ? c1 : c1 - 'a' + 'A';
				c2 = (c2 <= 'Z') ? c2 : c2 - 'a' + 'A';
				temp=c1 - c2;
			}
			if (temp<0){
				return true;
			}
			else if (temp>0){
				return false;
			}
			index++;
		}
		return false;
	}
}