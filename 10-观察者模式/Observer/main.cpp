#include<stdio.h>
#include <list>
using namespace std;

class AbstractObserver{
public:
	virtual void update()=0;
	virtual ~AbstractObserver(){}
};
class AbstractInformer{
public:
	char* name;
	char* status;
	AbstractInformer(char* name,char* status){
		this->name=name;
		this->status=status;
	}
	list<AbstractObserver*> obsList;
	virtual void add(AbstractObserver* observer)=0;
	virtual void notify()=0;
	virtual ~AbstractInformer(){};
};
class Observer:public AbstractObserver{
private:
	char* name;
	AbstractInformer* informer;
public:
	Observer(char* name,AbstractInformer* informer){
		this->name=name;
		this->informer=informer;
	}
	void update(){
		printf("%s提示%s %s，该切换状态了\n",informer->name,name,informer->status);
	}

};
class Informer:public AbstractInformer{
public:
	Informer(char* name,char* status):AbstractInformer(name,status){}
	void add(AbstractObserver* observer){
		obsList.push_back(observer);
	}
	void notify(){
		for(list<AbstractObserver*>::iterator iter=obsList.begin();iter!=obsList.end();iter++){
			AbstractObserver*& observ=*iter;
			observ->update();
		}
	}
};
int main(){
	Informer* informer=new Informer("前台通知者","老板来了");
	Observer* observer1=new Observer("同事1",informer);
	Observer* observer2=new Observer("同事2",informer);
	Observer* observer3=new Observer("同事3",informer);
	Observer* observer4=new Observer("同事4",informer);
	informer->add(observer1);
	informer->add(observer2);
	informer->add(observer3);
	informer->add(observer4);
	informer->notify();
	return 0;
}