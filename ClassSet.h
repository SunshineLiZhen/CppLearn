#pragma once
using namespace std;


/*****************************************************************************/
/* ����Ա�����������󡢳�����ָ�롢����������
*/
/*****************************************************************************/
class Student
{
public:
	//���ع��캯��
	Student();
	Student(string name,int age,int max);
	//�������캯��
	Student(const Student &stu);
	//��������
	~Student();

	//�ӿ�
	string getName();
	int getMax() const;
	int getAge();
	void setName(string name);
	void study();
	void printInfo();
	void printInfo() const;
private:
	//˽�г�Ա����
	string m_strName;
	int m_iAge;
	int m_iGender;
	int m_iMoney;

	//����Ա����
	const int m_iMax;//���ѡ�޿�Ŀ������
};


///�Ҿ���
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

//������
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
	//�������ƺ�
	string m_strCode;

	//�Ҿ�
	Furniture m_furBed;
};

//������
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


//��̬��Աѧϰ
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