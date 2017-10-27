#include<iostream>
#include<fstream>
#include<string>
#include<stack>

using namespace std;

string readAndRemoveComment();
int main(){
	string input = readAndRemoveComment();
	cout << input;
	return 0;
}

string readAndRemoveComment(){
	stack<char> stack;
	string result = "";
	char temp;
	while (temp = cin.get()){
		if (temp == '<'){
			if (cin.get() == '!'&&cin.get() == '-'&&cin.get() == '-'){
			}
			else{
				result += temp;
			}
		}
		else if(temp=='-'){
			if (cin.get() == '!'&&cin.get() == '-'&&cin.get() == '-'){
			}
			else{
				result += temp;
			}
		}
	}
}