#include<iostream>

using namespace std;

const int plainMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int specialMonth[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
class DateTime{
public:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	void operator++();
	friend ostream& operator<<(ostream& out, DateTime& time);
};
ostream& operator<<(ostream& out, DateTime& time);
int main(){
	DateTime time;
	cin >> time.year >> time.month >> time.day >> time.hour >> time.minute >> time.second;
	time++;
	cout << time;
	return 0;
}

void DateTime::operator++(){
	second++;
	if (second == 60){
		second -= 60;
		minute++;
		if (minute == 60){
			minute -= 60;
			hour++;
			if (hour == 24){
				hour -= 24;
				day++;
				if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
					if (day == (specialMonth[month - 1]+1)){
						day = 1;
						month++;
						if (month == 13){
							month = 1;
							year++;
						}
					}
				}
				else{
					if (day == (plainMonth[month - 1]+1)){
						day = 1;
						month++;
						if (month == 13){
							month = 1;
							year++;
						}
					}
				}
			}
		}
	}
}

ostream& operator<<(ostream& out, DateTime& time){
	cout << time.year << " ";
	cout << time.month << " ";
	cout << time.day << " ";
	cout << time.hour << " ";
	cout << time.minute << " ";
	cout << time.second;
	return out;
}