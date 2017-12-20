#include<iostream>
#include<string>

using namespace std;

int main(){
	int a, b, c, d;
	int meat, vegatable;
	cin >> a >> b >> c >> d;
	switch (a){
	case 1:
		meat = 10;
		break;
	case 2:
		meat = 8;
		break;
	case 3:
		meat = 7;
		break;
	}
	switch (c)
	{
	case 1:
		vegatable = 4;
		break;
	case 2:
		vegatable = 3;
		break;
	default:
		break;
	}
	cout << meat*b + vegatable*d;
	return 0;
}