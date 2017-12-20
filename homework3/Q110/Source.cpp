#include<iostream>

using namespace std;

class Point{
private:
	int x = 0;
	int y = 0;
	int z = 0;
public:
	friend Point& operator++(Point& point);
	friend ostream& operator<<(ostream& out, Point& point);
	friend istream& operator>>(istream& in, Point& point);
	Point& operator+(Point& point);
};

Point& operator++(Point& point);
ostream& operator<<(ostream& out, Point& point);
istream& operator>>(istream& in, Point& point);
int main(){
	Point *point1 = new Point();
	Point *point2 = new Point();
	cin >> *point1 >> *point2;
	(*point1)++;
	cout << *point1;
	cout << endl;
	cout << *point1 + *point2;
	delete point1, point2;
	return 0;
}

Point& operator++(Point& point){
	point.x++;
	point.y++;
	point.z++;
	return point;
}
ostream& operator<<(ostream& out, Point& point){
	out << "x:" << point.x << "," << "y:" << point.y << "," << "z:" << point.z;
	return out;
}
istream& operator>>(istream& in, Point& point){
	int x, y, z = 0;
	in >> point.x >> point.y >> point.z;
	return in;
}

Point& Point::operator+(Point& point){
	Point *newP = new Point();
	newP->x = x + point.x;
	newP->y = y + point.y;
	newP->z = z + point.z;
	return *newP;
}