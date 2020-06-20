#include<stdio.h>

class Prototype{
public:
	virtual Prototype* Clone()=0;
};
class WorkExp:public Prototype{
public:
	WorkExp(char* time,char* comp){
		timeArea=time;
		company=comp;
	}
	void show(){
		printf("工作经历：%s %s\n",this->timeArea,this->company);
	}
	char* timeArea;
	char* company;
	Prototype* Clone(){
		WorkExp* workexp=new WorkExp(this->timeArea,this->company);
		return workexp;
	}
};
class Resume:public Prototype{
private:
	WorkExp* workexp;
	char* sex;
	char* name;
	Resume(WorkExp* wk){
		this->workexp=(WorkExp*)wk->Clone();
	}
public:
	Resume(char* name,char* sex){
		this->sex=sex;
		this->name=name;
	}
	void setWork(WorkExp* wk){
		this->workexp=wk;
	}
	void setSex(char* sex){
		this->sex=sex;
	}
	void setName(char* name){
		this->name=name;
	}
	void show(){
		printf("%s %s\n",this->name,this->sex);
		this->workexp->show();
	}
	Prototype* Clone(){
		Resume* res=new Resume(this->workexp);
		res->name=this->name;
		res->sex=this->sex;
		return res;
	}
};
int main(){
	Resume* res1=new Resume("小王","man");
	WorkExp* workexp1=new WorkExp("10年","sun");
	WorkExp* workexp2=new WorkExp("1年","google");
	res1->setWork(workexp1);
	Resume* res2=(Resume*)res1->Clone();
	res2->setName("小杰");
	res2->setSex("woman");
	res2->setWork(workexp2);
	res1->show();
	res2->show();
	return 0;
}