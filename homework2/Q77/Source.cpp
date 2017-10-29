#include<iostream>
#include<fstream>
#include<string>
#include<stack>

using namespace std;

string readAndRemoveComment();
int main(){
	string input = readAndRemoveComment();
	
	stack<string> tagStack;
	string tagName="";
	stack<char> charStack;
	for (int i = 0; i < input.size(); i++){
		if (input[i] == '<'){
			charStack.push('<');
		}
		else if (input[i] == '>'){
			if (charStack.empty()){
				cout << "False";
				return 0;
			}
			charStack.pop();

			if (tagName[0] == '/'){
				if (tagStack.empty()){
					cout << "False";
					return 0;
				}
				else if (('/' + tagStack.top()) != tagName){
					cout << "False";
					return 0;
				}
				tagStack.pop();
			}
			else{
				tagStack.push(tagName);
			}

			if (tagName.size() == 0 || tagName.size()>9){
				cout << "False";
				return 0;
			}
			
			bool isUpper = true;
			if (tagName[0] == '/'){
				for (int i = 1; i < tagName.size(); i++){
					if (!(tagName[i] >= 'A'&&tagName[i] <= 'Z')){
						isUpper = false;
					}
				}
			}
			else{
				for (int i = 0; i < tagName.size(); i++){
					if (!(tagName[i] >= 'A'&&tagName[i] <= 'Z')){
						isUpper = false;
					}
				}
			}
			if (!isUpper){
				cout << "False";
				return 0;
			}
			tagName = "";
		}
		else if (!charStack.empty()){
			tagName += input[i];
		}
	}

	if (input[input.size() - 1] != '>'){
		cout << "False";
		return 0;
	}
	if (!tagStack.empty() || !charStack.empty()){
		cout << "False";
		return 0;
	}
	cout << "True";
	return 0;
}

string readAndRemoveComment(){
	stack<char> stack;
	string input = "";
	string result = "";
	getline(cin, input);

	for (int i = 0; i < input.size(); i++){
		if (i < input.size() - 3){
			if (input[i] == '<'&&input[i + 1] == '!'&&input[i + 2] == '-'&&input[i + 3] == '-'&&stack.empty()){
				stack.push('#');
			}
		}
		if (stack.empty()){
			result += input[i];
		}
		if (input[i] == '>'&&input[i - 1] == '-'&&input[i - 2] == '-'){
			stack.pop();
		}
	}
	return result;
}