#include<iostream>

using namespace std;

class GPU{
private:
	long long price;
	long long hasRate;
public:
	void setPrice(long long p){ price = p; }
	long long getPrice(){ return price; }
	void setHasRate(long long r){ hasRate = r; }
	long long getHasRate(){ return hasRate; }
	virtual double Caculate() = 0;
};

class GPUType:GPU{
public:
	double consume;
	GPUType(){ setPrice(0); setHasRate(0); }
	GPUType(long long p, long long r){ setPrice(p); setHasRate(r); }
	long long getSPrice(){ return getPrice(); }
	virtual double Caculate();
	friend istream& operator>>(istream& in, GPUType& gpu);
};

istream& operator>>(istream& in, GPUType& gpu);
int main(){
	GPUType* GPU1 = new GPUType();
	GPU1->consume = 16.2;
	GPUType* GPU2 = new GPUType();
	GPU2->consume = 28.8;
	GPUType* GPU3 = new GPUType();
	GPU3->consume = 19.44;
	cin >> *GPU1 >> *GPU2 >> *GPU3;

	long long totalPrice = GPU1->getSPrice() + GPU2->getSPrice() + GPU3->getSPrice();
	double totalIncome = GPU1->Caculate() + GPU2->Caculate() + GPU3->Caculate();
	long long time;
	if (totalIncome <= 0){
		cout << -1;
		return 0;
	}
	else{
		time = ceil(totalPrice / totalIncome);
		cout << time;
		return 0;
	}
}

double GPUType::Caculate(){
	return getHasRate()*0.02 - consume;
}

istream& operator>>(istream& in, GPUType& gpu){
	long long price = 0, hasRate = 0;
	cin >> price >> hasRate;
	gpu.setPrice(price);
	gpu.setHasRate(hasRate);
	return in;
}