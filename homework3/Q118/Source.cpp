#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Hero{
public:
	int id;
	int hp;
	int atk;
	bool canUsePower = true;
	bool isDead(){ return hp <= 0; }
	virtual void afterPeriod(){};
	friend ostream& operator<<(ostream& out, Hero& hero);
};

class Warrior:public Hero{
public:
	Warrior(){ id = 1; hp = 12; atk = 2; }
	virtual void afterPeriod()
	{ 
		if (hp > 0){
			hp++;
		}
	}
};

class Magician :public Hero{
public:
	Magician(){ id = 2; hp = 2; atk = 6; }
	virtual void afterPeriod()
	{
		if (canUsePower){
			hp = 2;
			canUsePower = false;
		}
	}
};

class Leader :public Hero{
public:
	Leader(){ id = 3; hp = 6; atk = 6; }
	virtual void afterPeriod()
	{
		if (hp > 0){
			atk++;
		}
	}
};

Hero* initHero(int n);
ostream& operator<<(ostream& out, Hero& hero);
int main(){
	int number = 0;
	int index1 = 0;
	int index2 = 0;
	cin >> number;
	vector<Hero*> heros1(number);
	vector<Hero*> heros2(number);
	for (int i = 0; i < number; i++){
		int n;
		cin >> n;
		heros1[i] = initHero(n);
	}
	for (int i = 0; i < number; i++){
		int n;
		cin >> n;
		heros2[i] = initHero(n);
	}

	while (index1 < number&&index2 < number){
		heros1[index1]->hp -= heros2[index2]->atk;
		heros2[index2]->hp -= heros1[index1]->atk;
		heros1[index1]->afterPeriod();
		heros2[index2]->afterPeriod();
		if (heros1[index1]->isDead()){
			index1++;
		}
		if (heros2[index2]->isDead()){
			index2++;
		}
	}

	if (index1 == number&&index2==number){
		cout << "All Dead";
	}
	else if (index1 == number){
		while (index2 < number-1){
			cout << *heros2[index2]<<endl;
			index2++;
		}
		cout << *heros2[number - 1];
	}
	else{
		while (index1 < number - 1){
			cout << *heros1[index1] << endl;
			index1++;
		}
		cout << *heros1[number - 1];
	}
	return 0;
}

Hero* initHero(int n){
	switch (n){
	case 1:
		return new Warrior();
	case 2:
		return new Magician();
	case 3:
		return new Leader();
	default:
		return nullptr;
	}
}

ostream& operator<<(ostream& out, Hero& hero){
	switch (hero.id)
	{
	case 1:
		out << "Warrior ";
		break;
	case 2:
		out << "Magician ";
		break;
	case 3:
		out << "Leader ";
		break;
	default:
		break;
	}
	out << hero.atk << " " << hero.hp;
	return out;
}