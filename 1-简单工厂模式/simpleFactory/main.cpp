#include<stdio.h>

class Calculator{
protected:
	int numA;
	int numB;
public:
	virtual int getResult()=0;
	Calculator(){
		numA=0;
		numB=0;
	}
	void setA(int a){
		numA=a;
	}
	int getA(){
		return numA;
	}
	void setB(int b){
		numB=b;
	}
	int getB(){
		return numB;
	}
};
class CalculatorAdd:public Calculator{
	int getResult(){
		return numA+numB;
	}
};
class CalculatorDecrease:public Calculator{
	int getResult(){
		return numA-numB;
	}
};
class CalculatorMultiplicate:public Calculator{
	int getResult(){
		return numA*numB;
	}
};

class SimpleFactory{
private:
	Calculator* cal;
public:
	static Calculator* createCalculator(char operate){
		switch(operate){
			case '+': 
				return new CalculatorAdd();
				break;
			case '-': 
				return new CalculatorDecrease();
				break;
			case '*': 
				return new CalculatorMultiplicate();
				break;
		}
		return NULL;
	}

};
int main(){
	char operate;
	scanf("%c",&operate);
	Calculator* cal=SimpleFactory::createCalculator(operate);
	cal->setA(20);
	cal->setB(5);
	printf("%d\n",cal->getResult());
	return 0;
}