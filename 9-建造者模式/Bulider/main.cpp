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
		printf("画出瘦子的头\n");
	}
	void bulidBody(){
		printf("画出瘦子的身体\n");
	}
	void bulidHand(){
		printf("画出瘦子的双手\n");
	}
	void bulidFoot(){
		printf("画出瘦子的双脚\n");
	}
};
class ProduceB:public Builder{
public:
	void bulidHead(){
		printf("画出胖子的头\n");
	}
	void bulidBody(){
		printf("画出胖子的身体\n");
	}
	void bulidHand(){
		printf("画出胖子的双手\n");
	}
	void bulidFoot(){
		printf("画出胖子的双脚\n");
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