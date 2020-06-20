#include<stdio.h>

class Builder{
public:
	virtual void bulidHead()=0;
	virtual void bulidBody()=0;
	virtual void bulidHand()=0;
	virtual void bulidFoot()=0;
};
class ProduceA:public Builder{
public:
	void bulidHead(){
		printf("�������ӵ�ͷ\n");
	}
	void bulidBody(){
		printf("�������ӵ�����\n");
	}
	void bulidHand(){
		printf("�������ӵ�˫��\n");
	}
	void bulidFoot(){
		printf("�������ӵ�˫��\n");
	}
};
class ProduceB:public Builder{
public:
	void bulidHead(){
		printf("�������ӵ�ͷ\n");
	}
	void bulidBody(){
		printf("�������ӵ�����\n");
	}
	void bulidHand(){
		printf("�������ӵ�˫��\n");
	}
	void bulidFoot(){
		printf("�������ӵ�˫��\n");
	}
};
class Director{
public:
	Builder* product;
	Director(Builder* pro){
		product=pro;
	}
	void build(){
		this->product->bulidHead();
		this->product->bulidBody();
		this->product->bulidHand();
		this->product->bulidFoot();
	}
};
int main(){
	ProduceA* proA=new ProduceA();
	ProduceB* proB=new ProduceB();
	Director* dir=new Director(proA);
	dir->build();
	dir=new Director(proB);
	dir->build();
	return 0;
}