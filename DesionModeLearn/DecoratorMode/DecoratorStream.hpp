#pragma once
#include <iostream>
#include "IStream.hpp"

using namespace std;

/// <summary>
/// װ����
/// </summary>
class DecoratorStream:public IStream
{
protected:
	shared_ptr<IStream> m_stream = nullptr;
public:
	DecoratorStream(shared_ptr<IStream> stream) :m_stream(stream)
	{

	}

};




