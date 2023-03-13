// CppLearn.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include "stdio.h"
#include <bitset>
#include "stdlib.h"
#include "IOLearn.h"
#include "DATaTypeLearn.h"
#include "FileIO.h"
#include "ClassSet.h"
#include "InheritLearn.h"
#include "PolymorphicLearn.h"
#include "AlgorithmLearn.h"
#include "DataStructLearn.h"
#include "STLLearn.h"
#include "DesignModeLearn.h"
#include "MemoryLearn.h"

using namespace std;


int main()
{

	//IOLearn io1;
	//io1.example();

	//DATaTypeLearn dtl;
	//dtl.yinYongExample();

	//FileIO fs;
	//fs.outStreamExaple();
	//fs.inputStreamExample();
	
	DATaTypeLearn datl;
	datl.typeConvertExample();



	House *p = new House("Gandam","BED1");

	cout << p->getFur().getName() << endl;
	delete p;
	p = NULL;


	Tank tank1("123");
	tank1.attack();
	Tank tank2("234");
	tank2.attack();
	Tank tank3("456");
	tank3.attack();
	Tank tank4("789");
	tank4.attack();
	
	cout << Tank::getCount() << endl;

	Circle *pc1 = new Circle(3, 4, 10);
	delete pc1;
	pc1 = NULL;

	/****************继承方式示例***********************/
	cout << "****************继承方式示例***********************" << endl;
	Electrician *pc = new Electrician("jim", 20, 1000);
	cout << "Electrician Age:" << pc->getAge() << endl //公有继承后，父类的公有函数变为子类的公有函数，仍可以访问
		<< "Electrician Name:" << pc->getName() << endl;//公有继承后，父类的公有函数变为子类的公有函数，仍可以访问
    pc->printInfo();
	
	delete pc;
	pc = NULL;

	Worker *pw = new Worker("tom", 10);
	cout << pw->getAge();

	/****************多继承示例***********************/
	cout << "****************多继承示例***********************" << endl;
	Migrantworker *pM = new Migrantworker("lina", 30, 2222);
	cout << "name|age|salary:"
		<< pM->getCode() << "|"
		<< pM->getAge() << "|"
		<< pM->getSalary() << endl;

	delete pM;
	pM = NULL;

	/****************菱形继承-虚继承示例***********************/
	cout << "****************菱形继承-虚继承示例***********************" << endl;
	DelicacyFoodCooker * pDfc = new	DelicacyFoodCooker("lucy", "666", 33, 3333);
	cout << pDfc->getName() << endl
		<< pDfc->getCode() << endl
		<< pDfc->getAge() << endl
		<< pDfc->getSalary() << endl;

	delete pDfc;
	pDfc = NULL;


	/****************多态-虚函数示例***********************/
	cout << "****************多态-虚函数示例***********************" << endl;
	Shape * c = new Circle1(3);
	Shape * r = new Rectangle(3, 4);
	Rectangle r2(3, 3);
	cout << c->calcArea() << endl;
	cout << r->calcArea() << endl;
	cout << sizeof(r2);
	delete c;
	delete r;
	c = NULL;
	r = NULL;

	/****************多态-纯虚函数抽象类示例***********************/
	cout << "****************多态-纯虚函数抽象类示例***********************" << endl;
	Clothing * pcloth = new Jacket();
	cout << pcloth->getPrice() << endl;

	delete pcloth;
	pcloth = NULL;

	/****************多态-接口类示例***********************/
	cout << "****************多态-接口类示例***********************" << endl;
	Flyble *obj1 = new Men();
	Flyble *obj2 = new Plane();
	
	doSomething(obj1);
	doSomething(obj2);

	int x = 9999;
	int countx = 0;
	while (x)
	{
		countx++;
		x = x&(x - 1);
	}

	cout << bitset<sizeof(int)*8>(9999) << endl;

	char* src = "hello,world";
	char* dest = NULL;
	int ln = strlen(src);
	dest = (char *)malloc(sizeof(char)*(ln + 1));
	memset(dest, 0, ln + 1);

	char* d = dest;
	char* ss = src + ln -1;

	while (ln-- != 0)
	{
		*d++ = *ss--;
	}
	
	cout << dest << endl;
	free(dest);
	dest = NULL;


	/****************算法示例***********************/
	cout << "****************算法示例***********************" << endl;
	AlgorithmLearn al;
	string str = "123,456g789";
	al.getAllDigitsInString2(str);

	cout << al.FeiBo(10) << endl;

	cout << al.Fun2(3) << endl;
	
	al.selectSortExample();

	al.strOpExample();
	al.str2HighExample();
	al.diyStr2LowerExExample();
	al.diyStrCmpExample();
	al.binsearchAlg1Example();

	al.atoK();

	cout << "ddddddddddddddddd" << endl;
	MyQueue * myQue = new MyQueue(4);
	myQue->EnQueue(5);
	myQue->EnQueue(44);
	myQue->EnQueue(48);
	myQue->EnQueue(55);
	cout << "队列超过容量插入结果：" << 
		myQue->EnQueue(99) << endl;
	myQue->QueueTraverse();
	myQue->ClearQueue();
	cout << "清空：";
	myQue->QueueTraverse();
	cout << "length:" << myQue->QueueLength();
	int de = 0;
	myQue->DeQueue(de);
	cout << endl << de << endl;

	myQue->DeQueue(de);
	cout << endl << de << endl << endl;

	myQue->QueueTraverse();

	myQue->EnQueue(88);
	myQue->QueueTraverse();

	delete myQue;
	myQue = NULL;

	MyStack *pStack = new MyStack(4);
	pStack->push(12);
	pStack->push(13);
	pStack->push(14);
	pStack->push(15);
	pStack->stackTraverse();

	int top = 0;
	pStack->getTopOfStack(top);
	cout << "top ele:" << top << endl;
	cout << "length:" << pStack->stackLength() << endl;

	pStack->pop(top);

	pStack->stackTraverse();
	delete pStack;
	pStack = NULL;

	const int a = 10;
	int* pp = (int*)&a;
	*pp = 20;
	cout << &a << endl;
	cout << pp << endl;
	cout << "a|p" << a << "," << *pp << endl;

	SortAlgorithmLearn *pSort = new	SortAlgorithmLearn();
	pSort->quickSortExample();

	STLLearn *pStl = new STLLearn();
	pStl->vectorExample();
	pStl->mapExample();
	pStl->functionalExample();
	delete pStl;
	pStl = NULL;

	DesignModeLearn * dml = new DesignModeLearn();
	dml->observerExample();
	delete dml;
	dml = NULL;

	cout << "****************运算符重载***********************" << endl;
	PolymorphicLearn *poly = new PolymorphicLearn();
	poly->opertorExample();
	delete poly;
	poly = NULL;

	MemoryLearn mem;
	//mem.vectorExample();

	MyLinkTree mlt(10);
	mlt.preOrderTraverse();
	mlt.inOrderTraverse();
	mlt.postOrderTraverse();

	cout << "treeDepth:" << mlt.treeDepth() << endl;
	system("pause");
    return 0;
}

