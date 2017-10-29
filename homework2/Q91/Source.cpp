#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include<map>
#include<sstream>

using namespace std;

bool hasElement(list<string> lst, string value);
int main(){
	int length = 0;
	int subjectNum = 0;
	int studentNum = 0;
	list<string> idList;
	list<string> subjectList;
	cin >> length;
	string **info = new string*[length];
	for (int i = 0; i < length; i++){
		info[i] = new string[4];
	}
	for (int i = 0; i < length; i++){
		cin >> info[i][0];
		cin >> info[i][1];
		if (!hasElement(idList, info[i][1])){
			idList.push_back(info[i][1]);
			studentNum++;
		}
		cin >> info[i][2];
		if (!hasElement(subjectList, info[i][2])){
			subjectList.push_back(info[i][2]);
			subjectNum++;
		}
		cin >> info[i][3];
	}

	map<string, double> averageMap;
	for (list<string>::iterator it = idList.begin(); it != idList.end(); it++){
		double total = 0;
		map<string, double> subjectScore;
		string id = *it;
		for (int i = 0; i < length; i++){
			if (id == info[i][1]){
				stringstream ss;
				double score;
				ss << info[i][3];
				ss >> score;
				subjectScore[info[i][2]] = score;
			}
		}
		for (map<string, double>::iterator it = subjectScore.begin(); it != subjectScore.end(); it++){
			total += it->second;
		}
		averageMap[id] = total*1.0 / subjectNum;
	}

	double average = 0;
	double **reverseArray = new double*[studentNum];
	for (int j = 0; j < studentNum; j++){
		reverseArray[j] = new double[2];
	}
	int i = 0;
	for (map<string, double>::iterator it = averageMap.begin(); it != averageMap.end(); it++){
		average += it->second;
		stringstream ss;
		double id;
		ss << it->first;
		ss >> id;
		reverseArray[i][0] = id;
		reverseArray[i][1] = it->second;
		i++;
	}
	average = average / studentNum;

	for (int j = 0; j < studentNum; j++){
		for (int k = 0; k < studentNum-1; k++){
			if (reverseArray[k][1] < reverseArray[k + 1][1]){
				double *temp = new double[2];
				temp[0] = reverseArray[k][0];
				temp[1] = reverseArray[k][1];
				reverseArray[k] = reverseArray[k + 1];
				reverseArray[k + 1] = temp;
			}
		}
	}

	for (int j = 0; j < studentNum; j++){
		for (int k = 0; k < studentNum - 1; k++){
			if (reverseArray[k][1] == reverseArray[k + 1][1] && reverseArray[k][0] < reverseArray[k+1][0]){
				double *temp = new double[2];
				temp[0] = reverseArray[k][0];
				temp[1] = reverseArray[k][1];
				reverseArray[k] = reverseArray[k + 1];
				reverseArray[k + 1] = temp;
			}
		}
	}

	for (int i = 0; i < studentNum; i++){
		if (reverseArray[i][1] < average){
			long long temp = floor(reverseArray[i][0] + 0.1);
			cout << temp<<endl;
		}
	}

	return 0;
}

bool hasElement(list<string> lst, string value){
	for (list<string>::iterator it = lst.begin(); it != lst.end(); it++){
		if (*it == value){
			return true;
		}
	}
	return false;
}