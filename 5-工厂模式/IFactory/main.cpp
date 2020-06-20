#include<stdio.h>

class Operation{
protected:
	double numA,numB;
public:
	void setA(double num){
		numA=num;
	}
	void setB(double num){
		numB=num;
	}
	virtual double gerResult()=0;
};
class AddOperation:public Operation{
public:
	double gerResult(){
		return numA+numB;
	}
};
class SubOperation:public Operation{
public:
	double gerResult(){
		return numA-numB;
	}
};

class IFactory{
public:
	virtual Operation* createOperation()=0;
};
class AddIFactory:public IFactory{
public:
	Operation* createOperation(){
		return new AddOperation();
	}
};
class SubIFactory:public IFactory{
public:
	Operation* createOperation(){
		return new SubOperation();
	}
};

int main(){
	double numA=10,numB=2;
	IFactory* factory=new SubIFactory();
	Operation* operation1=factory->createOperation();
	Operation* operation2=factory->createOperation();
	operation1->setA(numA);
	operation1->setB(numB);
	operation2->setA(10);
	operation2->setB(30);
	printf("%f\n",operation1->gerResult());
	printf("%f\n",operation2->gerResult());
	return 0;
}