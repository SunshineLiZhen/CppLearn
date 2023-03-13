#pragma once
#include "stdafx.h"
using namespace std;

class AlgorithmLearn
{
public:
	AlgorithmLearn();
	~AlgorithmLearn();

	//取出字符串中的所有数字
	void getAllDigitsInString(string src);
	void getAllDigitsInString2(string src);

	//从一副扑克牌中抽出13张从A到K。
	//（1）把最下面的一张抽出来摆到桌子上, 
	//（2）第二张拿出来放在最上面,
	// 以此类推，如果想要按照A-K顺序依次抽出来.怎么摆 ?
	void atoK();
	//斐波那契数列,获得第n个斐波那契数
	long long int FeiBo(int n);

	// f(1) = 1; f(n) = f(n-1) + 1/f(n-1)
	float Fun1(int n);
	float Fun2(int n);

	//冒泡排序法演示
	void bubbleSortExample();
	
	//插入排序法演示
	void insertSortExample(); 

	void selectSortExample();

	// 二分搜索法演示
	void binsearchAlg1Example();

	//字符串操作演示
	void strOpExample();

	void str2HighExample();

	void diyStr2LowerExExample();

	void diyStrCmpExample();

	
private:
	/*
	* 冒泡排序法
	* pArr:源字符串
	* pTar:排序后的字符串
	*/
	bool bubbleSort(int *pArr, int arrLen, int* pTar);

	bool insertSort(int *pArr, int arrLen, int* pTar);

	bool selectSort(int *pArr, int arrLen, int* pTar);

	//查找算法
	//折半查找算法
	int binsearchAlg1(int* digit,int tar,int len);

	int binsearchAlg2(int* digit, int tar, int len);
	//字符串操作
	//字符串拷贝
	bool diyStrCpy(char * source, char * target, int len);
	
	//字符串链接
	bool diyStrCat1(char * str1, int len, char * str2);

	bool diyStrCat2(char* str1, char* str2, char* tar, int len);

	//字符串大写转小写
	//如果str非子母，是数字或者特殊符号，这些符号会原封不动保留
	bool diyStr2Low(char* str, char* target, int len);

	/*
	 *条件：source和target长度足够。source都是子母，没有其他字符
	 */
	bool diyStr2LowerEx(char* source, char* target);

	bool diyStr2UpperEx(char* source, char* target);
	
	/*
	 * 字符串比较
	 * 规则：逐个比较两字符串的字符，如果全部相等则返回true，否则false
	 * 区分大小写
	 */
	bool diyStrCmp(char* str1, char* str2);

	/*
	 * 字符串分割
	 * 遇到一个分隔符就认为有一个字符串，不管他有没有内容
	 */
	bool diyStrSeparate(char* source, char separator, char target[][20]);
	/*
	 *打印数组
	 */
	void printArray(int* pArr, int arrLen);
};

/****************************************************************************************************/
/* 排序算法学习
*/
/****************************************************************************************************/
class SortAlgorithmLearn
{
public:
	void quickSortExample();
private:
	// 快速排序法
	bool quickSort(int* pArr,int arrLen,int* pTar);
	void quickSortImpl(int* pArr,int arrLen,int low,int high);
};

/****************************************************************************************************/
/* 搜索算法学习
*/
/****************************************************************************************************/
class SearchAlgorithmLearn
{

};

/****************************************************************************************************/
/* 字符串操作算法学习
*/
/****************************************************************************************************/
class StringAlgorithmLearn
{

};
