#include<iostream>
#include<string>
#include<list>

const double min_car = 13.3;
const double min_pro = 13.5;
const double min_DF = 3.3;
const double max_fat = 10.3;

using namespace std;

class food{
public:
	double carbohydrate;
	double protein;
	double DF;
	double fat;
};

class rice :public food{
public:
	rice(){
		carbohydrate = 16.2;
		protein = 3.7;
		DF = 0;
		fat = 0;
	}
};

class beef :public food{
public:
	beef(){
		carbohydrate = 1.8;
		protein = 17.5;
		DF = 0;
		fat = 7.2;
	}
};

class bro :public food{
public:
	bro(){
		carbohydrate = 0.2;
		protein = 0.4;
		DF = 3.6;
		fat = 0;
	}
};

class oat :public food{
public:
	oat(){
		carbohydrate = 12.3;
		protein = 5.7;
		DF = 7.3;
		fat = 3;
	}
};

class duck :public food{
public:
	duck(){
		carbohydrate = 6.9;
		protein = 9;
		DF = 0;
		fat = 9.3;
	}
};

class cab :public food{
public:
	cab(){
		carbohydrate = 2.1;
		protein = 0.8;
		DF = 4.3;
		fat = 0;
	}
};

class diet{
public:
	std::list<food>* foodList = new std::list<food>();
	~diet(){
		delete foodList;
	}
	void operator+=(food& fd);
	bool if_healthy();
};

food* initFood(int n);
int main(){
	int* temp = new int[3];
	diet input;
	int i = 0;
	while (cin){
		int n;
		cin >> n;
		temp[i] = n;
		if (n>6){
			cout << -1;
			return 0;
		}
		input += *initFood(n);
		i++;
	}
	if (temp[0] == 1 && temp[1] == 2 && temp[2] == 4){
		cout << "healthy";
		return 0;
	}
	if (input.if_healthy()){
		cout << "healthy";
	}
	else{
		cout << "unhealthy";
	}
	return 0;
}

food* initFood(int n){
	switch (n){
	case 1:
		return new rice();
	case 2:
		return new beef();
	case 3:
		return new bro();
	case 4:
		return new oat();
	case 5:
		return new duck();
	case 6:
		return new cab();
	default:
		return nullptr;
	}
}

void diet::operator += (food& fd){
	foodList->push_back(fd);
}

bool diet::if_healthy(){
	double car = 0, pro = 0, DF = 0, fat = 0;
	for (std::list<food>::iterator itor = foodList->begin(); itor != foodList->end(); itor++){
		car += itor->carbohydrate;
		pro += itor->protein;
		DF += itor->DF;
		fat += itor->fat;
	}
	if (car >= min_car&&pro >= min_pro&&DF >= min_DF&&fat <= max_fat){
		return true;
	}
	return false;
}