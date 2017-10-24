#include<iostream>
#include<string>
#include<sstream>

using namespace std;

void calculateStudent(string(*info)[4], int length);
void calculateCourse(string(*info)[4], int length);
void execute(string(*info)[4], int length);
int main(){
	int numOfInfo = 0;
	cin >> numOfInfo;
	string (*info)[4] = new string[numOfInfo][4];
	for (int i = 0; i < numOfInfo; i++){
		cin >> info[i][0];
		cin >> info[i][1];
		cin >> info[i][2];
		cin >> info[i][3];
	}
	int numOfCommand = 0;
	cin >> numOfCommand;
	for (int j = 0; j < numOfCommand; j++){
		execute(info,numOfInfo);
	}
	return 0;
}

void execute(string(*info)[4], int length){
	char* type = new char[10];
	cin >> type;
	if (!strcmp(type, "student")){
		calculateStudent(info,length);
	}
	else{
		calculateCourse(info,length);
	}
}

void calculateStudent(string(*info)[4], int length){
	string target = "";
	int count = 0;
	int sum = 0;
	cin >> target;
	for (int i = 0; i < length; i++){
		if (info[i][0]==target){
			stringstream stream;
			count++;
			int score = 0;
			stream << info[i][3];
			stream >> score;
			sum += score;
		}
	}
	cout << target << " ";
	printf_s("%0.2f\n", sum*1.0 / count);
}

void calculateCourse(string(*info)[4], int length){
	string target = "";
	int count = 0;
	int sum = 0;
	cin >> target;
	for (int i = 0; i < length; i++){
		if (info[i][2] == target){
			stringstream stream;
			count++;
			int score = 0;
			stream << info[i][3];
			stream >> score;
			sum += score;
		}
	}
	cout << target << " ";
	printf_s("%0.2f\n", sum*1.0 / count);
}