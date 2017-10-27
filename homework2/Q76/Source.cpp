#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<list>

using namespace std;

int main(){
	string input1, input2;
	cin >> input1;
	cin >> input2;
	int size1 = input1.size();
	int size2 = input2.size();

	//将>及<替换为空格
	for (int i = 0; i < size1; i++){
		input1[i] = input1[i] == '>' ? ' ' : input1[i];
	}
	for (int i = 0; i < size2; i++){
		input2[i] = input2[i] == '>' ? ' ' : input2[i];
	}

	stringstream s1, s2;
	int length1 = 0;
	int length2 = 0;
	s1 << input1;
	s2 << input2;

	list<int> list1;
	list<int> list2;
	while (s1){
		string temp;
		s1 >> temp;
		if (temp == "null"){
			break;
		}
		else{
			list1.push_back(temp[0] - '0');
			length1++;
		}
	}
	while (s2){
		string temp;
		s2 >> temp;
		if (temp == "null"){
			break;
		}
		else{
			list2.push_back(temp[0] - '0');
			length2++;
		}
	}

	int c = 0;
	int length = (length1 >= length2) ? length1 : length2;
	list<int>::iterator it1 = list1.end();
	list<int>::iterator it2 = list2.end();
	list<int>::iterator it1Begin = list1.begin();
	list<int>::iterator it2Begin = list2.begin();
	it1Begin;
	it2Begin;
	list<int> result;

	for (int i = 0; i < length; i++){
		int temp = 0;
		if (it1 != it1Begin&&it2 != it2Begin){
			it1--;
			it2--;
			temp = (*it1) + (*it2) + c;
		}
		else if (it1 != it1Begin){
			it1--;
			temp = (*it1) + c;
		}
		else{
			it2--;
			temp = (*it2) + c;
		}
		if (temp >= 10){
			if (temp < 20){
				c = 1;
				temp = temp - 10;
			}
			else{
				c = 2;
				temp = temp - 20;
			}
		}
		else{
			c = 0;
		}
		result.push_front(temp);
	}
	if (c){
		result.push_front(c);
	}

	list<int>::iterator it = result.begin();

	it = result.begin();
	bool isBegin=true;
	for (it; it != result.end(); it++){
		if (*it){
			cout << *it << '>';
			isBegin = false;
		}
		else{
			if (!isBegin){
				cout << *it << '>';
			}
		}
	}
	cout << "null";
	return 0;
}
