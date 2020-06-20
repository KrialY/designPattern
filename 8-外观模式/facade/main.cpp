#include<stdio.h>

class SharesA{
public:
	void Buy(){
		printf("��ƱA����\n");
	}
	void Sell(){
		printf("��ƱA����\n");
	}
};
class SharesB{
public:
	void Buy(){
		printf("��ƱB����\n");
	}
	void Sell(){
		printf("��ƱB����\n");
	}
};
class Other{
public:
	void Buy(){
		printf("��ծ����\n");
	}
	void Sell(){
		printf("��ծ����\n");
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