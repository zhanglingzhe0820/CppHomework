#include<iostream>

using namespace std;

class Operation{
private:
	double NumberA;
	double NumberB;
public:
	virtual double GetResult() = 0;
	double getA(){
		return NumberA;
	}
	void setA(double A){
		NumberA = A;
	}
	double getB(){
		return NumberB;
	}
	void setB(double B){
		NumberB = B;
	}
};

class OperationAdd :public Operation{
	virtual double GetResult(){
		return getA() + getB();
	}
};
class OperationSub :public Operation{
	virtual double GetResult(){
		return getA() - getB();
	}
};
class OperationMul :public Operation{
	virtual double GetResult(){
		return getA() * getB();
	}

};
class OperationDiv :public Operation{
	virtual double GetResult(){
		if (getB() == 0){
			return -1;
		}
		else{
			return getA() / getB();
		}
	}
};

static class OperationFactory{
public:
	static Operation* CreateOperation(char opt);
};
int main(){
	char opt;
	double operand1, operand2;
	cin >> opt;
	cin >> operand1 >> operand2;
	Operation* format = OperationFactory::CreateOperation(opt);
	format->setA(operand1);
	format->setB(operand2);
	cout << format->GetResult();
	return 0;
}

Operation* OperationFactory::CreateOperation(char opt){
	switch (opt){
	case '+':
		return new OperationAdd();
	case '-':
		return new OperationSub();
	case '*':
		return new OperationMul();
	case '/':
		return new OperationDiv();
	}
}