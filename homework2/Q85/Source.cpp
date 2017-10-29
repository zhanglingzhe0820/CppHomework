#include<iostream>
#include<fstream>
#include<string>
#include<list>

using namespace std;
void print(list<long long> lst);
void replace(list<long long> &lst, long long src, long long des);
void move(list<long long> &lst, string des, long long target);
void translate(list<long long> &lst, string des, int length);
int main(){
	list<long long> lst;
	int length = 0;
	cin >> length;
	for (int i = 0; i < length; i++){
		long long temp = 0;
		cin >> temp;
		lst.push_back(temp);
	}

	int numOfCommand = 0;
	cin >> numOfCommand;
	for (int i = 0; i < numOfCommand; i++){
		string command;
		cin >> command;
		if (command == "print"){
			print(lst);
		}
		else if (command == "replace"){
			long long src = 0;
			long long des = 0;
			cin >> src;
			cin >> des;
			replace(lst, src, des);
		}
		else if (command == "move"){
			string des;
			long long target = 0;
			cin >> des;
			cin >> target;
			move(lst, des, target);
		}
		else if (command == "translate"){
			string des;
			int length = 0;
			cin >> des;
			cin >> length;
			translate(lst, des, length);
		}
	}
	return 0;
}

void print(list<long long> lst){
	for (list<long long>::iterator it = lst.begin(); it != lst.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

void replace(list<long long> &lst, long long src, long long des){
	for (list<long long>::iterator it = lst.begin(); it != lst.end(); it++){
		if (*it == src){
			*it = des;
		}
	}
}
void move(list<long long> &lst, string des, long long target){
	int count = 0;
	for (list<long long>::iterator it = lst.begin(); it != lst.end();){
		if (*it == target){
			it=lst.erase(it);
			count++;
		}
		else{
			it++;
		}
	}
	for (int i = 0; i < count; i++){
		if (des == "head"){
			lst.push_front(target);
		}
		else{
			lst.push_back(target);
		}
	}
}
void translate(list<long long> &lst, string des, int length){
	if (des == "head"){
		for (int i = 0; i < length; i++){
			long long temp = lst.front();
			lst.pop_front();
			lst.push_back(temp);
		}
	}
	else{
		for (int i = 0; i < length; i++){
			long long temp = lst.back();
			lst.pop_back();
			lst.push_front(temp);
		}
	}
}
