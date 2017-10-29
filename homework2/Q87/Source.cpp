#include<iostream>
#include<fstream>
#include<map>

using namespace std;

void calculatePath(int **input, int m, int length, int last[]);
int main(){
	//¶ÁÈëÊý¾Ý
	int length = 0;
	cin >> length;
	int **input = new int*[length];
	for (int i = 0; i < length; i++){
		input[i] = new int[length];
	}
	for (int i = 0; i < length; i++){
		for (int j = 0; j <= i; j++){
			cin >> input[i][j];
		}
	}
		calculatePath(input, 1, length, new int[1]{input[0][0]});
	return 0;
}

void calculatePath(int **input, int m, int length,int last[]){
	if (m == length){
		int min = last[0];
		for (int i = 0; i < length; i++){
			if (min > last[i]){
				min = last[i];
			}
		}
		cout << min;
		return;
	}
	int *result = new int[m + 1];
	result[0] = last[0] + input[m][0];
	for (int i = 1; i < m; i++){
		int temp1 = last[i-1] + input[m][i];
		int temp2 = last[i] + input[m][i];
		result[i] = temp1 < temp2 ? temp1 : temp2;
	}
	result[m] = last[m - 1] + input[m][m];
	
	delete[] last;
	calculatePath(input, m + 1, length, result);
}
