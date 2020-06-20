#include<stdio.h>

class Person{
public:
	Person(){
	
	}
	Person(char* name){
		this->name=name;
	}
	char* name;
	virtual void show(){
		printf("这是人\n");
	}
};
class Decorator:public Person{
protected:
	Person* man;
public:
	void setComponent(Person* man){
		this->man=man;
	}
	void show(){
		man->show();
	}
};
class T_shirt:public Decorator{
public:
	void show(){
		Decorator::show();
		printf("穿体恤\n");
	}
};
class Shoes:public Decorator{
public:
	void show(){
		Decorator::show();
		printf("穿鞋子\n");
	}
};
int main(){
	Person* man=new Person("krial");
	Decorator* Tshirt=new T_shirt();
	Decorator* shoes=new Shoes();
	shoes->setComponent(man);
	Tshirt->setComponent(shoes);
	Tshirt->show();
	return 0;
}