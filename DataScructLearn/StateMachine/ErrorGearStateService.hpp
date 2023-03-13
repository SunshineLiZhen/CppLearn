#pragma once
#include <iostream>
#include "StateBase.hpp"

using namespace std;

class ErrorStateService :public StateBase
{
public:
	ErrorStateService()
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
		cout << "³öÏÖ´íÎó..." << endl;
	}


};