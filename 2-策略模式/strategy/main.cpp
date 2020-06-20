#include<stdio.h>

class Strategy{
public:
	virtual double getRes(double mon)=0;
};
class ReturnStrategy:public Strategy{
public:
	double getRes(double mon){
		return 0;
	}
};
class DiscountStrategy:public Strategy{
public:
	double discount;
	DiscountStrategy(double discount){
		this->discount=discount;
	}
	double getRes(double mon){
		return discount*mon;
	}
};
class NormalStrategy:public Strategy{
public:
	double getRes(double mon){
		return mon;
	}
};
class ContextStrategy{
private:
	Strategy* cal;
public:
	ContextStrategy(int type){
		Strategy* concreatCal;
		switch(type){
			case 1:
				concreatCal=new ReturnStrategy();
				break;
			case 2:
				concreatCal=new DiscountStrategy(0.8);
				break;
			case 3:
				concreatCal=new NormalStrategy();
				break;
		}
		this->cal=concreatCal;
	}
	double getResult(double price){
		return cal->getRes(price);
	}
};
int main(){
	ContextStrategy* ContextS=new ContextStrategy(2);
	printf("%f\n",ContextS->getResult(100));
	return 0;
}