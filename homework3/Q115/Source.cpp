#include<iostream>
#include<algorithm>

using namespace std;

template<typename T>
class Tool{
private:
	T* sort(int size, T* input);
public:
	int intFind(int target, int size, int* input);
	int doubleFind(double target, int size, double* input);
	int charFind(char target, int size, char* input);
};
int main(){
	int length = 0;
	int intTarget;
	double doubleTarget;
	char charTarget;
	Tool<int> intTool;
	Tool<double> doubleTool;
	Tool<char> charTool;

	cin >> length;
	int* intInput = new int[length];
	for (int i = 0; i < length; i++){
		cin >> intInput[i];
	}
	cin >> intTarget;
	cout << intTool.intFind(intTarget, length, intInput) << endl;

	cin >> length;
	double* doubleInput = new double[length];
	for (int i = 0; i < length; i++){
		cin >> doubleInput[i];
	}
	cin >> doubleTarget;
	cout << doubleTool.doubleFind(doubleTarget, length, doubleInput) << endl;

	cin >> length;
	char* charInput = new char[length];
	for (int i = 0; i < length; i++){
		cin >> charInput[i];
	}
	cin >> charTarget;
	cout << charTool.charFind(charTarget, length, charInput);
	return 0;
}

template<typename T>
T* Tool<T>::sort(int size, T* input){
	std::sort(input, input + size);
	return input;
}

template<typename T>
int Tool<T>::intFind(int target, int size, int* input){
	input = sort(size, input);
	int max = size - 1;
	int min = 0;
	int index = (min + max) / 2;
	int count = 0;
	do{
		index = (min + max) / 2;
		count++;
		if (input[index] > target){
			max = index - 1;
		}
		else{
			min = index + 1;
		}
	} while (input[index] != target);
	return count;
}
template<typename T>
int Tool<T>::doubleFind(double target, int size, double* input){
	input = sort(size, input);
	int max = size - 1;
	int min = 0;
	int index = (min + max) / 2;
	int count = 0;
	do{
		index = (min + max) / 2;
		count++;
		if (input[index] > target){
			max = index - 1;
		}
		else{
			min = index + 1;
		}
	} while (input[index] != target);
	return count;
}
template<typename T>
int Tool<T>::charFind(char target, int size, char* input){
	input = sort(size, input);
	int max = size - 1;
	int min = 0;
	int index = (min + max) / 2;
	int count = 0;
	do{
		index = (min + max) / 2;
		count++;
		if (input[index] > target){
			max = index - 1;
		}
		else{
			min = index + 1;
		}
	} while (input[index] != target);
	return count;
}