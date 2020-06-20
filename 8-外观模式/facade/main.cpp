#include<stdio.h>

class SharesA{
public:
	void Buy(){
		printf("股票A买入\n");
	}
	void Sell(){
		printf("股票A卖出\n");
	}
};
class SharesB{
public:
	void Buy(){
		printf("股票B买入\n");
	}
	void Sell(){
		printf("股票B卖出\n");
	}
};
class Other{
public:
	void Buy(){
		printf("国债买入\n");
	}
	void Sell(){
		printf("国债卖出\n");
	}
};
class Facade{
private:
	SharesA* sharesA;
	SharesB* sharesB;
	Other* other;
public:
	Facade(){
		sharesA=new SharesA();
		sharesB=new SharesB();
		other=new Other();
	}
	void BuyAll(){
		sharesA->Buy();
		sharesB->Buy();
		other->Buy();
	}
	void SellAll(){
		sharesA->Sell();
		sharesB->Sell();
		other->Sell();
	}
};
int main(){
	Facade* mon=new Facade();
	mon->BuyAll();
	mon->SellAll();
	return 0;
}