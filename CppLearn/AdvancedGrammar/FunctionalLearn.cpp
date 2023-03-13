#include "FunctionalLearn.h"
#include <string>
#include <iostream>
using namespace std;

typedef void(*pFunc)(const string &s);

// ����ָ��
void foo(const string &s)
{
	cout << s << endl;
}

FunctionalLearn::FunctionalLearn()
{
}

FunctionalLearn::~FunctionalLearn()
{
}

void FunctionalLearn::memoeryFunction(int i)
{
	cout << i << endl;
}

void FunctionalLearn::test()
{
	// ��ͨ����
	// 1.ʹ�ú���ָ����ú���
	void (*fun1)(const string&) = &foo;
	fun1("china");

	// 2.ʹ�ú���������ú���
	function<void(const string &)> fun2 = &foo;
	fun2("china");

	// ��Ա����
	// 3.ʹ�ú���������
	//���ʹ��bind��ĳ��ֵ����ô�ú������ڸò�����ʧ�ˡ������Ҫ��������Ҫʹ��ռλ��ռסλ�á�
	//����������У�fooԭ�����������������ǰ���ʽ������ĳ�������ַ������ֻʣ��һ����ַ��
	function<void(int)> fun3 = bind(&FunctionalLearn::memoeryFunction, this, placeholders::_1);
	fun3(2);

	//��ʹ��STL�㷨ʱ�����е��ȽϺ���������ǳ�Ա������ģ���ò�����Ա������ָ�룬��ʱ����Ҫ��bind


}

unsigned short zigZagDecode(unsigned short value)
{
	return (value >> 1) ^ (-(value & 1));
}

void zigZagDeltaDecode(unsigned short uBuffer[], unsigned short vBufer[], unsigned short heightBuffer[],int count)
{
	unsigned short u = 0;
	unsigned short v = 0;
	for (int i = 0; i < count; ++i)
	{
		u += zigZagDecode(uBuffer[i]);
		v += zigZagDecode(uBuffer[i]);
	}
}