#pragma once
#include "stdafx.h"
using namespace std;

class AlgorithmLearn
{
public:
	AlgorithmLearn();
	~AlgorithmLearn();

	//ȡ���ַ����е���������
	void getAllDigitsInString(string src);
	void getAllDigitsInString2(string src);

	//��һ���˿����г��13�Ŵ�A��K��
	//��1�����������һ�ų�����ڵ�������, 
	//��2���ڶ����ó�������������,
	// �Դ����ƣ������Ҫ����A-K˳�����γ����.��ô�� ?
	void atoK();
	//쳲���������,��õ�n��쳲�������
	long long int FeiBo(int n);

	// f(1) = 1; f(n) = f(n-1) + 1/f(n-1)
	float Fun1(int n);
	float Fun2(int n);

	//ð��������ʾ
	void bubbleSortExample();
	
	//����������ʾ
	void insertSortExample(); 

	void selectSortExample();

	// ������������ʾ
	void binsearchAlg1Example();

	//�ַ���������ʾ
	void strOpExample();

	void str2HighExample();

	void diyStr2LowerExExample();

	void diyStrCmpExample();

	
private:
	/*
	* ð������
	* pArr:Դ�ַ���
	* pTar:�������ַ���
	*/
	bool bubbleSort(int *pArr, int arrLen, int* pTar);

	bool insertSort(int *pArr, int arrLen, int* pTar);

	bool selectSort(int *pArr, int arrLen, int* pTar);

	//�����㷨
	//�۰�����㷨
	int binsearchAlg1(int* digit,int tar,int len);

	int binsearchAlg2(int* digit, int tar, int len);
	//�ַ�������
	//�ַ�������
	bool diyStrCpy(char * source, char * target, int len);
	
	//�ַ�������
	bool diyStrCat1(char * str1, int len, char * str2);

	bool diyStrCat2(char* str1, char* str2, char* tar, int len);

	//�ַ�����дתСд
	//���str����ĸ�������ֻ���������ţ���Щ���Ż�ԭ�ⲻ������
	bool diyStr2Low(char* str, char* target, int len);

	/*
	 *������source��target�����㹻��source������ĸ��û�������ַ�
	 */
	bool diyStr2LowerEx(char* source, char* target);

	bool diyStr2UpperEx(char* source, char* target);
	
	/*
	 * �ַ����Ƚ�
	 * ��������Ƚ����ַ������ַ������ȫ������򷵻�true������false
	 * ���ִ�Сд
	 */
	bool diyStrCmp(char* str1, char* str2);

	/*
	 * �ַ����ָ�
	 * ����һ���ָ�������Ϊ��һ���ַ�������������û������
	 */
	bool diyStrSeparate(char* source, char separator, char target[][20]);
	/*
	 *��ӡ����
	 */
	void printArray(int* pArr, int arrLen);
};

/****************************************************************************************************/
/* �����㷨ѧϰ
*/
/****************************************************************************************************/
class SortAlgorithmLearn
{
public:
	void quickSortExample();
private:
	// ��������
	bool quickSort(int* pArr,int arrLen,int* pTar);
	void quickSortImpl(int* pArr,int arrLen,int low,int high);
};

/****************************************************************************************************/
/* �����㷨ѧϰ
*/
/****************************************************************************************************/
class SearchAlgorithmLearn
{

};

/****************************************************************************************************/
/* �ַ��������㷨ѧϰ
*/
/****************************************************************************************************/
class StringAlgorithmLearn
{

};
