#pragma once
#include <iostream>


using namespace std;

class House
{
public:
	void Init()
	{
		this->BuildPart1();

		for (int i = 0; i < 4; ++i)
		{
			this->BuildPart2();
		}

		bool flag = this->BuildPart3();
		if (flag)
		{
			this->BuildPart4();
		}

		this->BuildPart5();
	}
	~House() {}

protected:
	virtual void BuildPart1() = 0;
	virtual void BuildPart2() = 0;
	virtual bool BuildPart3() = 0;
	virtual void BuildPart4() = 0;
	virtual void BuildPart5() = 0;
};

class StoneHouse :public House
{
public:
	virtual void BuildPart1()
	{
	}

	virtual void BuildPart2()
	{
	}

	virtual bool BuildPart3()
	{
	}

	virtual void BuildPart4()
	{
	}

	virtual void BuildPart5()
	{
	}
};

class ApplyCasePTM
{
public:
	void Go()
	{
		shared_ptr<House> pHouse = make_shared< StoneHouse>();
		pHouse->Init();
	}
};