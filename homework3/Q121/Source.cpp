#include<iostream>
#include<string>

using namespace std;

class Student{
public:
	string id;
	string name;
	int age;
	double weight;
	double math;
	double english;
	double cpp;
	double operator-(Student& student);
};
template<typename T>
int compare(T t1, T t2);
int compare(string t1, string t2);
int main(){
	Student student1, student2;
	cin >> student1.id >> student1.name >> student1.age >> student1.weight >> student1.math >> student1.english >> student1.cpp;
	cin >> student2.id >> student2.name >> student2.age >> student2.weight >> student2.math >> student2.english >> student2.cpp;
	cout << compare(student1.name, student2.name) << " ";
	cout << compare(student1.age, student2.age) << " ";
	cout << compare(student1.weight, student2.weight) << " ";
	cout << compare(student1,student2);
	return 0;
}

double Student::operator-(Student& student){
	double total1 = math * 4 + english * 4 + cpp * 3;
	double total2 = student.math * 4 + student.english * 4 + student.cpp * 3;
	return total1 - total2;
}

template<typename T>
int compare(T t1, T t2){
	if (t1 - t2 > 0){
		return 1;
	}
	else if (t1 - t2 < 0){
		return -1;
	}
	else{
		return 0;
	}
}

int compare(string t1, string t2){
	if (t1.compare(t2)>0){
		return 1;
	}
	else if (t1.compare(t2) < 0){
		return -1;
	}
	else{
		return 0;
	}
}