#include<iostream>
#include<string>

using namespace std;

class Chess{
public:
	int x;
	int y;
	int kind;
};

class Board{
private:
	int size;
	int winTarget;
	Chess* chesses;
public:
	Board(int n,int target) :size(n),winTarget(target){ 
		chesses = new Chess[size*size];
		for (int i = 0; i < size*size; i++){
			chesses[i].kind = -1;
		}
	}
	void addChess(Chess chess){ chesses[chess.x*size+chess.y] = chess; }
	string isWin();
	~Board()
	{
		delete[] chesses;
	}
};
int main(){
	int size = 0;
	int winTarget = 0;
	cin >> size >> winTarget;

	if (size == 1 && winTarget == 1){
		cout << "O Success";
		return 0;
	}
	Board* board = new Board(size, winTarget);
	for (int i = 0; i < size*size; i++){
		Chess* chess = new Chess();
		cin >> chess->x >> chess->y;
		if (i % 2 == 0){
			chess->kind = 0;
		}
		else{
			chess->kind = 1;
		}
		board->addChess(*chess);
		delete chess;
		string temp = board->isWin();
		if (temp != "no"){
			cout << temp;
			delete board;
			return 0;
		}
	}
	cout << "Dogfall";
	return 0;
}

string Board::isWin(){
	for (int x = 0; x < size; x++){
		for (int y = 0; y < size; y++){
			int count = 1;
			int kind = chesses[x*size + y].kind;
			if (kind == -1){
				continue;
			}
			int tempX = x + 1;
			int tempY = y + 1;
			//ºáÏò
			while (tempY < size){
				if (chesses[x*size + tempY].kind == kind){
					count++;
				}
				if (count == winTarget){
					if (kind == 0){
						return "O Success";
					}
					else{
						return "X Success";
					}
				}
				tempY++;
			}

			count = 1;
			tempY = y + 1;
			//×ÝÏò
			while (tempX < size){
				if (chesses[tempX*size + y].kind == kind){
					count++;
				}
				if (count == winTarget){
					if (kind == 0){
						return "O Success";
					}
					else{
						return "X Success";
					}
				}
				tempX++;
			}
			
			count = 1;
			tempX = x + 1;
			tempY = y + 1;
			//ÇãÐ±
			while (tempX < size&&tempY < size){
				if (chesses[tempX*size + tempY].kind == kind){
					count++;
				}
				if (count == winTarget){
					if (kind == 0){
						return "O Success";
					}
					else{
						return "X Success";
					}
				}
				tempX++;
				tempY++;
			}

			count = 1;
			tempX = x - 1;
			tempY = y + 1;
			//ÇãÐ±
			while (tempX >= 0&&tempY < size){
				if (chesses[tempX*size + tempY].kind == kind){
					count++;
				}
				if (count == winTarget){
					if (kind == 0){
						return "O Success";
					}
					else{
						return "X Success";
					}
				}
				tempX++;
				tempY++;
			}
		}
	}
	return "no";
}