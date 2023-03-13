#include "stdafx.h"
#include "ClassSet.h"


Student::Student():m_iMax(10)
{

}

Student::Student(string name,int age,int max) :m_strName(name),m_iAge(age),m_iMax(30)
{
	//这行代码编译会报错，说明此处不是第一次赋值
	//其实第一次赋值发生在初始化列表处。因此说明，在初始化列表初始化成员变量效率高
	//m_iMax = 10; const变量不可以在赋值符号左边，因为他不可以修改
}
Student::Student(const Student & stu):m_strName(stu.m_strName),m_iAge(stu.m_iAge),m_iMax(stu.getMax())
{
	
}
;
Student::~Student() 
{

};

string Student::getName()
{
	return m_strName;
}

int Student::getAge()
{
	return m_iAge;
}

void Student::setName(string name)
{
	m_strName = name;
}

void Student::study()
{
	cout << "study" << endl;
}

void Student::printInfo()
{
	cout << "printInfo()" << endl;
}

void Student::printInfo() const
{
	cout << "printInfo() const" << endl;
}

int Student::getMax() const
{
	return m_iMax;
}

///////////////////////////////////////////////////////////////
House::House(string code, string furName):m_strCode(code),m_furBed(furName)
{
	cout << "House" << endl;
}

House::~House()
{
	cout << "~House" << endl;
}

string House::getCode()
{
	return string();
}

void House::setCode(string code)
{
	m_strCode = code;
}

void House::setFur(Furniture fur)
{
	m_furBed = fur;
}

///////////////////////////////////////////////////////////////
Furniture & House::getFur()
{
	return m_furBed;
}

Furniture::Furniture(string name):m_strName(name)
{
	cout << "Furniture" << endl;
}

Furniture::~Furniture()
{
	cout << "~Furniture" << endl;
}

void Furniture::setName(string name)
{
	m_strName = name;
}

string Furniture::getName()
{
	return m_strName;
}

Coordinate::Coordinate()
{
}

///////////////////////////////////////////////////////////////
Coordinate::Coordinate(int x, int y):m_iX(x),m_iY(y)
{
	cout << "Coordinate(int x, int y)" << endl;
}

Coordinate::~Coordinate()
{
	cout << "~Coordinate" << endl;
}

void Coordinate::printInfo()
{
	cout << "(" << m_iX << "," << m_iY << ")" << endl;
}

///////////////////////////////////////////////////////////////////////
int Tank::g_iCount = 0;//静态数据成员初始化
Tank::Tank(string code):m_strCode(code)
{
	++g_iCount; // 静态数据成员增加
}

Tank::~Tank()
{
	--g_iCount; // 静态数据成员减少
}

void Tank::attack()
{
	if (g_iCount > 3)
	{
		cout << "士气鼓舞" << endl;
	}
	else
	{
		cout << "士气低落" << endl;
	}
}

//静态函数
int Tank::getCount()
{
	return g_iCount;
}

////////////////////////////////////////////////////////////////////
Circle::Circle(int x, int y, int r)
{
	cout << "Circle(int x,int y,int z)" << endl;
	m_pCenter = new Coordinate(x, y);
	m_iR = r;
}

Circle::~Circle()
{
	cout << "~Circle()" << endl;
	delete m_pCenter;
	m_pCenter = NULL;
}
