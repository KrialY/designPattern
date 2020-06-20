#include<stdio.h>

class Template{
public:
	void TestA(){
		printf("��һ����Ŀ����������������\n");
		printf("�𰸣�%s\n",this->AnswerA());
	}
	void TestB(){
		printf("�ڶ�����Ŀ����������������\n");
		printf("�𰸣�%s\n",this->AnswerB());
	}
	virtual char* AnswerA()=0;
	virtual char* AnswerB()=0;
};
class PapaerA:public Template{
public:
	char* AnswerA(){
		return "A";
	}
	char* AnswerB(){
		return "D";
	}
};
class PapaerB:public Template{
public:
	char* AnswerA(){
		return "C";
	}
	char* AnswerB(){
		return "B";
	}
};
int main(){
	Template* sutdentA=new PapaerA();
	Template* sutdentB=new PapaerB();
	sutdentA->TestA();
	sutdentA->TestB();
	sutdentB->TestA();
	sutdentB->TestB();
	return 0;
}