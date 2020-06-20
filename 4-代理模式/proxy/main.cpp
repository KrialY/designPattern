#include<stdio.h>

class Givegift{
public:
	Givegift(){}
	virtual ~Givegift(){
	}
	virtual void giveApple()=0;
	virtual void giveFlowers()=0;
};
class People{
public:
	People(char* name){
		this->name=name;
	}
	char* name;
};
class Pursuer:Givegift{
public:
	People* mm;
	Pursuer(People* mm){
		this->mm=mm;
	}
	void giveApple(){
		printf("׷������ƻ����%s\n",mm->name);
	}
	void giveFlowers(){
		printf("׷�������ʻ���%s\n",mm->name);
	}
};
class Proxy:Givegift{
public:
	Pursuer* gg;
	Proxy(People* per){
		gg=new Pursuer(per);
	}
	void giveApple(){
		gg->giveApple();
	}
	void giveFlowers(){
		gg->giveFlowers();
	}
};
int main(){
	People* mm=new People("С��");
	Proxy* gg=new Proxy(mm);
	gg->giveApple();
	gg->giveFlowers();
	return 0;
}