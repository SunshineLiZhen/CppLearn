#pragma once
using namespace std;


/*****************************************************************************/
/* 常成员函数、常对象、常对象指针、常对象引用
*/
/*****************************************************************************/
class Student
{
public:
	//重载构造函数
	Student();
	Student(string name,int age,int max);
	//拷贝构造函数
	Student(const Student &stu);
	//析构函数
	~Student();

	//接口
	string getName();
	int getMax() const;
	int getAge();
	void setName(string name);
	void study();
	void printInfo();
	void printInfo() const;
private:
	//私有成员变量
	string m_strName;
	int m_iAge;
	int m_iGender;
	int m_iMoney;

	//常成员变量
	const int m_iMax;//最大选修科目的数量
};


///家具类
class Furniture
{
public:
	Furniture(string name);
	~Furniture();
	void setName(string name);
	string getName();
private:
	string m_strName;
};

//房子类
class House
{
public:
	House(string code,string furName);
	~House();
	string getCode();
	void setCode(string code);
	void setFur(Furniture fur);
	Furniture & getFur();

private:
	//房屋门牌号
	string m_strCode;

	//家具
	Furniture m_furBed;
};

//坐标类
class Coordinate
{
public:
	int m_iX;
	int m_iY;
public:
	Coordinate();
	Coordinate(int x,int y);
	~Coordinate();
	void printInfo();
};


//静态成员学习
class Tank
{
public:

public:
	Tank(string code);
	~Tank();
	void attack();
	static int getCount();
private:
	string m_strCode;
	static int g_iCount;
};



class Circle
{
public:
	Circle(int x, int y, int r);
	~Circle();
public:
private:
	int m_iR;
	Coordinate *m_pCenter;
};