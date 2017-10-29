#include<iostream>
#include<fstream>
#include<list>

using namespace std;

void arrangeList(list<long long> &lst, long long *input[], int lengthOfRow, int lengthOfColumn);
int main(){
	int lengthOfRow = 0;
	int lengthOfColumn = 0;
	int target = 0;
	list<long long> lst;
	cin >> lengthOfRow;
	cin >> lengthOfColumn;
	long long **input = new long long*[lengthOfRow];
	for (int i = 0; i < lengthOfRow; i++){
		input[i] = new long long[lengthOfColumn];
	}
	for (int i = 0; i < lengthOfRow; i++){
		for (int j = 0; j < lengthOfColumn; j++){
			cin >> input[i][j];
		}
	}
	cin >> target;
	arrangeList(lst, input, lengthOfRow, lengthOfColumn);
	for (list<long long>::iterator it = lst.begin(); it != lst.end(); it++,target--){
		if (target == 0){
			cout << *it;
		}
	}
	return 0;
}

void arrangeList(list<long long> &lst, long long *input[], int lengthOfRow, int lengthOfColumn){
	int index = 0;
	int length = (lengthOfRow <= lengthOfColumn) ? lengthOfRow : lengthOfColumn;
	for (; length >= 2 * index + 1; index++){
		if (lengthOfRow == 2 * index + 1){
			for (int i = index; i < lengthOfColumn - index; i++){
				lst.push_back(input[index][i]);
			}
		}
		else if (lengthOfColumn == 2 * index + 1){
			for (int i = index; i < lengthOfRow - index; i++){
				lst.push_back(input[i][index]);
			}
		}
		else{
			for (int i = index; i < lengthOfColumn - index; i++){
				lst.push_back(input[index][i]);
			}
			for (int i = index+1; i < lengthOfRow - index; i++){
				lst.push_back(input[i][lengthOfColumn - index - 1]);
			}
			for (int i = lengthOfColumn - index - 2; i >= index; i--){
				lst.push_back(input[lengthOfRow - index - 1][i]);
			}
			for (int i = lengthOfRow - index - 2; i > index; i--){
				lst.push_back(input[i][index]);
			}
		}
	}
}