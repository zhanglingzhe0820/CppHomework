#include<iostream>

using namespace std;

char* getItem(int index);
int main(){
	int index = 0;

	cin >> index;
	cout << getItem(index);
	return 0;
}

char* getItem(int index){
	char *result = new char[200];
	int count = 1;
	if (index == 1){
		return "1/1";
	}
	while (true){
		index = index - count;
		count++;
		if (index <=count &&index > 0){
			int first = index;
			char* firstC = new char[100];
			_itoa_s(first, firstC,100, 10);
			int second = count + 1 - index;
			char* secondC = new char[100];
			_itoa_s(second, secondC,100, 10);
			if (count % 2 == 0){
				strcpy_s(firstC + strlen(firstC), 10, "/");
				strcpy_s(result, 10, firstC);
				strcpy_s(result + strlen(firstC), 100, secondC);
			}
			else{
				strcpy_s(secondC + strlen(secondC), 10, "/");
				strcpy_s(result, 10, secondC);
				strcpy_s(result + strlen(secondC), 100, firstC);
			}

			return result;
		}
	}
}
