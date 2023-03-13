#pragma once
#include <iostream>
#include "StateBase.hpp"

using namespace std;

class StandbyState :public StateBase
{
public:
	StandbyState()
	{

	}

	void Enter() override
	{

	}

	void Exit() override
	{

	}

	void Work() override
	{
		cout << "¿ÕÏÐÖÐ..." << endl;
	}


};